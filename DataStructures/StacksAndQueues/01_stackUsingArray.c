//Whatever you are trying to return from pop function to show
//it as a error should not be a member of stack.
#include<stdio.h>
#define max 10
int top=-1;
int stack[max];
void push(int item){
	if(top==max-1)
		printf("Overflow\n");
	else
		stack[++top]=item;
	return;
}
int pop(){
	if(top==-1){
		printf("Underflow\n");
		return -1;
	}
	else
		return stack[top--];
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