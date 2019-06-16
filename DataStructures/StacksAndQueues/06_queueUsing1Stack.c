//Q is implemented using single stack s
//For enqueuing into queue we perform push operation to the item on the stack s and 
// For dequque operation we perform 3 operation which is as follows reverse -> pop -> reverse to the stack s in order to follow the Queue property.
//The reverse operation reverses the element order of the stack
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
void enqueue(struct stack *s,int item){
	push(s,item);
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
void reverse(struct stack *s){
	int i,j;
	for(i=0,j=s->top;i<j;i++,j--){
		int temp=s->arr[i];
		s->arr[i]=s->arr[j];
		s->arr[j]=temp;
	}
}
int dequeue(struct stack *s){
	int x;
	if(stack_empty(s)){
			printf("Queue is empty\n");
			return -1;
	}
	reverse(s);
	x=pop(s);
	reverse(s);
	return x;
}

int main(){
	int i,ele;
	struct stack *s;
	s=createStack(max);
	printf("Enter the slno for the corresponding operation\n");
	while(1){
		printf("1:Enqueue\n2:Dequeue\n3:Exit\nEnter the operation value::");
		scanf("%d",&i);
		if(i==1){
			printf("Enter the element to be enqueued into the queue::");
			scanf("%d",&ele);
			enqueue(s,ele);
		}
		else if(i==2)
			printf("the dequeued element is::%d\n",dequeue(s));
		else if(i==3)
			break;
		else
			printf("Invalid Input\n");
	}
	return 0;
}