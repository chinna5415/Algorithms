#include <stdio.h>
#include <stdlib.h>
#define or ||

void operation(void);

int main() {
    int op;

    while (1) {
        printf("\n1.Enter the data\n2.Exit\n");
        printf("choose your option : ");
        scanf("%d",&op);

        switch (op) {
            case 1 : operation();
                break;
            case 2 : exit(0);
                break;
            default: printf("input error");
        }
    }
}

void operation(void) {
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
                else
                    state = 'D';
                break;
            }

            case 'A' : {
                if (data[i] == '1')
                    state = 'A';
                else if (data[i] == '0')
                    state = 'C';
                else
                    state = 'D';
                break;
            }

            case 'B' : {
                if (data[i] == '1')
                    state = 'E';
                else if (data[i] == '0')
                    state = 'B';
                else
                    state = 'D';
                break;
            }

            case 'C' : {
                if (data[i] == '1')
                    state = 'E';
                else if (data[i] == '0')
                    state = 'B';
                else
                    state = 'D';
                break;
            }

            case 'E' : {
                if (data[i] == '1')
                    state = 'A';
                else if (data[i] == '0')
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

    if (state == 'A' or state == 'B')
        printf("Accepted\n");
    else if (state == 'D')
        printf("Invalid\n");
    else
        printf("Not Accepted\n");
}