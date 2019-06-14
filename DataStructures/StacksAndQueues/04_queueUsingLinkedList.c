//Whatever you are trying to return from dequeue function to show it as an error should not be a member of queue.
//enqueue id done at the end of linked list and dequeue is done at front of linked list.
#include<stdio.h>
#include<stdlib.h>
struct node{
	int i;
	struct node *link;
};
struct node *head=NULL;
void enqueue(int item){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Malloc error\n");
		return;
	}
	temp->i=item;
	temp->link=NULL;
	if(head==NULL)
		head=temp;
	else{
		struct node *p=head;
		while(p->link!=NULL)
			p=p->link;
		p->link=temp;
	}
}
int dequeue(){
	struct node *p;
	if(head==NULL){
		printf("Underflow\n");
		return -1;
	}
	int item=head->i;
	p=head;
	head=head->link;
	free(p);
	return item;
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
			printf("the dequeued element is::%d\n",dequeue());
		else if(i==3)
			break;
		else
			printf("Invalid Input\n");
	}
	return 0;
}
