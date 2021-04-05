#include<stdio.h>
#include<stdlib.h>
struct graph* gr=NULL;
struct node{
	int dest;
	struct node* next;
};

struct adjlist{
	struct node* head;
};

struct graph{
	int v;
	struct adjlist* array;
	
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
	gr->array=(struct adjlist*)malloc(v*sizeof(struct adjlist));
	for(int i=0;i<v;i++){
		gr->array[i].head=NULL;
	}
	return(gr);
	
}

void add_edge(struct graph* gr,int src,int dest){
	struct node* temp=cnode(dest);
	temp->next=gr->array[src].head;
	gr->array[src].head=temp;

}

bool iscycleutil(int v,bool visited[],bool stack[]){
	if(visited[v]==false){
		visited[v]=true;
		stack[v]=true;
		struct node*temp=gr->array[v].head;
		while(temp!=NULL){
			int k=temp->dest;
			if(visited[k]==false&&iscycleutil(k,visited,stack)){
			   printf(" %d<--",k);	
				return true;
			}
			else if(stack[k]==true){
				printf("\n I got a cycle:::: from %d to %d\n",k,v);
				printf("\n%d<--",k);
				return true;
				
			}
			temp=temp->next;
		}
		stack[v]=false;
		return false;
		
	}
}

bool iscycle(){
	bool visited[gr->v],stack[gr->v];
	for(int i=0;i<gr->v;++i){
		visited[i]=false;
		stack[i]=false;
		
	}
	for(int i=0;i<gr->v;i++)
		if(iscycleutil(i,visited,stack))
			return true;
		
	return false;
	
}
void printgraph(){
   for(int i=1;i<gr->v;++i){
   	struct node* temp=gr->array[i].head;
   	printf("\n %d",i);
	   while(temp){
   		printf("--->%d",temp->dest);
   		temp=temp->next;
	   }
   }
}


int main(){
gr = cgraph(11);
    add_edge(gr, 2,1);
    add_edge(gr, 1,3);
    add_edge(gr, 1,4);

    add_edge(gr, 3,2);
        if(iscycle())
printf("\n\nyes there is cycle");
else
printf("no cycle");
    add_edge(gr, 4,5);
   // add_edge(gr, 4,8); 
    //add_edge(gr, 5,6);
    add_edge(gr, 5,7);
    add_edge(gr, 7,6);
    add_edge(gr, 6,8);
    add_edge(gr, 8,4);
    
   // add_edge(gr, 9,10);
    //add_edge(gr, 8,7);
    printgraph();
    
if(iscycle())
printf("\n\nyes there is cycle");
else
printf("no cycle");
}



