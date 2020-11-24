#include <stdio.h>
#include <stdlib.h>
#include "chinna.h"

void OPERATION(void);

int main() {
	int op;

	while (1) {
		printf("1.Enter the data\n2.Exit\n");
		printf("choose your option : ");
		scanf("%d",&op);

		switch (op) {
			case 1 : OPERATION();
					 break;
			case 2 : exit(0);
					 break;
			defuatl : printf("input error!");
		}
	}

	return 0;
}

void OPERATION(void) {
	char data[10];
	printf("\nenter the string : ");
	scanf("%s",data);

	char state = 'I';
	for (int i = 0; data[i] != '\0'; i++) {
		switch (state) {
				case 'I' : {
								if (data[i] == '0')
									state = 'A';
								else if (data[i] == '1')
									state = 'B';
								else
									state = 'D';
								break;
				}

				case 'B' : {
								if (data[i] == '0')
									state = 'C';
								else if (data[i] == '1')
									state = 'I';
								else
									state = 'D';
								break;
				}

				case 'C' : {
								if (data[i] == '0')
									state = 'B';
								else if (data[i] == '1')
									state = 'A';
								else
									state = 'D';
								break;
				}

				case 'A' : {
								if (data[i] == '0')
									state = 'I';
								else if (data[i] == '1')
									state = 'C';
								else
									state = 'D';
								break;
				}

				case 'D' : {
								state = 'D';
								break;
				}
		}
	}

	if (state == 'I')
		printf("Accepted\n");
	else if (state == 'D')
		printf("Invalid\n");
	else
		printf("Not Accepted\n");
}
