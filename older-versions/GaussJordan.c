#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>





int main()
{
  double matrix[20][20];
  int dim;
  double def,def2;
  int i,j,c;
  printf("\n\nEnter the number of unknowns : ");
  scanf("%d",&dim);
  c=1;
  printf("\nEnter the elements of matrix\n");
  
  for(i=1;i<=dim;i++){
	printf("\t%d.equaiton\n",i);
	for(j=1;j<=dim+1;j++){
	  if(j<=dim){  	
		printf("X%d= ",j);}else{
			printf("C%d= ",c);
			}
		scanf("%lf",&matrix[i][j]);
    }
  c++;
  }
  printf("\n\t----------\t\t Matrix \t\t------------\n");    
  for(i=1;i<=dim;i++)
     {
          printf("\n");
          for(j=1;j<=dim+1;j++)
          {     
               printf("\t%lf \t",matrix[i][j]);
          }
     }
  getch();

  printf("\n\t----------\t\t------------\n");
//********************calculations*******************
 c=0;
 do{
  c++;
  def=matrix[c][c];
  for(i=1;i<=dim;i++){
	  for(j=1;j<=dim+1;j++){
		 if(i==c){
		  matrix[i][j]=matrix[i][j]/def;
	   }
	  }
  }
  for(i=1;i<=dim;i++){
	  def2=matrix[i][c];
	  for(j=1;j<=dim+1;j++){
		  if(i!=c){
				  matrix[i][j]=matrix[i][j]-(def2*matrix[c][j]);
				  }
		  }
	  }  
printf("\n\n");
for(i=1;i<=dim;i++)
     {
          printf("\n");
          for(j=1;j<=dim+1;j++)
          {     
               printf("\t%lf \t",matrix[i][j]);
          }
}
Sleep(250);
}while(c<=dim);
//********************//////////////*******************
  
	
	for(i=1;i<=dim;i++){
		printf("\nX%d= %lf",i,matrix[i][dim+1]);
	}
}
