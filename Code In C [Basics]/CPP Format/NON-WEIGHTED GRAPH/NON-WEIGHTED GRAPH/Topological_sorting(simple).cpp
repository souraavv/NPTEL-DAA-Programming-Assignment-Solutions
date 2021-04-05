#include<stdio.h>
#include<stdlib.h>

struct graph* gr=NULL;
struct node{
	int dest;
	struct node* next;
};
struct list{
	struct node* head;
};
struct graph{
	int v;
	struct list* array;
};
struct stack{
	int arr[10];
	int front;
};
struct node* cnode(int dest){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->dest=dest;
	temp->next=NULL;
	return(temp);
}
struct graph* cgraph(int v){
	struct graph* gr=(struct graph*)malloc(sizeof(struct graph));
	gr->v=v;
	gr->array=(struct list*)malloc(v*sizeof(struct list));
	int i=0;
	for(i=0;i<v;++i){
		gr->array[i].head=NULL;
	}
	return(gr);
}
void addedge(struct graph* gr,int src,int dest){
	struct node* temp=cnode(dest);
	temp->next=gr->array[src].head;
	gr->array[src].head=temp;
    temp=NULL;
    free(temp);
	
}
struct stack* cstack(){
	struct stack* st=(struct stack*)malloc(sizeof(stack));
	st->front=-1;
	
}
void push(struct stack* st,int p){
	st->arr[++st->front]=p;
}
void pop(struct stack* st){
     --st->front;
}
int top(struct stack* st){
	return(st->arr[st->front]);
}
bool isempty(struct stack* st){
	if(st->front==-1){
		return true;
	}
	return false;
}
void print(struct graph* gr){
	int v;
	for(v=0;v<gr->v;++v){
		struct node* temp=gr->array[v].head;
		printf("\n|%d|",v);
		
	    while(temp!=NULL){
	    	printf("---->%d",temp->dest);
	    	temp=temp->next;
		}
		if(temp==NULL){
			printf("--->NULL");
			
		}
	
		
	}
}


void tsUtil(int v,bool visited[],struct stack *st){
	visited[v]=true;
	struct node* temp=gr->array[v].head;
	while(temp!=NULL){
		int  k=temp->dest;
		if(!visited[k]){
			tsUtil(k,visited,st);
				}
	 temp=temp->next;	 
}
	push(st,v);
}
void topological_sort(){
	struct stack* st=cstack();
	bool visited[gr->v];
	for(int i=0;i<gr->v;++i){
		visited[i]=false;
	}
	for(int i=0;i<gr->v;i++){
		if(!visited[i]){
	
			tsUtil(i,visited,st);
		}
	}

   printf("\n TOPOLOGICAL ORDER IS : \n");
	while(isempty(st)==false){
		int k=top(st);
		printf(" %d-->",k+1);
		pop(st);
		
	}
	
	
}

int main(){
	gr=cgraph(8);
	
	addedge(gr,0,2);
	addedge(gr,0,3);
	addedge(gr,0,4);
	addedge(gr,1,2);
	addedge(gr,1,7);
	addedge(gr,2,5);
	addedge(gr,3,5);
	addedge(gr,3,7);
	addedge(gr,4,7);
	addedge(gr,5,6);
	addedge(gr,6,7);
   topological_sort();
	
	return 0;
	
}
	