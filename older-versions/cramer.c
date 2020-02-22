#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>





double determinant(double f[20][20],int x);


int main()
{
  double matrix[20][20];
int dim;
  int i,j,c;
  double res[20],cal[20][20],detG;
  printf("\n\nEnter dimension of square matrix : ");
  scanf("%d",&dim);
  c=1;
  printf("\nEnter the elements of matrix\n");
  for(i=1;i<=dim;i++){
	printf("\t%d.equaiton\n",i);
	for(j=1;j<=dim;j++){
		printf("X%d= ",j);
		scanf("%lf",&matrix[i][j]);
    }
  printf("Enter the result of equation %d= ",i);
  scanf("%lf",&res[c]);
  c++;
  }
  c=1;
  printf("\n\n\t----------\t\t Equations \t\t------------\n");    
  for(i=1;i<=dim;i++)
     {
          printf("\t");
          for(j=1;j<=dim;j++)
          {     
              if(j!=dim){ 
               printf("%.2lfX%d +",matrix[i][j],c);}else{
				   printf(" %.2lfX%d",matrix[i][j],c);}
               c++;
          }
          printf(" = %.2lf",res[i]);
          printf("\n");
          c=1;
     }
  
  printf("\n\t----------\t\t Matrix \t\t------------\n");    
  for(i=1;i<=dim;i++)
     {
          printf("\n");
          for(j=1;j<=dim;j++)
          {     
               printf("\t%lf \t",matrix[i][j]);
          }
     }
  printf("\n \n");
  printf("\n Determinant of Matrix is %lf . ",determinant(matrix,dim));
  detG=determinant(matrix,dim);
  getch();
  c=1;
//******************** CRAMER CALCULATIONS ************************
  printf("\n \n");
  do{	
	//to reset the cal matrix
	for(i=1;i<=dim;i++){
		for(j=1;j<=dim;j++){
			cal[i][j]=matrix[i][j];			
		}
	}
	//changing the column with result column
		for(i=1;i<=dim;i++){
			cal[i][c]=res[i];			
		}
	//	printf("\ndetX%d= %lf",c,determinant(cal,dim));
		printf("\nX%d= %lf",c,determinant(cal,dim)/detG);

c++;
}while(c<=3);	
		
		
}

double determinant(double f[20][20],int x)
{
  int pr,j,p,q,t;
  double c[20],b[20][20],det=0;
  if(x==2)
  {
    det=0;
    det=(f[1][1]*f[2][2])-(f[1][2]*f[2][1]);
    return(det);
   }
  else
  {
    for(j=1;j<=x;j++)
    {        
      int r=1,s=1;
      for(p=1;p<=x;p++)
        {
          for(q=1;q<=x;q++)
            {
              if(p!=1&&q!=j)
              {
                b[r][s]=f[p][q];
                s++;
                if(s>x-1)
                 {
                   r++;
                   s=1;
                  }
               }
             }
         }
     for(t=1,pr=1;t<=(1+j);t++)
     pr=(-1)*pr;
     c[j]=pr*determinant(b,x-1);
     }
     for(j=1,det=0;j<=x;j++)
     {
       det=det+(f[1][j]*c[j]);
      }
     return(det);
   }
}
