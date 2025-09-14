#!/bin/bash

gcc -o /home/username/PeanutGB/buttons.o /home/username/PeanutGB/buttons.c
gcc -o /home/username/PeanutGB/menu.o /home/username/PeanutGB/menu.c
gcc -O3 -o /home/username/PeanutGB/PeanutGB.o /home/username/PeanutGB/main.c

sudo chmod +x /home/username/PeanutGB/buttons.o
sudo chmod +x /home/username/PeanutGB/menu.o
sudo chmod +x /home/username/PeanutGB/PeanutGB.o

sudo chown username /home/username/PeanutGB/buttons.o
sudo chown username /home/username/PeanutGB/menu.o
sudo chown username /home/username/PeanutGB/PeanutGB.o

echo "Installed PeanutGB!"
echo "To reboot: sudo reboot"
echo "Then, to manually play: sh ~/PeanutGB/run.sh"
echo "Or, to auto play: echo 'sh ~/PeanutGB/run.sh' >> ~/.bashrc"





