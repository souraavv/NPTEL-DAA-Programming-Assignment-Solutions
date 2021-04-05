#include<stdio.h>
#include<stdlib.h>
#define size 100

struct graph* gr=NULL;
struct queue* q=NULL;
struct queue{
	int items[size];
	int front,rear;
};
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
	
	int i=0;
	for(i=0;i<v;++i){
		gr->array[i].head=NULL;
	}
	return(gr);
}
void add_edge(struct graph* gr,int src,int dest){
	struct node* temp=cnode(dest);
	temp->next=gr->array[src].head;
	gr->array[src].head=temp;
	temp=NULL;
	free(temp);

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
                printf("|%d| ", q->items[i]);
               
        }
       printf("\n"); 
    }    
}		
void toUtil(int indegree[]){
	for(int v=1;v<gr->v;v++){
		if(indegree[v]==0){
			indegree[v]=-1;
			enqueue(q,v);
		
		
			
			while(isEmpty(q)==false){
				int u=dequeue(q);
				indegree[u]=-1;
				printf("%d --->",u);
				struct node* temp=gr->array[u].head;
				while(temp!=NULL){
					int k=temp->dest;
					indegree[k]=indegree[k]-1;
					if(indegree[k]==0){
						
						enqueue(q,k);
						
						
						
					}
				
					temp=temp->next;
				}
			}
		
		}	
	}	
}
void topl_order(){
	int indegree[gr->v];
	 for(int i=0;i<gr->v;++i){
    	indegree[i]=0;
		}
		
    for(int i=0;i<gr->v;++i){
    
    	struct node* temp=gr->array[i].head;
    	while(temp!=NULL){
    	
    		int k=temp->dest;
    		indegree[k]++;
    		
    		temp=temp->next;
		}
		
	}
	
	toUtil(indegree);

}


int main(){

     
     gr = cgraph(9);
    add_edge(gr, 1,5);
    add_edge(gr, 1,4);
    add_edge(gr, 1,3);
   add_edge(gr, 2,3);
    add_edge(gr, 2,8);
    add_edge(gr, 3,6); 
   add_edge(gr, 4,6);
    add_edge(gr, 4,8);
    add_edge(gr,5,8);
    add_edge(gr, 6,7);
    add_edge(gr, 7,8);
    
     
	printf("Topological order of given graph is:\n");
	q=cqueue();
	
	topl_order();
	 
return 0;
}