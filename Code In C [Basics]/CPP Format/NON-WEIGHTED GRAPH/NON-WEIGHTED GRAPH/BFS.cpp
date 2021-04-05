#include<stdio.h>
#include<stdlib.h>
#define size 40

struct node{
	int dest;
	struct node* next;
};
struct adj_list{
	struct node* head;
	
};
struct graph{
	int v;
	struct adj_list* array;
	int* visited;
	int* parent;
};

struct queue{
	int items[size];
	int front,rear;
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
	gr->array=(struct adj_list*)malloc(v*sizeof(struct adj_list));
	gr->visited=(int *)malloc(v*sizeof(int));
	gr->parent=(int*)malloc(v*sizeof(int));
	int i=0;
	for(i=0;i<v;++i){
		gr->array[i].head=NULL;
		gr->visited[i]=0;
		gr->parent[i]=-1;
	}
	return(gr);
}
void add_edge(struct graph* gr,int src,int dest){
	struct node* temp1=cnode(dest-1);
	temp1->next=gr->array[src-1].head;
	gr->array[src-1].head=temp1;
	struct node* temp2=cnode(src-1);
	temp2->next=gr->array[dest-1].head;
	gr->array[dest-1].head=temp2;
}

struct queue* cqueue(){
	struct queue* q=(struct queue*)malloc(sizeof(queue));
	q->front=-1;
	q->rear=-1;
	return(q);
	
}
int isEmpty(struct queue* q) {
    if(q->rear == -1) 
        return 1;
    else 
        return 0;
}

void enqueue(struct queue* q, int value){
    if(q->rear == size-1)
        printf("\nQueue is Full!!");
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct queue* q){
    int item;
    if(isEmpty(q)){
        printf("Queue is empty");
        item = -1;
    }
    else{
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear){
         //   printf("Resetting queue");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void printQueue(struct queue *q) {
    int i = q->front;

    if(isEmpty(q)) {
        printf("Queue is empty");
    } else {
        printf("\nQueue contains::");
        for(i = q->front; i < q->rear + 1; i++) {
                printf("|%d|-- ", q->items[i]+1);
               
        }
    }    
}		
void bfs(struct graph* gr,int start){
	struct queue*q=cqueue();
	gr->visited[start]=1;
	enqueue(q,start);
	while(!isEmpty(q)){
		 printQueue(q);
		int currentVertex=dequeue(q);
		printf("\nMark %d Visited\n", currentVertex+1);
	    printf("\n SO WE HAVE MARKED IT VISITED AND NOW \nLet TOP element to out from  queue and enqueue its neighbours\n");
	    printf("--------------------------------------------------------------------------------------------------------------------------------");
		struct node* temp=gr->array[currentVertex].head;
		while(temp){
			int t=temp->dest;
			if(gr->visited[t]==0){
				gr->parent[t]=currentVertex+1;
				gr->visited[t]=1;
				enqueue(q,t);
			}
			temp=temp->next;
		}
	}
	printf("\nParent array  is:\n");
	for(int i=0;i<gr->v;++i){
		printf("|%d|is parent of |%d|\n",gr->parent[i],i+1);
	}
}
void path(struct graph* gr,int dest,int src){


	int k=gr->parent[dest-1];
	printf("%d <---- %d\n",k,dest);
	if(k==src){
     printf("\n YES! ---------there is path from src to destination --------");
     
     return;
	}
	else{
		path(gr,k,src);
		
	}

}
int main()
{   char ch;
    struct graph* gr = cgraph(10);
    add_edge(gr, 1,2);
    add_edge(gr, 1,3);
    add_edge(gr, 1,4);
    add_edge(gr, 2,1);
    add_edge(gr, 2,3);
    add_edge(gr, 3,1);
    add_edge(gr, 3,2);
    add_edge(gr, 4,1);
    add_edge(gr, 4,5);
    add_edge(gr, 4,8);
    add_edge(gr, 5,6);
    add_edge(gr, 5,7);
    add_edge(gr, 6,5);
    add_edge(gr, 6,8);
    add_edge(gr, 7,5);
    add_edge(gr, 7,6);
    add_edge(gr, 8,9);
    add_edge(gr, 9,10);
 
    bfs(gr, 0);
    do{
	printf("\n\nLOOKING FOR A PATH(y/n): ");
    scanf("%c",&ch);
    
	
	int dest;
	int src;
	printf("Enter the dest : ");
	scanf("%d",&dest);
	printf("\nEnter the source : ");
	scanf("%d",&src);
    path(gr,dest,src);
    
}while(ch=='y');
    //printf("%d",gr->parent[]);
 
    return 0;
}