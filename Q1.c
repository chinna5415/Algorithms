#include <stdio.h>
#include <stdlib.h>
#include "chinna.h"

int main() {
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
								break;
				}

				case 'B' : {
								if (data[i] == '0')
									state = 'C';
								else if (data[i] == '1')
									state = 'I';
								break;
				}

				case 'C' : {
								if (data[i] == '0')
									state = 'B';
								else if (data[i] == '1')
									state = 'A';
								break;
				}

				case 'A' : {
								if (data[i] == '0')
									state = 'I';
								else if (data[i] == '1')
									state = 'C';
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
	

	return 0;
}
