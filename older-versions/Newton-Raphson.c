#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>


double derfunc(double f[], double d[], int N);
double function(double x, double p[], int num);


int main(int argc, char **argv)
{
	

	int s,N,j,i;
	double firstX,secondX,ErrorA,ErrorH,f[20],d[20];
	
	printf("give the number of unknowns= ");
	scanf("%d", &N);
	printf("give the function\n");
	i=N;
	for(j=0;j<=N;j++){
		printf("x^%d= ",i);
		scanf("%lf",&f[j]);
		
		if(i!=0){
			printf("+");
			}
		i--;		
		}
	i=N;
	for(j=0;j<=N;j++){
		printf("%.0lfx^%d",f[j],i);
		if(i!=0){
			if(f[j+1]>0){
			printf("+");}
			}else{printf("=");}
		i--;		
		}
		printf("0\n");
		
	printf("give the approximate error= ");
	scanf("%lf",&ErrorA);

	printf("give the starting value of x= ");
	scanf("%lf",&firstX);
	
	if(function(firstX,f,N)==0){
		 printf("starting value is a root");
		 }	
	printf("\n\n starting to calculations\n\n");
	s=0;
	do{ 
		s=s+1;
		secondX=firstX-(function(firstX,f,N)/function(firstX,d,N));
		ErrorH=((secondX-firstX)/secondX)*100;
		if(ErrorH<0){ErrorH=(-1)*ErrorH;
			}
				
		printf("firstX= %.9lf\t",firstX);
		printf("secondX =f(%.9lf)= %.9lf",firstX,secondX);
		printf("\tErrorH= %.9lf",ErrorH);
		printf("\n\n");
		
		firstX=secondX;
		
		//i'm making it slow to show the steps
		Sleep(1000);
	    	}while(ErrorH>ErrorA);
	
	
	printf("The root between the borders you gave is %.9lf.", firstX);
	printf("\n\n it took %d steps to find the root",s);
	return 0;
}

double function(double x, double p[], int num){
	double sum;
	int i;
	sum=0;
	for(i=0;i<=num;i++){
		sum=sum+(p[i]*(pow(x,(num-i))));
		}
	return sum;
	}

double derfunc(double f[],double d[], int N){
	 int i;
	 for(i=0;i<=N-1;i++){
		 d[i]=(N-i)*f[i];
		 }
		
return 0;
}
