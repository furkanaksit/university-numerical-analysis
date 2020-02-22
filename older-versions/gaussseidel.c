#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>





int main()
{							//dynamic malloc bilmediğimiçin
  double xi,ErrorA,ErrorH,x[3];//bilinmeyen sayısı 3 olarak varsayılmıştır
  int i,j,c;				
  double matrix[20][20];
  int dim;
  
  
  printf("give the approximate error= ");
  scanf("%lf",&ErrorA);
  printf("\n\nEnter the number of unknowns(1-19) : ");
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
for(i=1;i<=dim;i++){
	x[i]=0;
	}
 do{
		xi=x[1];
		for(i=1;i<=dim;i++){			
			x[i]=matrix[i][dim+1];
			//printf("\n----x[%d]= %lf------",i,x[i]);
			for(j=1;j<=dim;j++){
				if(j!=i){
					x[i]-=matrix[i][j]*x[j];					
					}					
			}
			x[i]/=matrix[i][i];
			printf("\nx[%d]= %lf\n",i,x[i]);
		}
		ErrorH=((xi-x[1])/xi)*100;
		printf("\nerror= %.5lf\n",ErrorH);
		printf("\n-----------\n");
		if(ErrorH<0){
			ErrorH*=-1;
			}
		Sleep(1000);		 
	 }while(ErrorH>ErrorA);
//********************//////////////*******************
  
	
	for(i=1;i<=dim;i++){
		printf("\nX%d= %lf",i,x[i]);
	}
}

	
