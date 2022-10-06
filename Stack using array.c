#include< stdio.h >

#define MAX 100

/* declaration*/
typedef struct
{
        int ele[MAX];
        int TOP;
}
STACK;

STACK * s;

/* function: pushItem( ), to insert an item into stack. */
void pushItem(STACK * s, int ITEM)
{
        if (s -> TOP == MAX - 1)

        {
                printf("\nSTACK is FULL.\n");
                return;
        }
        s -> ele[++s -> TOP] = ITEM;
        printf("\nITEM inserted successfully.\n");
}

/* function: popItem( ), to delete an item from stack. */
int popItem(STACK * s)
{

        int itm;
        if (s -> TOP == -1) 
        {
                printf("\nSTACK is empty.\n");
                return;
        }
        itm = s -> ele[s -> TOP];
        s -> TOP--;
        printf("\nItem removed : %d\n", itm);
}

/* function: dispItem( ), to display stack elements. */
void dispItems(STACK * s) 
{
        int i;
        if (s -> TOP == -1)
        {
                printf("STACK IS EMPTY.");
                return;
        }
        for (i = s -> TOP; i >= 0; i--)
                printf("%d->", s -> ele[i]);

        printf("\n");
}

/* main function **/
void main() 
{
        int num;
        char dummy;

        /* initialisation*/

        s = (STACK * ) malloc(sizeof(STACK));
        s -> TOP = -1;

        int choice = 0;

        again:

                /* display stack elements **/
                printf("\nSTACK ELEMENTS :");
        dispItems(s);

        printf("\nSTACK OPTIONS \n0: Exit\n1: Add item\n2: Remove item \nEnter choice :::");
        scanf("%d", & choice);

        switch (choice)
        {

        case 0:
                exit(1);
                break;

        case 1:
                printf("\nEnter an item to insert:");
                scanf("%d", & num);
                pushItem(s, num);
                break;

        case 2:
                popItem(s);
                break;

        default:
                printf("\nAn Invalid Choice !!!");
                break;

        }

        scanf("%c", & dummy);
        goto again;

}
