#include<stdio.h>
#include<stdlib.h>
static int k=0;
struct data* dt=NULL;
struct is{
	int start;
	int finish;
};

struct data{
	int v;
	struct is* array;
};

struct data* create_data(int v){
	
	struct data* temp=(struct data*)malloc(sizeof(struct data));
	temp->v=v;
	temp->array=(struct is*)malloc(v*sizeof(struct is));
	return temp;
}

void add_data(int start,int finish){
     dt->array[k].start=start;
     dt->array[k++].finish=finish;
}
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition ( int low, int high) 
{ 
    int pivot = dt->array[high].finish;    
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    {   
        if (dt->array[j].finish <= pivot) 
        { 
            i++;   
			swap(&dt->array[i].finish,&dt->array[j].finish);
			 swap(&dt->array[i].start,&dt->array[j].start);
        } 
    } 
    swap(&dt->array[i+1].finish, &dt->array[high].finish); 
    swap(&dt->array[i+1].start,&dt->array[high].start);
            
    return (i + 1); 
} 

void quickSort(struct is* arr,int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition( low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}   

void interval_scheduling(){
	
	quickSort(dt->array,0,dt->v);
	int i=0;
	printf("%d--%d",dt->array[i].start,dt->array[i].finish);
	for(int j=1;j<dt->v;++j){
		if(dt->array[j].start>=dt->array[i].finish)
		{  printf("\n%d--%d",dt->array[j].start,dt->array[j].finish);
		  i=j;
        }
	}
	
}



int main(){
	dt=create_data(6);
    add_data(5,9);
    add_data(1,2);
    add_data(3,4);
    add_data(0,6);
    add_data(5,7);
    add_data(8,9);
    interval_scheduling();
    return 0;
	
}



