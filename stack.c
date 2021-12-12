#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
int val;
struct node* next;
};

void deque(struct node * (&front) ,struct node * (&rear)){
    if(front==rear){
        printf("Queue is Empty \n");
    }
    else{
       struct node *ptr=front;
       front=front->next;
       free(ptr);
    }
}

void display(struct node *ptr){
while(ptr!=NULL){
    printf("%d ", ptr->val);
    ptr=ptr->next;
}
printf("\n");
}

void enque(struct node *(&front), struct node *(&rear)){
int data;
printf("Enter the data \n");
scanf("%d",&data);
struct node *n =(node*) malloc(sizeof(struct node));
if(n==NULL){
    printf("Queue is Full \n");
}
else{
n->val=data;
n->next=NULL;
if(rear==NULL && front==NULL){
front=n;
rear=n;
return; 
}        
else{
rear->next=n;
rear=n;
}
}
}

int main()
{ 
     printf("Hi dear User...I Hope u will love my work :) \n This Program is about Queues and its Operations in which U can arrange you data via Queue Data Structure \n memory is being allocated Dynamically and Efficiently \n You can do the following operations\n 1:Enque 2:Deque 3:Display \n");
   struct node *front =(node*) malloc(sizeof(struct node));
   struct node *rear =(node*) malloc(sizeof(struct node));
   rear=NULL;
   front=NULL;
   while(1){
   printf("Enter Your no. according to the above operations provided \n");    
   int ch;
   scanf("%d",&ch);
   switch(ch){
       case 1: enque(front,rear);
       break;
       case 2: deque(front,rear);
       break;
       case 3: display(front);
       break;
       default: printf("Fir se try kariye \n");
   }
   }
   return 0;
}