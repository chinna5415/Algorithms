#include <stdio.h>
#include <stdlib.h>
#include "chinna.h"

int main() {
    char data[20];
    printf("enter the data : ");
    scanf("%s",data);

    char state = 'I';
    for (int i = 0; data[i] != '\0'; i++) {
        switch (state) {
            case 'I' : {
                if (data[i] == '1')
                    state = 'A';
                else if (data[i] == '0')
                    state = 'B';
                break;
            }

            case 'A' : {
                if (data[i] == '1')
                    state = 'A';
                else if (data[i] == '0')
                    state = 'C';
                break;
            }

            case 'B' : {
                if (data[i] == '1')
                    state = 'E';
                else if (data[i] == '0')
                    state = 'B';
                break;
            }

            case 'C' : {
                if (data[i] == '1')
                    state = 'E';
                else if (data[i] == '0')
                    state = 'B';
                break;
            }

            case 'E' : {
                if (data[i] == '1')
                    state = 'A';
                else if (data[i] == '0')
                    state = 'C';
                break;
            }

            case 'D' : {
                state = 'D';
                break;
            }
        }
    }

    if (state == 'A' or state == 'B')
        printf("Accepted\n");
    else if (state == 'D')
        printf("Invalid\n");
    else
        printf("Not Accepted\n");
}
