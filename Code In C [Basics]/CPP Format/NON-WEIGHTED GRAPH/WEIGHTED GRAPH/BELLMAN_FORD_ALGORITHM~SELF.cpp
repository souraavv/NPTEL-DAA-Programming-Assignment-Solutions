#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int min(int a,int b){
	if(a<b)return a;

		return b;
	
}
struct graph* gr=NULL;
struct node{
	int dest;
	int weight;
	struct node* next;
};

struct list{
	struct node* head;
	
};

struct graph{
	int v;
	
	struct list* array;
};

struct node* cnode(int dest,int w){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->dest=dest;
	temp->weight=w;
	temp->next=NULL;
	
	return(temp);
}

struct graph* cgraph(int v){
	struct graph* gr=(struct graph*)malloc(sizeof(struct graph));
	gr->v=v;
	gr->array=(struct list*)malloc(v*sizeof(struct list));
	for(int i=0;i<v;++i){
		gr->array[i].head=NULL;
	}
	return(gr);
}
void addedge(struct graph* gr,int src,int weight,int dest){
	struct node* temp=cnode(dest,weight);
	temp->next=gr->array[src].head;
	gr->array[src].head=temp;
	printf("ADDED EDGE:: %d---(%d)--->%d\n",src,weight,dest);
	temp=NULL;
	delete(temp);
}

void bellman(int src){
	int dist[gr->v];
	for(int i=0;i<gr->v;++i){
		dist[i]=INT_MAX;
	
	}
	dist[src]=0;

	
	for(int j=0;j<gr->v;++j){
	
	
    	for(int i=0;i<gr->v;++i){
	
	          if(dist[i]!=INT_MAX){
	
		        struct node* temp=gr->array[i].head;
		        while(temp!=NULL){
		     	int j=temp->dest;
		       	int w=temp->weight;
		       /*	printf("setting %d from %d  ",j+1,i+1);
		         printf("\t weight : %d  \n",w);*/
		    	dist[j]=min(dist[j],dist[i]+w);
	
	 	        temp=temp->next;
	           }
           } 
	
       }
	


/*for(int i=0;i<gr->v;++i){
		printf("\n|%d| -- |%d|",i+1,dist[i]);
	}
	printf("\n---------------------------------------------------\n");*/
      }

printf("::::::::CALCULATING SHORTEST PATH IN NEGATIVE WEIGHT EDGE GRAPH::::::::\n");
for(int i=0;i<gr->v;++i){
	if(dist[i]==INT_MAX){
	
		printf("\n|%d|---->-----------|INFINITE|--->-----------------------|%d|",src+1,i+1);
	}
	else{
		printf("\n|%d|---->---|%d|--->----|%d|",src+1,dist[i],i+1);
	}
	
}
printf("\n---------------------------------------------------\n");
}


int main(){
	gr=cgraph(8);
	addedge(gr,0,10,1);
	addedge(gr,0,8,7);
	addedge(gr,1,2,5);
	addedge(gr,2,1,1);
	addedge(gr,2,1,3);
	addedge(gr,3,3,4);
	addedge(gr,4,-1,5);
	addedge(gr,5,-2,2);
	addedge(gr,6,-1,5);
	addedge(gr,6,-4,1);
	addedge(gr,7,1,6);
	bellman(1);
	
}