//Whatever you are trying to return from dequeue function to show it as an error should not be a member of queue.
//We are going to use circular representation of an array in order to use the free spaces available in queue.
#include<stdio.h>
#define max 10
int front=-1,rear=-1;
int queue[max];
void enqueue(int item){
	rear=(rear+1)%max;
	if(front==rear){
		printf("Queue is full\n");
		if(rear==0)
			rear=max-1;
		else
			rear=rear-1;
		return;
	}
	else{
		queue[rear]=item;
		return;
	}
}
int dequeue(){
	if(front==rear){
		printf("Queue is empty\n");
		return -1;
	}
	else{
		front=(front+1)%max;
		int item=queue[front];
		return item;
	}
}
int main(){
	int i,ele;
	printf("Enter the slno for the corresponding operation\n");
	while(1){
		printf("1:Enqueue\n2:Dequeue\n3:Exit\nEnter the operation value::");
		scanf("%d",&i);
		if(i==1){
			printf("Enter the element to be enqueued into the queue::");
			scanf("%d",&ele);
			enqueue(ele);
		}
		else if(i==2)
			printf("The dequeud element is::%d\n",dequeue());
		else if(i==3)
			break;
		else
			printf("Invalid Input\n");
	}
	return 0;
}