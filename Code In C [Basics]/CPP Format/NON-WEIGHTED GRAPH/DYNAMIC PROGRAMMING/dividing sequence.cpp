#include<stdio.h>
int maximum(int a,int b){
	if(a>b)return a;
	return b;
}

int besty(int arr[],int size){
	
	  int best[size];
	  best[0]=1;
	  int fmax=best[0];
	for(int i=1;i<size;++i){
		int max=1;
		for(int j=0;j<=i-1;++j){
			if(arr[i]%arr[j]==0)
		    	max=maximum(max,best[j]+1);

		}
		
		best[i]=max;
		fmax=maximum(best[i],fmax);
		
	}
	return fmax;
}
 main(){
	int n;
	scanf("%d",&n);

	int arr[n];
   int size=sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
	
	int k=besty(arr,size);
	printf("%d",k);

	
}