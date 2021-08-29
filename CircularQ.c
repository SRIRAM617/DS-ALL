#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int data;
    int size;
    int first;
    int rear;
    int *q;
};
void Create(struct queue *q1)
    {


    printf("Enter the size of the array\n");
    scanf("%d",&q1->size);
    q1->first=q1->rear=0;
    q1->q=(int*)malloc(q1->size*sizeof(int));
    }
void enqueue(struct queue *q1,int element)
{
    if((q1->rear+1%q1->size)==q1->first)
        printf("\nQueue overflow or Queue is full\n");
    else
    {
      q1->rear=(q1->rear+1)%q1->size;
      q1->q[q1->rear]=element;
    }
}
int dequeue(struct queue *q1)
{
    int x=-1;
    if(q1->first==q1->rear)
        printf("\nQueue underflow\n");
    else
    {
      q1->first=((q1->first+1)%(q1->size));
      x=q1->q[q1->first];
      return x;
    }
}
void display(struct queue q1)
{
    int i;
    i=q1.first+1;
    do
    {
        printf("%d",q1.q[i]);
        i=(i+1)%q1.size;
        printf("\n");
    }while(i!=(q1.rear+1)%q1.size);
}
int main()
{
    struct queue q1;
    Create(&q1);
    enqueue(&q1,1);
    enqueue(&q1,2);
    enqueue(&q1,3);
    enqueue(&q1,4);
    dequeue(&q1);
    dequeue(&q1);
    enqueue(&q1,5);
    enqueue(&q1,6);

    display(q1);

}
