#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int file = open("/sys/class/graphics/fb0/virtual_size", O_RDONLY);
	
	char buffer[16];

	read(file, &buffer, 3);

	close(file);

	if (buffer[0] == '3' && buffer[1] == '2' && buffer[2] == '0')
	{
		// no HDMI detected
		
		file = open("/boot/firmware/config.txt", O_RDONLY);
		read(file, &buffer, 16); // # config_lcd.txt
		close(file);

		if (buffer[9] == 'l' && buffer[10] == 'c' && buffer[11] == 'd')
		{
			// already in LCD mode

			system("modprobe snd-pcm-oss"); // turn on audio

			//system("/home/username/PeanutGB/buttons.o &"); // run keyboard and joystick
			//system("/home/username/PeanutGB/menu.o"); // run game selection menu

			return 1;
		}
		else
		{
			// not in LCD mode

			system("rm /boot/firmware/config.txt");
			system("cp /home/username/PeanutGB/config_lcd.txt /boot/firmware/config.txt");
			system("rm /boot/firmware/cmdline.txt");
			system("cp /home/username/PeanutGB/cmdline_lcd.txt /boot/firmware/cmdline.txt");
			system("reboot");
		}
	}
	else
	{
		// HDMI detected
		
		file = open("/boot/firmware/config.txt", O_RDONLY);
		read(file, &buffer, 16); // # config_hdmi.txt
		close(file);

		if (buffer[9] == 'h' && buffer[10] == 'd' && buffer[11] == 'm' && buffer[12] == 'i')
		{
			// already in HDMI mode

			system("modprobe snd-pcm-oss"); // turn on audio

			//system("/home/username/PeanutGB/buttons.o &"); // run keyboard and joystick
			//system("/home/username/PeanutGB/menu.o"); // run game selection menu

			return 1;
		}
		else
		{
			// not in HDMI mode

			system("rm /boot/firmware/config.txt");
			system("cp /home/username/PeanutGB/config_hdmi.txt /boot/firmware/config.txt");
			system("rm /boot/firmware/cmdline.txt");
			system("cp /home/username/PeanutGB/cmdline_hdmi.txt /boot/firmware/cmdline.txt");
			system("reboot");
		}
	}

	return 0;
}
