------------------------------------------SIRUSERI TRAFFIC LIGHT~SELF WRITTEN---------------------------------------
#include<stdio.h>
#include<limits.h>
#define r 4

int min_distance(int dist[],bool visited[]){
	int min=INT_MAX,min_index;
	for(int i=0;i<r;i++){
		if(visited[i]==false&&dist[i]<=min){
			min=dist[i];
			min_index=i;
		}
	}
	return(min_index);
}

int dijkstra(int graph[r][r],int time[r],int src,int dest){
	int dist[r];
	bool visited[r];
	for(int i=0;i<r;i++){
		dist[i]=INT_MAX;
		visited[i]=false;
		
	}
	dist[src]=0;
	for(int i=0;i<r-1;++i){
		int u=min_distance(dist,visited);
		visited[u]=true;
		for(int j=0;j<r;j++)
		if(!visited[j]&&graph[u][j]&&dist[u]!=INT_MAX){
			if(dist[j]>graph[u][j]+dist[u]&&(j!=dest)){
			
			if(graph[u][j]%time[j]==0){
				dist[j]=graph[u][j]+dist[u];
				
			}
			else{
				dist[j]=dist[u]+graph[u][j]+(time[j]-(graph[u][j]%time[j]))
		}
	  }
	  if(dist[j]>graph[u][j]+dist[u]&&j==dest){
	  	dist[j]=graph[u][j]+dist[u];
	  }
     }
}
return(dist[3]);
}

int main(){
  
    int time[r];
    for(int a=0;a<r;++a){
    	scanf("%d",&time[a]);
	}
	int graph[r][r];
	for(int g=0;g<r;g++){
		for(int f=0;f<r;f++){
			graph[g][f]=0;
		}
	}
	for(int b=0;b<r+1;b++){
	
   int i,j,k;
   scanf("%d %d %d",&i,&j,&k);
   graph[i-1][j-1]=k;
}
printf("ANS:: ");


int p=dijkstra(graph,time,0,3);
printf("\n%d",p);
    return 0; 

}

sample input:
4 3 2 5
1 2 4
1 3 8
2 3 6
2 4 10
3 4 7