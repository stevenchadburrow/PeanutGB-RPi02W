#!/bin/bash

amixer set Master 50%

/home/username/PeanutGB/buttons.o &

stty -echo

sudo chmod -w /dev/stdin

echo "Changing /dev/stdin to Read-Only"

/home/username/PeanutGB/menu.o

sudo chmod +w /dev/stdin

echo "Changing /dev/stdin to Read-Write"

stty echo




