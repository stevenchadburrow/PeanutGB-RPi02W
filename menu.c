#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char list[1024][64];
	int total = 0;

	system("ls /home/username/PeanutGB/ROMS > /home/username/PeanutGB/list.val");

	FILE *input = NULL;

	input = fopen("/home/username/PeanutGB/list.val", "rt");
	if (!input)
	{
		printf("Cannot open list.val\n");
		return 0;
	}

	int bytes = 1;
	char buffer = 0;

	while (bytes > 0)
	{
		bytes = fscanf(input, "%s", list[total]);
		
		if (bytes > 0)
		{
			total++;
		}
	}

	fclose(input);

	system("rm /home/username/PeanutGB/list.val");

	int selected = 0;
	int redraw = 1;

	int buttons_file = 0;
	char buttons_prev[9];
	char buttons_buffer[9];

	for (int i=0; i<9; i++) buttons_buffer[i] = '0';

	while (buttons_buffer[0] == '0')
	{
		for (int i=0; i<9; i++)
		{
			buttons_prev[i] = buttons_buffer[i];
		}
	
		buttons_file = open("/home/username/PeanutGB/buttons.val", O_RDONLY);
		read(buttons_file, &buttons_buffer, 9);
		close(buttons_file);

		if (buttons_buffer[2] != '0' && buttons_prev[2] == '0')
		{
			if (selected < total-1) selected++;

			redraw = 1;
		}
		else if (buttons_buffer[1] != '0' && buttons_prev[1] == '0')
		{
			if (selected > 0) selected--;

			redraw = 1;
		}
		else if (buttons_buffer[5] != '0' ||
			buttons_buffer[6] != '0' ||
			buttons_buffer[7] != '0' ||
			buttons_buffer[8] != '0')
		{
			char command[1024];

			int config_file = open("/boot/firmware/config.txt", O_RDONLY);
			read(config_file, &list[total], 16); // # config_lcd.txt or # config_hdmi.txt
			close(config_file);

			if (list[total][9] == 'l' && list[total][10] == 'c' && list[total][11] == 'd')
			{
				sprintf(command, "/home/username/PeanutGB/PeanutGB.o /home/username/PeanutGB/ROMS/%s 1", list[selected]);

				system(command);

				return 1;		
			}
			else if (list[total][9] == 'h' && list[total][10] == 'd' && list[total][11] == 'm' && list[total][12] == 'i')
			{
				sprintf(command, "/home/username/PeanutGB/PeanutGB.o /home/username/PeanutGB/ROMS/%s 0", list[selected]);
		
				system(command);

				return 1;
			}
		}

		if (redraw == 1)
		{
			redraw = 0;

			system("clear");
			printf("PeanutGB Emulator on RPi02W\n");
			printf("WSAD = UDLR\n");
			printf("NM = BA\n");
			printf("Enter/Backspace = Start/Select\n");
			printf("Escape = Exit to Console\n");
			printf("Choose Game Below:\n\n");

			for (int i=selected-5; i<=selected+5; i++)
			{
				if (i >= 0 && i < total)
				{
					if (i == selected)
					{
						printf(">%s\n", list[i]);
					}
					else
					{
						printf(" %s\n", list[i]);
					}
				}
				else
				{
					printf(" \n");
				}
			}
		}
	}

	return 1;
}
