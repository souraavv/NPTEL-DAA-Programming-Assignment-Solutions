#include<stdio.h>
#include<stdlib.h>
struct graph* gr=NULL;
	static int t=0;
	
int min(int a,int b){
	if(a<b){return a;
	}
	else return b;
}
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
 	struct node* temp=cnode(src);
 	temp->next=gr->array[dest].head;
 	gr->array[dest].head=temp;
 	temp=cnode(dest);
 	temp->next=gr->array[src].head;
 	gr->array[src].head=temp;
 	
 }
 
 void apu(int v,int parent[],bool visited[],int low[],int disc[]){
 
 	int children =0;
 	disc[v]=low[v]=++t;
	 visited[v]=true;

 	
 	struct node* temp=gr->array[v].head;
 	while(temp!=NULL){
 		int k=temp->dest;
 		if(visited[k]==false){
 			children++;
 			parent[k]=v;
 			apu(k,parent,visited,low,disc);
 			low[v]=min(low[v],low[k]);
 	if (low[k] > disc[v]) 
              printf("%d --%d\n",v,k);
		 }
		 else if(k!=parent[v]){
		 	low[v]=min(disc[k],low[v]);
		 }
		 temp=temp->next;
	 }
	 
 }
 
 void ap(struct graph* gr){
 	bool visited[gr->v];
 	int parent[gr->v],disc[gr->v],low[gr->v];
 	for(int i=0;i<gr->v;++i){
 		parent[i]=-1;
 		visited[i]=false;
	 }
	 
	 for(int i=0;i<gr->v;++i){
	 	if(visited[i]==false){
	 		apu(i,parent,visited,low,disc);
		 }
	 }
}

 

 int main(){
 	gr=cgraph(10);
     addedge(gr,0, 1); 
     addedge(gr,0, 2); 
     addedge(gr,0,3);
     addedge(gr,1,2);
     addedge(gr,3,4);
    ap(gr);  
 	return 0;
 }