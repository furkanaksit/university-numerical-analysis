#include<conio.h>
#include<stdio.h>

double matrix[20][20];
int dim;


double determinant(double f[20][20],int x);


int main()
{
  int i,j;
  printf("\n\nEnter dimension of square matrix : ");
  scanf("%d",&dim);

  printf("\nEnter the elements of matrix\n");
  for(i=1;i<=dim;i++)
  {
  for(j=1;j<=dim;j++)
  {
  printf("matrix[%d][%d] = ",i,j);
  scanf("%lf",&matrix[i][j]);
  }
  }
  printf("\n\n\t----------\t\t Matrix \t\t------------\n");    
  for(i=1;i<=dim;i++)
     {
          printf("\n");
          for(j=1;j<=dim;j++)
          {     
               printf("\t%lf \t",matrix[i][j]);
          }
     }
  printf("\n \n");
  printf("\n Determinant of Matrix is %lf .",determinant(matrix,dim));
  getch();
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
