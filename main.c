#include <stdio.h>
#include <sys/ioctl.h>
#include <linux/kd.h>

#include "peanut_gb.c"

int main(const int argc, const char **argv)
{
	if (argc < 3)
	{
		printf("Needs Arguments:\n");
		printf("<filename> 0 for Television Mode\n");
		printf("<filename> 1 for Handheld Mode\n");

		return 0;
	}

	scanline_handheld = atoi(argv[2]);

	FILE *input = NULL;

	input = fopen(argv[1], "rt");
	
	if (!input)
	{
		printf("Error Opening File\n");
		return 0;
	}

	int bytes = 1;
	unsigned char buffer = 0;
	unsigned long location = 0;

	while (bytes > 0)
	{
		bytes = fscanf(input, "%c", &buffer);

		if (bytes > 0)
		{
			cart_rom[location] = buffer;

			location++;
		}
	}

	fclose(input);

	char tty_name[16];

	system("tty > /home/username/PeanutGB/temp.val");
	system("echo \"                \" >> /home/username/PeanutGB/temp.val");

	int tty_file = open("/home/username/PeanutGB/temp.val", O_RDWR);
	
	read(tty_file, &tty_name, 16);

	close(tty_file);

	system("rm /home/username/PeanutGB/temp.val");

	for (int i=0; i<16; i++)
	{
		if (tty_name[i] <= ' ') tty_name[i] = 0;
	}

	tty_file = open(tty_name, O_RDWR);

	ioctl(tty_file, KDSETMODE, KD_GRAPHICS); // turn off tty

	// this needs 'sudo' perhaps do it in rc.local or something?
	//system("modprobe snd-pcm-oss"); // opens up /dev/dsp
	// this sets the volume, change accordingly
	//system("amixer set Master 25%");

	//PeanutGB(0, "/home/username/PeanutGB/buttons.val"); // DMG
	PeanutGB(1, "/home/username/PeanutGB/buttons.val"); // GBC

	ioctl(tty_file, KDSETMODE, KD_TEXT); // turn on tty

	close(tty_file);

	return 1;
}
