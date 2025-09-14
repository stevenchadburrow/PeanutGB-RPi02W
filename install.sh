#!/bin/bash

gcc -o /home/username/PeanutGB/keyboard.o /home/username/PeanutGB/keyboard.c
gcc -o /home/username/PeanutGB/joystick.o /home/username/PeanutGB/joystick.c
gcc -o /home/username/PeanutGB/menu.o /home/username/PeanutGB/menu.c
gcc -O3 -o /home/username/PeanutGB/PeanutGB.o /home/username/PeanutGB/main.c

echo "Installed PeanutGB!"
echo "To reboot: sudo reboot"
echo "Then, to manually play: sh ~/PeanutGB/run.sh"
echo "Or, to auto play: echo 'sh ~/PeanutGB/run.sh' >> ~/.bashrc"





