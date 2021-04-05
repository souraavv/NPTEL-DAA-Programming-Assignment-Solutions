#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define int long long
int ans=INT_MIN;

struct data* dt=NULL;

int max(int a,int b){
	if(a>b)return a;
	return b;
}
struct node{
	int dest;
	struct node* next;
	
};

struct list{
	struct node* head;
};

struct data{
	struct list* array;
};

struct node* cnode(int dest){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->dest=dest;
	temp->next=NULL;
	return(temp);
}

struct data* cdata(int v){
	struct data* dt=(struct data*)malloc(sizeof(struct data));
	dt->array=(struct list*)malloc(v*sizeof(struct list));
	for(int i=0;i<v;++i){
		dt->array[i].head=NULL;
	}
	return dt;
}

void addedge(int u,int v){
	struct node* temp=cnode(v);
	temp->next=dt->array[u].head;
	dt->array[u].head=temp;
	
}
void DFS(int a[],int p[],int node){
	
	printf("\n value at  ans:: %lld\n",ans);
	struct node* temp=dt->array[node].head;
	while(temp!=NULL){
		int k=temp->dest;
		ans=max(ans,a[node]-a[k]);
		printf("\n CALL FOR NODE %d\n",k);
		DFS(a,p,k);
		temp=temp->next;
	}

}
 main(){
	int n,root; 
	 
	scanf("%lld",&n);
	dt=cdata(n);
    int a[n],p[n]; 
	for(int i=0;i<n;++i){
		scanf("%lld",&a[i]);
	}
	
	for(int i=0;i<n;++i){
		scanf("%lld",&p[i]);
		
		if(p[i]==-1){
			root=i;
		}
		else{
			p[i]--;
			addedge(p[i],i);
			
		}
	}
	for(int i=0;i<n;++i){
	printf("%lld ",a[i]);
	}
	printf("root is : %d,",root);
	
	 DFS(a,p,root);
	printf("ans : %d",ans);
	return 0;
}

