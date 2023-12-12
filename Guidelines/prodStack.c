#include <stdio.h>
#include <stdlib.h>

void display(int c, int stack[]);

void main() {
    int c1 = 0, c2 = 0, n, pc[3], ch;

    printf("Enter the stack size: ");
    scanf("%d", &n);

    while (n > 0) {
        printf("\t\tProducer Stack (Stack Size : %d)", n);
        display(c1, pc);
        printf("\n\n\t\tConsumer Stack (Stack Size : %d)", n);
        display(c2, pc);

        printf("CHOICES: 1.PRODUCER\t2.CONSUMER\t3.Exit\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (c1 == n)
                    printf("Producer stack is FULL.\n");
                else {
                    c1++;
                    printf("\t\tEnter PRODUCE item is :");
                    scanf("%d", &pc[c1]);
                }
                break;

            case 2:
                if (c2 == n) {
                    printf("Consumer Stack is FULL.......\n\tReset the Cosumer Stack\n");
                    c2 = 0;
                } else if (c1 == 0)
                    printf("\tProducer stack is EMPTY\n");
                else {
                    c2++;
                    pc[c2] = pc[c1];
                    printf("\t\tCONSUME one item");
                    c1--;
                }
                break;

            case 3:
                exit(0);

            default:
                printf("\tIt is the wrong choice, Please enter correct");
        }
    }
}

void display(int c, int stack[]) {
    int i;

    if (c == 0)
        printf("\tStack is EMPTY\n\t\t");
    else
        for (i = 1; i <= c; i++)
            printf("\t%d", stack[i]);
}

