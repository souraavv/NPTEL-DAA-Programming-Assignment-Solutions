#include<stdio.h>
int n;
void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

void heapify(int arr[],int i){
	int l=2*i+1;
	int r=2*i+2;
	int small=i;
	if(l<n&&arr[l]<arr[i])
	  small=l;
	if(r<n && arr[r]<arr[small])
	  small=r;
	  
	if(small!=i){
		swap(&arr[i],&arr[small]);
		heapify(arr,small);
	}
}
void reset(int arr[]){
	arr[0]=arr[n-1];
	heapify(arr,0);
}

int min(int arr[]){
	int k=arr[0];
	reset(arr);
	n--;
	return k;
	
}
int main(){
	
	printf(" Enter the size of array : ");
	scanf("%d",&n);
	int arr[n];
	printf("enter the input: \n");
	for(int i=n-1;i>(n/2)-1;i--){	
		scanf(" %d",&arr[i]);
	}
	printf("\n%d\n ",(n/2)-1);
	for(int i=(n/2)-1;i>=0;i--){
		scanf("%d",&arr[i]);
    	heapify(arr,i);
	}
	
	printf("\n MINIMUM HEAP IS : \n");
	for(int i=0;i<n;++i){
		printf(" %d  ",arr[i]);
	}
	int k=min(arr);
	printf("\n\nWE are   extracting   minimum::  %d \n",k);
	
	printf("\n MINIMUM HEAP IS : \n");
	for(int i=0;i<n;++i){
		printf(" %d  ",arr[i]);
	}
	return 0;
}