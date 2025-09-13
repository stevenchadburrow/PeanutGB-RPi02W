#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/input.h>
#include <unistd.h>

int main()
{
	system("echo \"000000000\" > /home/username/PeanutGB/buttons.val");

	char button[9];

	for (int i=0; i<9; i++) button[i] = '0';

	char string[256];

	for (int i=0; i<256; i++) string[i] = 0;

	int keys_fd;
    	struct input_event keys_ev;

	keys_fd = open("/dev/input/event0", O_RDONLY);

	if (keys_fd > 0)
	{
		while (1)
		{
			read(keys_fd, &keys_ev, sizeof(struct input_event));

			//printf("%d %d\n", keys_ev.code, keys_ev.value); // just for testing

			if (keys_ev.code == 1 && (unsigned char)keys_ev.value > 0) // escape to EXIT
			{
				button[0] = '1';
			}
			else if (keys_ev.code == 17) // w for UP
			{
				button[1] = (char)((unsigned char)keys_ev.value + '0');
			}
			else if (keys_ev.code == 31) // s for DOWN
			{
				button[2] = (char)((unsigned char)keys_ev.value + '0');
			}
			else if (keys_ev.code == 30) // a for LEFT
			{
				button[3] = (char)((unsigned char)keys_ev.value + '0');
			}
			else if (keys_ev.code == 32) // d for RIGHT
			{
				button[4] = (char)((unsigned char)keys_ev.value + '0');
			}
			else if (keys_ev.code == 14) // backspace for SELECT
			{
				button[5] = (char)((unsigned char)keys_ev.value + '0');
			}
			else if (keys_ev.code == 28) // return for START
			{
				button[6] = (char)((unsigned char)keys_ev.value + '0');
			}
			else if (keys_ev.code == 50) // m for A
			{
				button[7] = (char)((unsigned char)keys_ev.value + '0');
			}
			else if (keys_ev.code == 49) // n for B
			{
				button[8] = (char)((unsigned char)keys_ev.value + '0');
			}

			for (int i=0; i<256; i++) string[i] = 0;
	
			sprintf(string, "echo \"%c%c%c%c%c%c%c%c%c\" > /home/username/PeanutGB/buttons.val",
				button[0], button[1], button[2], button[3],
				button[4], button[5], button[6], button[7], button[8]);

			//printf("%s\n", string);
			system(string);

			if (button[0] != '0') break;
		}
	}

	if (keys_fd > 0) close(keys_fd);

    return 0;
}
