#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;
void enqueue(int element)
{
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
    {
        printf("Heap overflow");
    }
    else
    {
      t->data=element;
      t->next=NULL;
      if(front==NULL)
      {
          front=rear=t;
      }
      else
      {
        front->next=t;
      }

    }
}
int dequeue()
{
    int element=-1;
    struct Node *t;

    if(front==NULL)
        printf("Queue underflow");
    else
    {
      t=front;
      front=front->next;
      element=t->data;
      free(t);
    }
    return element;
}
void display()
{
struct Node *q=front;
    while(q!=NULL)
    {
        printf("%d\n",q->data);
        q=q->next;
    }
}
int main()
{

    struct Node *q;
    enqueue(2);
    dequeue();
    display();



    return 0;
}
