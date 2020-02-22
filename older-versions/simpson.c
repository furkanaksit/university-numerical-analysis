#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

double function(double x, double p[], int num);
int main()
{
	int  N,j,i,n;
	double f[20],uL,lL,h,sum,x[20];
	
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
		
	printf("give the upper bound= ");
	scanf("%lf",&uL);
	printf("give the lower bound= ");
	scanf("%lf",&lL); 
	printf("give the number of trapezoids= ");
	scanf("%d",&n);
	h=(uL-lL)/n;
	sum=0;
	for(i=0;i<=n;i++){
		x[i]=lL+i*h;
		}
	for(i=0;i<=n;i++){
		if(i==0){sum=sum+function(x[i],f,N);}
		else if(i==n){sum=sum+function(x[i],f,N);}
		else if(i%2==0){sum=sum+(2*function(x[i],f,N));}
		else if(i%2!=0){sum=sum+(4*function(x[i],f,N));}
	}


	sum=sum*h/3; 
	printf("alan= %lf",sum);
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

