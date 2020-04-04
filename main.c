#include <stdio.h>
#include <stdlib.h>
#include "header\lang.h"
#include "header\command.h"

void menuloop();

int main(int argc, char const *argv[])
{
	menuloop();
}

void menuloop() {
	CMD all[4];
	all[0] = downFBT;
	all[1] = downEBT;
	all[2] = down7zip;
	all[3] = downHxd;

	int sel;
	int i, j;
	while (1) {
		i = 0;
		while (i < STRLEN) {
			printf("%s", menustr[i]);
			i++;
		}

		printf("select : ");
		fflush(stdin);
		scanf("%d", &sel);

		system("cls");

		CMD c;
		switch(sel) {
		case 0:
			c = endder;
			break;
		case 1:
			c = downFBT;
			break;
		case 2:
			c = downEBT;
			break;
		case 3:
			c = down7zip;
			break;
		case 4:
			c = downHxd;
			break;
		case 5:
			j = 0;
		while (j < 5) {
			(all[j])();
			j++;
		}
		break;
		default:
			c = resel;
			break;
		}
		c();
	}
}