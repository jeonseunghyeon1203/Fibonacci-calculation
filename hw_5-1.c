#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct{
int front;
int rear;
element data[MAX_QUEUE_SIZE]
}QueueType;

void error(char *message)
{
    fprintf(stderr,"%s\n",message);
    exit(1);
}

void init_queue(QueueType *q)
{
    q->front=q->rear=0;
}

void queue_print(QueueType *q)
{
    printf("QUEUE(front=%d rear=%d) = ",q->front,q->rear);
    if(!is_empty(q)){
        int i=q->front;
        do{
            i=(i+1)%(MAX_QUEUE_SIZE);
            printf("%d | ",q->data[i]);
            if(i==q->rear)
                break;
        }while(i!=q->front);
    }
    printf("\n");
}

int is_full(QueueType *q)
{
    return((q->rear+1)%MAX_QUEUE_SIZE==q->front);
}

int is_empty(QueueType *q)
{
    return(q->front==q->rear);
}

void enqueue(QueueType *q,int item)
{
    if(is_full(q)){
        error("큐가 포화상태입니다.");
        return;
    }
    q->rear=(q->rear+1)%MAX_QUEUE_SIZE;
    q->data[q->rear]=item;
}

element dequeue(QueueType *q)
{
    if(is_empty(q))
        error("큐가 공백상태입니다.");
    q->front=(q->front+1)%MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element peek(QueueType *q)
{
    if(is_empty(q))
        error("큐가 공백상태입니다.");
    return q->data[(q->front+1)%MAX_QUEUE_SIZE];
}
int main()
{

    int i=2;
    int s;
    int fibo[MAX_QUEUE_SIZE];
    QueueType queue;

    init_queue(&queue);

    enqueue(&queue,0);
    fibo[0]=0;
    printf("fibo[0]=%d\n",fibo[0]);

    enqueue(&queue,1);
    fibo[1]=1;
    printf("fibo[1]=%d\n",fibo[1]);
    while(i<MAX_QUEUE_SIZE)
    {
        fibo[i]=dequeue(&queue)+peek(&queue);
        enqueue(&queue,fibo[i]);
        i++;
    }

    printf("위치:");
    scanf("%d",&s);
    printf("Fibonacci(%d)=%d",s,fibo[s]);

    return 0;
}
