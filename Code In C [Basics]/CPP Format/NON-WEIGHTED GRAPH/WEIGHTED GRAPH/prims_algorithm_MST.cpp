#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define V 7

int min_edge(int dist[],bool visited[]){
	int min=INT_MAX,min_index;
	for(int i=0;i<V;++i){
		if(visited[i]==false&&dist[i]<min){
			min=dist[i];
			min_index=i;
		}
		
	}
	return(min_index);
}
int printMST(int parent[], int n, int graph[V][V]) 
{ 
printf(":::::::::::MINIMUM SPANNING TREE::::::::::"); 
for (int i = 1; i < V; i++) 
	printf("\n%d ---->---(%d)---->-----%d \n", parent[i]+1, graph[i][parent[i]],i+1); 
} 

void primsTree(int graph[V][V]){
	bool visited[V];
	int parent[V];
	int dist[V];
	for(int i=0;i<V;++i){
		dist[i]=INT_MAX;
		visited[i]=false;
	}
	
	dist[0]=0;
	parent[0]=-1;
	for(int i=0;i<V-1;++i){
		int u=min_edge(dist,visited);
		visited[u]=true;
		for(int v=0;v<V;++v){
			if(graph[u][v]&&visited[v]==false&&graph[u][v]<dist[v]){
				parent[v]=u;
				dist[v]=graph[u][v];
			}
		}
	}
		printMST(parent, V, graph); 
}
int main(){
	int graph[V][V]={{0,10,18,0,0,0,0},
	            {10,0,6,0,20,0,0},
	            {18,6,0,70,0,0,0},
				{0,0,70,0,0,0,0},
				{0,20,0,0,0,10,10},
				{0,0,0,0,10,0,5},
				{0,0,0,0,10,5,0}};
				
				primsTree(graph);
				return 0;
}



