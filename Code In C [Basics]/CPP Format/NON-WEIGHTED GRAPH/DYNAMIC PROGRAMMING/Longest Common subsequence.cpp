#include<stdio.h>

int size(char A[]){
	int c=0,i=0;
	while(A[i]!='\0'){
		i=i+1;
		c=c+1;
	}
	return c+1;

	}
void print(char A[]){
	int i=0;
	printf("      ");
	while(A[i]!='\0'){
		printf("|_%c_",A[i]);
		i=i+1;
	}
	printf("|_._|");
}
int max(int a,int b){
	if(a>b)return a;
	return b;
}
int LCS(char A[],char B[]){
	int LCS[size(A)][size(B)];
	for(int r=0;r<size(B);++r)
	  LCS[r][size(B)-1]=0;
	for(int c=0;c<size(A);++c)
	  LCS[size(A)-1][c]=0;
	  

	
	for(int c=size(B)-2;c>=0;--c){
		for(int r=size(A)-2;r>=0;--r){
			if(A[r]==B[c])
			  LCS[r][c]=1+LCS[r+1][c+1];
			else
			   LCS[r][c]=max(LCS[r+1][c],LCS[r][c+1]);
		   
		}
		
	}  print(B);
	printf("\n\n");
	for(int i=0;i<size(A);++i)
	  { 
	    
	    printf("|_%c_| ",A[i]);
	  for(int j=0;j<size(B);++j)
	   printf("|_%d_",LCS[i][j]);
	printf("|");
     printf("\n");
}
    int i=0,j=0;
    printf("\nLongest common subsequence is: ");
    while(i<=size(A)&&j<=size(B)){
    	if(A[i]==B[j]){
    		printf("%c",A[i]);
    		i++;j++;
		}
		else{  
			int k=max(LCS[i+1][j],LCS[i][j+1]);
				if(k==LCS[i+1][j])
				  i++;
				else
				  j++;
			
		}
	}
	return LCS[0][0];
      
}



int main(){
	char A[]="sharma";
	char B[]="sourav";

	int p=LCS(A,B);
	printf("\nAnd it's length is %d",p);
}