#include<stdio.h>

int size(char A[]){
	int c=0,i=0;
	while(A[i]!='\0'){
		i=i+1;
		c=c+1;
	}
	return c;

}
int min(int a,int b,int c){
 if(a<b&&a<c)
   return a;
 if(b<c&&b<a)
  return b;
  return c;	
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
int ED(char A[],char B[]){
    int m=size(A);
	int n=size(B);
    int ED[m+1][n+1];
	for(int r=0;r<=m;++r)
	  ED[r][n]=m-r;
	for(int c=0;c<=m;++c)
	  ED[m][c]=n-c;
	for(int c=m-1;c>=0;--c){
		for(int r=n-1;r>=0;--r){
			if(A[r]==B[c])
			  ED[r][c]=ED[r+1][c+1];
			else
			  ED[r][c]=1+min(ED[r+1][c+1],ED[r+1][c],ED[r][c+1]);
			  
		}
		
	}
	 print(B);
	printf("\n\n");
	for(int i=0;i<=m;++i)
	  { 
	    
	    printf("|_%c_| ",A[i]);
	  for(int j=0;j<=n;++j)
	   printf("|_%d_",ED[i][j]);
	printf("|");
     printf("\n");
}
    int i=0,j=0;
    printf("\nTransforming %s to %s: ",B,A);
    while(i<=m&&j<=n){
    	if(A[i]==B[j]){
    		i++;j++;
		}
		else{  
			int k=min(ED[i+1][j+1],ED[i+1][j],ED[i][j+1]);
				if(k==ED[i+1][j])
				{
				  printf("\n Deleting: %c at position: %d in %s--->%s ",A[i],i+1,A,A+i+1);
				  i++;
			    }
				else
				{
				  printf("\n Inserting: %c at position: %d ",B[j],j+1);
				  j++;
		}
		}
	}
     return ED[0][0];

}
int main(){
	char B[]="secret";
	char A[]="bisect";
	int p=ED(A,B);
	printf("\n \nSo Number of minimum edit that are require: %d",p);
}