#include <stdio.h>
#define N 5

int front = -1;
int rear = -1;
int queue[N];

void enqueue(int x) {
    if ((front == 0 && rear == N - 1) || ((rear + 1) % N == front)) {
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\nNo element to delete\n");
    } else if (front == rear) {
        printf("The deleted element is %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("The deleted element is %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("The queue elements are:\n");
        int i;
        for (i=front;i!=rear;i=(i + 1)%N) {
            printf("%d ", queue[i]);
            printf("\n");
        }
        printf("%d",queue[rear]);
    }
}

int main() {
    int ch,x;
    do{
    printf("Enter your choice\n1.enqueue\n2.dequeue\n3.display\n4.exit:");
    scanf("%d",&ch);
    switch(ch){
case 1:
    printf("Enter element to enter:");
    scanf("%d",&x);
    enqueue(x);
    break;
case 2:
    dequeue();
    break;
case 3:
    display();
    break;
case 4:
    printf("exit..");
    break;
default:
    printf("choice out of range\n");
}}while(ch!=4);
    return 0;
}
