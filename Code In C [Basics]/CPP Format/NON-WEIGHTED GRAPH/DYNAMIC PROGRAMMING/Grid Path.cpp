#include<stdio.h>

int numberOfPaths(int m, int n) 
{ 
	int count[++m][++n]; 
	for (int i = 0; i < m; i++) 
		count[i][0] = 1; 
	for (int j = 0; j < n; j++) 
		count[0][j] = 1; 
	for (int i = 1; i < m; i++) 
	{ 
		for (int j = 1; j < n; j++) 
		 if((i==2||i==4)&&j==4){
		  	// when there is a hole in the path
		  	count[i][j]=0;
		  	
		  }
		  else{
		    //no hole in that path
			count[i][j] = count[i-1][j] + count[i][j-1]; 
         }
          
	} 
	for(int i=0;i<m;i++){
		for(int j=0;j<n;++j){
			printf("| %d     ",count[i][j]);
		}
		printf("\n");
	}
	return count[m-1][n-1]; 
} 

int main() 
{ 
	printf("%d", numberOfPaths(5,10));
	
	return 0; 
} 
