#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main()
{
	int select = 0;
	int total = 0;
	char list[1000][64];

	system("ls /home/username/PeanutGB/ROMS > /home/username/PeanutGB/list.val");
	
	FILE *input = NULL;

	input = fopen("/home/username/PeanutGB/list.val", "rt");
	if (!input)
	{
		printf("Cannot open list.val\n");
		return 0;
	}

	int bytes = 1;
	char single[256];

	while (bytes > 0)
	{
		bytes = fscanf(input, "%s", single);
		
		if (bytes > 0)
		{
			for (int i=0; i<64; i++)
			{
				list[total][i] = single[i];
			}

			total++;		
		}
	}

	fclose(input);

	system("rm /home/username/PeanutGB/list.val");

	system("stty -echo -icanon");

	int file = 0;
	char buffer[1] = { '0' };
	
	int redraw = 1;

	while (buffer[0] != 27) // escape
	{
		if (redraw > 0)
		{
			redraw = 0;

			system("clear");
			printf("PeanutGB-RPi02W\n");
			printf("D-Pad: WSAD = UDLR\n");
			printf("Buttons: NM = BA\n");
			printf("Enter/Backspace = Start/Select\n");
			printf("Escape to Exit\n");
			printf("Select Game:\n\n");

			for (int i=select-5; i<=select+5; i++)
			{
				if (i < 0) printf(" \n");
				else if (i >= total) printf(" \n");
				else if (i == select) printf(">%s\n", list[select]);
				else printf(" %s\n", list[i]);
			}
		}

		file = open("/dev/stdin", O_RDONLY);
		read(file, &buffer, 1);
		close(file);

		if (buffer[0] == 119) // W
		{
			if (select > 0) select--;

			redraw = 1;
		}
		else if (buffer[0] == 115) // S
		{
			if (select < total-1) select++;

			redraw = 1;
		}
		else if (buffer[0] == 110 || // N
			buffer[0] == 109 || // M
			buffer[0] == 10 || // enter
			buffer[0] == 127) // backspace
		{
			char command[512];
			for (int i=0; i<512; i++) command[i] = 0;
			sprintf(command, "/home/username/PeanutGB/PeanutGB.o /home/username/PeanutGB/ROMS/%s", list[select]);
			system(command);

			buffer[0] = 27; // escape
		}
	}	

	system("stty echo icanon");

	return 1;
}
