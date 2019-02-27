#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next, *prev;
};

struct node *head = NULL;

void push(){
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    printf("\n\t Enter the node data:\t");
    scanf("%d",&p->data);

    p->prev = NULL;
    p->next = NULL;

    if(head == NULL){
        head=p;
    }else{
        p->next = head;
        head = p;
    }
}

void append(){
    struct node *p,*q;
    p = (struct node*)malloc(sizeof(struct node));
    printf("\n\t Enter the node data:\t");
    scanf("%d",&p->data);

    p->prev = NULL;
    p->next = NULL;

    if(head==NULL){
        head=p;
    }else{
        q=head;
        while(q->next!=NULL){
            q= q->next;
        }
        q->next = p;
        p->prev = q;
    }
}

int count(){
    struct node *p;
    p=head;
    int i=0;
    while(p){
        i++;
        p = p->next;

    }
    return i;
}
void middle(){
    struct node *p,*q,*temp;
    p = (struct node*)malloc(sizeof(struct node));

    int pos;
    printf("\n\tPlease enter the position you want:\t");
    scanf("%d",&pos);

    printf("\n\t Enter the node data:\t");
    scanf("%d",&p->data);

    //printf("hello");

    p->prev = NULL;
    p->next = NULL;

    q=head;
    int i;



        if(pos>count()){
            printf("\n\t your position is not in our list, you have '%d'\t",count());
        }else{

            for(i=1;i<pos;i++){
                q = q->next;
            }
            p->prev = q;
            p->next = q->next;
            temp=q->next;
            temp->prev = p;
            q->next = p;
        }
    }


void display(){
    struct node *p;
    p=head;
    while(p){
        printf("\t%d",p->data);
        p = p->next;
    }

}

void main(){
    int ch;

    while(1){
        printf("\n 1. push");
        printf("\n 2. append");
        printf("\n 3. middle");
        printf("\n 4. display");

        printf("\t");
        scanf("%d",&ch);

        switch(ch){
        case 1:
            push();
            break;
        case 2:
            append();
            break;
        case 3:
            middle();
            break;
        case 4:
            display();
            break;

        case 5:
            printf("%d",count());
            break;
        default:
            main();
            break;
        }
    }

}
