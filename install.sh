#!/bin/bash

git clone https://github.com/goodtft/LCD-show.git
sudo cp ./LCD-show/usr/tft9341-overlay.dtb /boot/overlays/tft9341.dtbo

sudo rm /boot/firmware/config.txt
sudo cp /home/username/PeanutGB/config_new.txt /boot/firmware/config.txt
sudo rm /boot/firmware/cmdline.txt
sudo cp /home/username/PeanutGB/cmdline_new.txt /boot/firmware/cmdline.txt

sudo echo "#!/bin/sh" > /etc/rc.local
sudo echo "sudo modprobe snd-pcm-oss" >> /etc/rc.local
sudo echo "exit 0" >> /etc/rc.local

sudo chmod +rwx /etc/rc.local
sudo chown root /etc/rc.local

gcc -o /home/username/PeanutGB/buttons.o /home/username/PeanutGB/buttons.c
gcc -O3 -o /home/username/PeanutGB/PeanutGB.o /home/username/PeanutGB/main.c

sudo chmod +x /home/username/PeanutGB/buttons.o
sudo chmod +x /home/username/PeanutGB/PeanutGB.o

sudo chown username /home/username/PeanutGB/buttons.o
sudo chown username /home/username/PeanutGB/PeanutGB.o

echo "Installed PeanutGB! Reboot to finalize."
echo "To manually play: sh ~/PeanutGB/run.sh"
echo "To auto play: echo 'sh ~/PeanutGB/run.sh' >> ~/.bashrc"





