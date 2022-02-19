#!/bin/bash

rm Game # remove any previous instance of the game
# build and execute
g++ src/*.cpp src/hdr/*.cpp -I hdr/ -o Game $(pkg-config allegro-5 allegro_font-5 allegro_primitives-5 allegro_color-5 allegro_audio-5 allegro_acodec-5 allegro_image-5 --libs --cflags)
./Game