#include<stdio.h>
#define V 8
#define INF 999999

int min(int a,int b){
	if(a<b)return a;
	return b;
}
void printSolution(int dist[][V]) 
{ 
printf("\n::::::::::::::::::::::::::: ALL PAIR SHORTEST PATH ::::::::::::::::::::::::\n");
    printf("_____________________________________________________________________");
    printf("\n___|________1|______2|______3|______4|______5|______6|______7|______8|\n");
      
	for (int i = 0; i < V; i++) 
	{ 
	printf(" %d |  ",i+1);
		for (int j = 0; j < V; j++) 
		{ 
			if (dist[i][j] == INF) 
				printf("%7s|", "INF"); 
			else
				printf ("%7d|", dist[i][j]); 
		} 
		
		printf("\n"); 
	} 
	printf("_____________________________________________________________________\n");
} 
void floydWarshal(int graph[][V]){
	int dist[V][V];
	for(int i=0;i<V;++i){
	  for(int j=0;j<V;++j){
	  	dist[i][j]=graph[i][j];
	  }
	}
	
	for(int k=0;k<V;++k){
		for(int i=0;i<V;++i){
			for(int j=0;j<V;++j){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}

	printSolution(dist); 
}
int main(){
	int graph[V][V]={{0,10,INF,INF,INF,INF,INF,8},
	                 {INF,0,INF,INF,INF,2,INF,INF},
	                 {INF,1,INF,1,INF,INF,INF,INF},
	                 {INF,INF,INF,0,3,INF,INF,INF},
	                 {INF,INF,INF,INF,0,-1,INF,INF},
	                 {INF,INF,-2,INF,INF,0,INF,INF},
	                 {INF,-4,INF,INF,INF,-1,0,INF},
	                 {INF,INF,INF,INF,INF,INF,1,0}};
  
  floydWarshal(graph);
  return 0;
  
					 
					 
					 
					 
					 
					 
}

