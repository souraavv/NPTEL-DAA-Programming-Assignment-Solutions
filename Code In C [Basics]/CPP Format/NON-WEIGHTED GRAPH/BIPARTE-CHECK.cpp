#include<stdio.h>
#include<stdlib.h>
struct graph* gr=NULL;
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
	struct node* temp1=cnode(dest);
	temp1->next=gr->array[src].head;
	gr->array[src].head=temp1;
	struct node* temp2=cnode(src);
	temp2->next=gr->array[dest].head;
	gr->array[dest].head=temp2;
}
bool  isbiparte(int v,bool visited[],int color[]){
	struct node* temp=gr->array[v].head;
	while(temp!=NULL){
		int k=temp->dest;
		if(visited[k]==false){
			visited[k]=true;
     	  
     	    color[k]=  !color[v];
			
		
		if(!isbiparte(k,visited,color)){
			return false;
		}
	}
	else if(color[k]==color[v]){
		return false;
		
	}
	temp=temp->next;
	}
	return true;
	
}
int main(){
	gr=cgraph(7);
	add_edge(gr, 0, 1); 
    add_edge(gr, 1, 2); 
    add_edge(gr, 2, 3); 
    add_edge(gr, 3, 4); 
    add_edge(gr, 4, 5); 
    add_edge(gr, 5, 6); 
    add_edge(gr, 6, 0); 
    bool visited[7];
    int color[7];
    for(int i=0;i<7;++i){
    	visited[i]=false;
	}
	visited[0]=true;
	color[0]=0;
	if(isbiparte(0,visited,color))
	 {
	 printf("yes!");
	 }else{
	 	printf("\n no");
	 	
	 }
	 return 0;
}