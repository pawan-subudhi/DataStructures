//Whatever you are trying to return from pop function to show
//it as a error should not be a member of stack.
#include<stdio.h>
#include<stdlib.h>
struct node{
	int i;
	struct node *link;
};
struct node *head=NULL;
void push(int item){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL){
		printf("Malloc error\n");
		return;
	}
	temp->i=item;
	temp->link=head;
	head=temp;
}
int pop(){
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
		printf("1:Push\n2:Pop\n3:Exit\nEnter the operation value::");
		scanf("%d",&i);
		if(i==1){
			printf("Enter the element to be pushed into the stack::");
			scanf("%d",&ele);
			push(ele);
		}
		else if(i==2)
			printf("the popped element is::%d\n",pop());
		else if(i==3)
			break;
		else
			printf("Invalid Input\n");
	}
	return 0;
}