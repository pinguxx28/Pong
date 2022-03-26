#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>

// === Own libraries ===
#include "pix.hpp"
#include "draw.hpp"
#include "font.hpp"

// === DISPLAY ===
#define dispW (8 * 32)
#define dispH (8 * 30)

// 0, Start menu
// 1, Game
// 2, Win
// 3, Loose
u_char screen = 0;
// 0, Main
// 1, How-to
u_char menuScreen = 0;
char menuScreenPtr = 0;
bool pauseGame = 0;

void handleScreen(pix::Pix *engine);

// === Vectors ===
typedef struct vec2D { float x, y; } vec2D;

// === PADDLES ===
typedef struct paddle_t
{
	float x, y;
	float w, h;
	float yVel;
	u_char score;
	bool shooter;
} paddle_t;

#define paddleSpeed 0.4f // How fast the the paddles velocity increases / decreases

// Create paddles
paddle_t paddle1;
paddle_t paddle2;

// Functions for paddles
void initPaddles();					  // Initialize the paddles
void updatePaddles(pix::Pix *engine); // Move the paddles and serve the ball
void drawPaddles(pix::Pix *engine);   // Draw the paddles and the scores

// === BALL ===
typedef struct ball_t
{
	float x, y;
	float r;
	float xVel, yVel;
	float speed;
	bool moving;
	vec2D shadow[10];
} ball_t;

#define maxBallSpeed 12.0f // The fastest speed the ball will be able to travel
#define ballShadowsLen 10  // How many ball shadows there are

// Create the ball
ball_t ball;

// Functions for the ball
void initBall();									  // Inititalize the ball
void scorePoint(float xVel, u_char *scoreP, bool *shooter); // Score for one of the players
void updateBall();									  // Update the ball, collision with the ball and others
void drawBall();									  // Draw the ball

// === NET ===
void drawNet(); // Draw the net

// === COLOR ===
ALLEGRO_COLOR RGB(u_char r, u_char g, u_char b);
ALLEGRO_COLOR RGBF(float r, float g, float b);

ALLEGRO_COLOR white, darkgray, lightgray, black;

// === WIN / LOOSE STATE ===
void checkWin();

// === SOUNDS ===
// Paddle, ball hits
ALLEGRO_SAMPLE *hit1, *hit2, *hit3;
ALLEGRO_SAMPLE* hits[3];
// Menu sounds
ALLEGRO_SAMPLE *goBack, *goForwards;
// Score
ALLEGRO_SAMPLE *score;
// Win
ALLEGRO_SAMPLE *win;
// Music
ALLEGRO_AUDIO_STREAM *music;

int main()
{
	std::printf("Loading...\n");
	// === LOADING ===

	std::srand(time(0)); // set random seed

	// Define colors
	white     = RGBF(1,1,1);
	darkgray  = RGBF(0.3f,0.3f,0.3f);
	lightgray = RGBF(0.5f,0.5f,0.5f);
	black     = RGBF(0,0,0);

	pix::Pix engine(dispW, dispH, 3, black); // Initialize the engine
	engine.keyboardInit();                   // Initialize the keyboard
	initPaddles();						     // Initialize the paddles
	initBall(); 							 // Initialize the ball				

	// Define hit sounds
	hit1 = al_load_sample("sound/hit1.wav"); mustInit(hit1, "hit1 sound");
	hit2 = al_load_sample("sound/hit2.wav"); mustInit(hit2, "hit2 sound");
	hit3 = al_load_sample("sound/hit3.wav"); mustInit(hit3, "hit3 sound");
	hits[0] = hit1; hits[1] = hit2; hits[2] = hit3;
	// Define menu sounds
	goBack     = al_load_sample("sound/goBack.wav");     mustInit(goBack,     "go back menu sound"    );
	goForwards = al_load_sample("sound/goForwards.wav"); mustInit(goForwards, "go forwards menu sound");
	// Define score
	score = al_load_sample("sound/score.wav"); mustInit(score, "score");
	// Define win
	win = al_load_sample("sound/win.wav"); mustInit(win, "win");
	// Define music
	music = al_load_audio_stream("sound/music.wav", 2, 2048); mustInit(music, "music");
	al_set_audio_stream_playmode(music, ALLEGRO_PLAYMODE_LOOP);
	al_set_audio_stream_gain(music, 0.1f);
	al_set_audio_stream_playing(music, false);
	al_attach_audio_stream_to_mixer(music, al_get_default_mixer());


	// ======
	std::printf("Done!\n");

	// Play score


	// === Game Loop ===
	while (engine.running())
	{
		engine.waitForEvent();
		switch (engine.getEvent())
		{
		case pix::KEY_CHAR:
			handleScreen(&engine);
			break;
		case pix::NEW_FRAME:
			if (screen == 1 && !pauseGame)
			{
				updatePaddles(&engine); // Update the paddles, move and serve
				updateBall();			// Check collisions and move ball
				checkWin();				// Check win or loose
			}
			engine.updateFrame(); 
			break;
		case pix::DISP_CLOSE:	
			engine.closeDisp(); 
			break;
		};

		if (engine.dispClosed()) break;				 
		engine.keyboardUpdate(); 

		if (engine.nextFrame())
		{
			engine.preDraw(); 

			// === DRAW ===
			if (screen == 0)
			{
				if (menuScreen == 0)
				{
					draw::string((char *) "Pong"  , dispW * 0.1f, dispH * 0.2f, 24, 24, white);

					draw::string((char *) "Play"  , dispW * 0.1f, dispH * 0.6f,      12, 12, white);
					draw::string((char *) "How-to", dispW * 0.1f, dispH * 0.6f + 16, 12, 12, white);

					// Draw pointer
					draw::texture64(font::font[font::index('>')], dispW * 0.1f - 16, dispH * 0.6f + menuScreenPtr * 16 + 2, 12, 8, white);
				}
				else if (menuScreen == 1)
				{
					draw::string((char *) "How-to", dispW * 0.1f, dispH * 0.2f, 20, 20, white);

					// Paddle1 (left)
					draw::string((char *) "Paddle1 (left)"           , dispW * 0.1f, dispH * 0.4f,      12, 12, white);
					draw::string((char *) "Move up & down with W & S", dispW * 0.1f, dispH * 0.4f + 14, 8 , 8 , white);
					draw::string((char *) "Serve the ball with D"    , dispW * 0.1f, dispH * 0.4f + 24, 8 , 8 , white);

					// Paddle2 (right)
					draw::string((char *) "Paddle2 (Right)"          , dispW * 0.1f, dispH * 0.6f,      12, 12, white);
					draw::string((char *) "Move up & down with I & K", dispW * 0.1f, dispH * 0.6f + 14, 8 , 8 , white);
					draw::string((char *) "Serve the ball with J"    , dispW * 0.1f, dispH * 0.6f + 24, 8 , 8 , white);

				}
			}
			else if (screen == 1)
			{
				drawNet(); 			  // Draw the middle net
				drawBall();			  // Draw the ball
				drawPaddles(&engine); // Draw the paddles and scores

				if (pauseGame) draw::string((char *) "Paused", dispW / 2 - 3 * 16, dispH / 2 - 8, 16, 16, darkgray);
			}
			else if (screen == 2)
				draw::string((char *) "Player1 wins!", dispW / 2 - 6 * 8, dispH / 2 - 4, 8, 8, white);
			else if (screen == 3)
				draw::string((char *) "Player2 wins!", dispW / 2 - 6 * 8, dispH / 2 - 4, 8, 8, white);
			// ======

			engine.postDraw(); 
		}
	}

	// Destroy music
	al_destroy_sample(hit1); al_destroy_sample(hit2); al_destroy_sample(hit3);
	al_destroy_sample(goBack); al_destroy_sample(goForwards);
	al_destroy_sample(score);
	al_destroy_audio_stream(music);

	return 0;
};

void handleScreen(pix::Pix *engine) // Handle actions on menus, screens
{
	if (screen == 0 && menuScreen == 0) // If on main menu
	{
		// Move menu pointer
		if (engine->eEvent.keyboard.keycode == ALLEGRO_KEY_UP  ) menuScreenPtr--;
		if (engine->eEvent.keyboard.keycode == ALLEGRO_KEY_DOWN) menuScreenPtr++;

		if (menuScreenPtr < 0) menuScreenPtr = 1;
		if (menuScreenPtr > 1) menuScreenPtr = 0;
	}

	if (engine->eEvent.keyboard.keycode == ALLEGRO_KEY_ENTER) // Enter pressed
	{
		if (screen == 1) {  al_set_audio_stream_playing(music, pauseGame); pauseGame = std::abs(pauseGame - 1); } // Pause the game in-game

		// Go to game or to how-to menu
		if (menuScreenPtr == 0 && menuScreen == 0 && screen == 0) { screen = 1;     al_play_sample(goForwards, 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, NULL); initPaddles(); initBall(); al_set_audio_stream_playing(music, true);	al_seek_audio_stream_secs(music, 0); }
		if (menuScreenPtr == 1 && menuScreen == 0 && screen == 0) { menuScreen = 1; al_play_sample(goForwards, 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, NULL); }

		// Go back to main menu from win / loose
		if (screen == 2 || screen == 3) { screen = 0; }
	}

	if (engine->eEvent.keyboard.keycode == ALLEGRO_KEY_BACKSPACE) // Backspace pressed
	{
		// Go back from how-to page
		if (menuScreen == 1 && screen == 0) { menuScreen = 0; al_play_sample(goBack, 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, NULL); }
		// Go back from in-game
		if (screen == 1)        			{ screen = 0; 	  al_play_sample(goBack, 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, NULL); al_set_audio_stream_playing(music, false); }
	}
}

void initPaddles() // Initialize the paddles
{
	// Paddle1
	paddle1 = (paddle_t) {
		.x = 8,     .y = dispH / 2 - 16,
		.w = 8,     .h = 32,
		.yVel = 0,
		.score = 0, .shooter = 1 };

	// Paddle2
	paddle2 = (paddle_t) {
		.x = dispW - 16, .y = dispH / 2 - 16,
		.w = 8, 		 .h = 32,
		.yVel = 0,
		.score = 0, 	 .shooter = 0 };
}

void updatePaddles(pix::Pix *engine) // Update the paddles, move and serve the ball
{
	// Paddle 1, left
	if (engine->keyPressed(ALLEGRO_KEY_W) && paddle1.y - paddleSpeed 			 > 0    ) paddle1.yVel -= paddleSpeed; // Decrease y velocity
	if (engine->keyPressed(ALLEGRO_KEY_S) && paddle1.y + paddle1.h + paddleSpeed < dispH) paddle1.yVel += paddleSpeed; // Increase y velocity

	paddle1.yVel *= 0.9;	   // Lerp
	paddle1.y += paddle1.yVel; // Move

	// Keep inside boundaries
	if (paddle1.y < 0) paddle1.y = 0;
	if (paddle1.y + paddle1.h > dispH) paddle1.y = dispH - paddle1.h;

	if (engine->keyPressed(ALLEGRO_KEY_D) && paddle1.shooter) { ball.moving = true; paddle1.shooter = false; al_play_sample(hits[rand() % 3], 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, NULL); } // Serve

	// Paddle 2, right
	if (engine->keyPressed(ALLEGRO_KEY_I) && paddle2.y - paddleSpeed 			> 0	   ) paddle2.yVel -= paddleSpeed; // Decrease y velocity
	if (engine->keyPressed(ALLEGRO_KEY_K) && paddle2.y + paddle2.h + paddleSpeed < dispH) paddle2.yVel += paddleSpeed; // Increase y velocity

	paddle2.yVel *= 0.9;	   // Lerp
	paddle2.y += paddle2.yVel; // Move

	// Keep inside boundaries
	if (paddle2.y < 0) paddle2.y = 0;
	if (paddle2.y + paddle2.h > dispH) paddle2.y = dispH - paddle2.h;

	if (engine->keyPressed(ALLEGRO_KEY_J) && paddle2.shooter) { ball.moving = true; paddle2.shooter = false; al_play_sample(hits[rand() % 3], 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, NULL); } // Serve
}

void drawPaddles(pix::Pix *engine) // Draw the paddles and the scores
{
	// === Draw paddles ===
	draw::rectangle(paddle1.x, paddle1.y, paddle1.x + paddle1.w, paddle1.y + paddle1.h, white); // Paddle1 (left)
	draw::rectangle(paddle2.x, paddle2.y, paddle2.x + paddle2.w, paddle2.y + paddle2.h, white); // Paddle2 (right)

	// === Draw score ===
	// Paddle1 (left)
	ALLEGRO_COLOR paddle1Color = white; // Set default color
	if (int32_t(engine->lFrames / 15) % 2 && paddle1.shooter) paddle1Color = lightgray; // Add flashing animation

	draw::texture64(font::font[font::index(paddle1.score + 48)], dispW * 0.25 - 8, 32, 8, 8, paddle1Color); // Draw score

	// Paddle2 (right)
	ALLEGRO_COLOR paddle2Color = white; // Set default color
	if (int32_t(engine->lFrames / 15) % 2 && paddle2.shooter) paddle2Color = lightgray; // Add flashing animation

	draw::texture64(font::font[font::index(paddle2.score + 48)], dispW * 0.75 - 8, 32, 8, 8, paddle2Color); // Draw score
}

void initBall() // Initialize the ball
{
	ball.x = dispW / 2; ball.y = dispH / 2; ball.r = 3;
	ball.xVel = 4;  ball.yVel = 0;
	ball.speed = 4; ball.moving = 0;

	// Shadows
	for (register u_char i = 0; i < ballShadowsLen; i++)
	{
		ball.shadow[i].x = ball.x;
		ball.shadow[i].y = ball.y;
	}
}

void scorePoint(float xVel, u_char *scoreP, bool *shooter) // Score for one side
{
	ball.x = dispW / 2; ball.y = dispH / 2; ball.r = 3;
	ball.xVel = xVel; ball.yVel = 0;
	ball.speed = 4; ball.moving = 0;

	paddle1.y = dispH / 2 - 16; paddle1.yVel = 0; // Reset Paddle1
	paddle2.y = dispH / 2 - 16; paddle2.yVel = 0; // Reset Paddle2

	++*scoreP; 	  // Increase the winner paddles score
	*shooter = 1; // Set the designated shooter

	al_play_sample(score, 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, NULL);
}

void updateBall() // Update the ball, check collision, move ball
{
	// === Paddles ===
	// Paddle1 collision
	if (ball.x - ball.r - 1 < paddle1.x + paddle1.w && ball.x + ball.r > paddle1.x && ball.y - ball.r - 1 < paddle1.y + paddle1.h && ball.y + ball.r > paddle1.y)
	{
		float angle = atan2f(ball.y - (paddle1.y + paddle1.h / 2), ball.x - 0); // Find angle	
		if (ball.speed < maxBallSpeed) ball.speed += 0.1f; // Increase ball speed

		// Apply angle
		ball.xVel = cosf(angle) * ball.speed;
		ball.yVel = sinf(angle) * ball.speed;

		// Play sound
		al_play_sample(hits[rand() % 3], 1.0f, -0.2f, 1.0f, ALLEGRO_PLAYMODE_ONCE, NULL);
	}
	// Paddle2 collision
	if (ball.x - ball.r - 1 < paddle2.x + paddle2.w && ball.x + ball.r > paddle2.x && ball.y - ball.r - 1 < paddle2.y + paddle2.h && ball.y + ball.r > paddle2.y)
	{
		float angle = atan2f(ball.y - (paddle2.y + paddle2.h / 2), ball.x - dispW); // Find angle
		if (ball.speed < maxBallSpeed) ball.speed += 0.1f; // Increase ball speed

		// Apply angle
		ball.xVel = cosf(angle) * ball.speed;
		ball.yVel = sinf(angle) * ball.speed;

		// Play sound
		al_play_sample(hits[rand() % 3], 1.0f, 0.2f, 1.0f, ALLEGRO_PLAYMODE_ONCE, NULL);
	}

	// === Top and bottom edges ===
	if (ball.y - ball.r - 1 < 0 || ball.y + ball.r > dispH) ball.yVel *= -1;

	// === Left and right edges ===
	if (ball.x - ball.r - 1 < 0) scorePoint( 3.0f, &paddle2.score, &paddle1.shooter); // Left edge
	if (ball.x + ball.r > dispW) scorePoint(-3.0f, &paddle1.score, &paddle2.shooter); // Right edge

	// === Move the ball ===
	if (ball.moving) ball.x += ball.xVel; ball.y += ball.yVel;

	// === Set shadows ===
	for (register u_char i = 0; i < ballShadowsLen; i++)
	{
		if (i+1 < ballShadowsLen)
		{
			ball.shadow[i].x = ball.shadow[i + 1].x;
			ball.shadow[i].y = ball.shadow[i + 1].y;
			continue;
		}

		ball.shadow[i].x = ball.x;
		ball.shadow[i].y = ball.y;
	}
}

void drawBall() // Draw the ball
{
	draw::ellipse(ball.x, ball.y, ball.r, white); // Ball

	// Draw shadows
	for (register u_char i = 0; i < ballShadowsLen; i++)
		draw::ellipse(ball.shadow[i].x, ball.shadow[i].y, ball.r, RGBF(i/10.0f, i/10.0f, i/10.0f));
}

void drawNet() // Draw net
{
	for (register u_char y = 0; y < dispH; y += 10) // Loop through every 10 pixels
		draw::rectangle(dispW / 2 - 2, y, dispW / 2 + 2, y + 7, darkgray); // Draw that part of net
}

ALLEGRO_COLOR RGB(u_char r, u_char g, u_char b) { return al_map_rgb(r, g, b); }
ALLEGRO_COLOR RGBF(float r, float g, float b) { return al_map_rgb_f(r, g, b); }

void checkWin()
{
	if (paddle1.score >= 5) { screen = 2; al_play_sample(win, 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, NULL); al_set_audio_stream_playing(music, false); }
	if (paddle2.score >= 5) { screen = 3; al_play_sample(win, 1.0f, 0.0f, 1.0f, ALLEGRO_PLAYMODE_ONCE, NULL); al_set_audio_stream_playing(music, false); }
}