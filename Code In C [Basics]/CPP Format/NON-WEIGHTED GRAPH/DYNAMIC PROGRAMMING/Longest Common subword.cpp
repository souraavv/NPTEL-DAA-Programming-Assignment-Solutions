#include<stdio.h>

int size(char A[]){
	int c=0,i=0;
	while(A[i]!='\0'){
		i=i+1;
		c=c+1;
	}
	return c+1;

	}

int LCW(char A[],char B[]){
	int LCW[size(A)][size(B)];
	for(int r=0;r<size(A);++r)
	  LCW[r][size(B)-1]=0;
	for(int c=0;c<size(B);++c)
	  LCW[size(A)-1][c]=0;
	
	int maxval=0;
	
	for(int c=size(B)-2;c>=0;--c){
		for(int r=size(A)-2;r>=0;--r){
			if(A[r]==B[c])
			  LCW[r][c]=1+LCW[r+1][c+1];
			else
			   LCW[r][c]=0;
		    if(LCW[r][c]>maxval)
		      maxval=LCW[r][c];
		}
	}  
	for(int i=0;i<size(A);++i)
	  {
	  for(int j=0;j<size(B);++j)
	   printf("|%d ",LCW[j][i]);
      printf("\n");
}
	return maxval;
      
}


int main(){
	char A[]="secret";
	char B[]="bisect";
	int p=LCW(A,B);
	printf("\n ANS: %d",p);
}