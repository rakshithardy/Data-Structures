#include <stdio.h>
# define N 5
int front=-1;
int rear=-1;
int queue[N];
void enque(int x){
        if(rear==N-1){
        printf("Queue overflow\n");
        }
        else if(front==-1&&rear==-1){
           front=rear=0;
           queue[rear]=x;
           }
        else{
            rear++;
            queue[rear]=x;
            }
        }
void deque(){
     if(front==-1&&rear==-1){
         printf("Queue is empty\n");
         }
     else if(front==rear){
         front=rear=-1;
         }
     else{
         printf("deleted element is %d",queue[front]);
         front++;
         }}
void display(){
     if(front==-1&&rear==-1){
         printf("Queue is empty\n");
         }
     else{
         printf("elements of Queue are:\n");
         for(int i=front;i<=rear;i++)
         {
            printf("%d\n",queue[i]);
         }
         }
     }
int main() {
    int ch, x;
    int queue[N];

    do {
        printf("\nQueue Operations\n 1.Enque(Insert) 2.Deque(Delete) 3.Display 4.Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &x);
                enque(x);
                break;
            case 2:
                deque();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exit...\n");
                break;
            default:
                printf("Choice out of range!\n");
        }
    } while (ch!=4);

    return 0;
}

