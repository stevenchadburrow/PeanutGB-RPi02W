#!/bin/bash

sudo echo "#!/bin/sh" > /etc/rc.local
sudo echo "sudo sh /home/username/PeanutGB/startup.sh" >> /etc/rc.local
sudo echo "exit 0" >> /etc/rc.local

sudo chmod +rwx /etc/rc.local
sudo chown root /etc/rc.local

gcc -o /home/username/PeanutGB/switch.o /home/username/PeanutGB/switch.c
gcc -o /home/username/PeanutGB/buttons.o /home/username/PeanutGB/buttons.c
gcc -o /home/username/PeanutGB/menu.o /home/username/PeanutGB/menu.c
gcc -O3 -o /home/username/PeanutGB/PeanutGB.o /home/username/PeanutGB/main.c

echo "Installed PeanutGB!"
echo "If this is a fresh install, type:"
echo "echo 'sh ~/PeanutGB/run.sh' >> ~/.bashrc"
echo "Otherwise on login, type:"
echo "sh ~/PeanutGB/run.sh"
echo "To restart, type:"
echo "sudo reboot"



