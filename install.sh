#!/bin/bash

sudo echo "#!/bin/sh" > /etc/rc.local
sudo echo "sudo sh /home/username/PeanutGB/startup.sh" >> /etc/rc.local
sudo echo "exit 0" >> /etc/rc.local

sudo chmod +rwx /etc/rc.local
sudo chown root /etc/rc.local

gcc -o switch.o switch.c
gcc -o buttons.o buttons.c
gcc -o menu.o menu.c
gcc -O3 -o PeanutGB.o main.c

echo "Installed PeanutGB!"
echo "If this is a fresh install, type:"
echo "echo 'sh ~/PeanutGB/run.sh' >> ~/.bashrc"
echo "Otherwise on login, type:"
echo "sh ~/PeanutGB/run.sh"
echo "To restart, type:"
echo "sudo reboot"



