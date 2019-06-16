//Q is implemented using 2 stacks s1 and s2
//For enqueuing into queue we perform push operation to the item on the stack s1 and 
// For dequque operation we perform by poping all the available item from stack s1 to s2 and then a single pop from s2 in order to follow the Queue property.
#include<stdio.h>
#include<stdlib.h>
#define max 10
struct stack{
	int *arr;
	int size,top;	
};
struct stack* createStack(int size){
	struct stack *s=(struct stack*)malloc(sizeof(struct stack));
	s->arr=(int*)malloc(sizeof(int)*size);
	s->top=-1;
	s->size=size;
	return s;
}
void push(struct stack *s,int item){
	if(s->top==max-1)
		printf("Overflow\n");
	else{
		s->top++;
		s->arr[s->top]=item;
	}
	return;
}
void enqueue(struct stack *s1,int item){
	push(s1,item);
}
int stack_empty(struct stack *s){
	if(s->top==-1)
		return 1;
	else
		return 0;
}
int pop(struct stack *s){
	int x = s->arr[s->top];
	s->top--;
	return x;
}
int dequeue(struct stack *s2,struct stack *s1){
	int x;
	if(stack_empty(s2)){
		if(stack_empty(s1)){
			printf("Queue is empty\n");
			return -1;
		}
		else{
			while(!stack_empty(s1)){
				x=pop(s1);
				push(s2,x);
			}
		}
	}
	x=pop(s2);
	return x;
}

int main(){
	int i,ele;
	struct stack *s1,*s2;
	s1=createStack(max);
	s2=createStack(max);
	printf("Enter the slno for the corresponding operation\n");
	while(1){
		printf("1:Enqueue\n2:Dequeue\n3:Exit\nEnter the operation value::");
		scanf("%d",&i);
		if(i==1){
			printf("Enter the element to be enqueued into the queue::");
			scanf("%d",&ele);
			enqueue(s1,ele);
		}
		else if(i==2)
			printf("the dequeued element is::%d\n",dequeue(s2,s1));
		else if(i==3)
			break;
		else
			printf("Invalid Input\n");
	}
	return 0;
}