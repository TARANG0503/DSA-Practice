#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node * next;
};

void llTraversal(struct node * head){
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
    
}

struct node * additionLinkrdList(struct  node * head, int ele){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));
    struct node * p = head;
    ptr->data = ele;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return(head);
}


int main(){
    struct node * head = (struct node *)malloc(sizeof(struct node));
    struct node * second = (struct node *)malloc(sizeof(struct node));
    struct node * third = (struct node *)malloc(sizeof(struct node));
    int ele;

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    scanf("%d", &ele);

    printf("before inserion : \n");
    llTraversal(head);


    printf("after insertion : \n");
    additionLinkrdList(head, ele);
    llTraversal(head);
    return 0;
}