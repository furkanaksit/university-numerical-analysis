#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

double function(double x, double p[], int num);
double area(double upperL, double lowerL, double h, double f[],int N);

int main(int argc, char **argv)
{
	int  N,j,i,n;
	double f[20],uL,lL,h,sum;
	
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
	uL=lL+h;
	sum=0;
	for(i=1;i<=n;i++){
		sum=sum+area(uL,lL,h,f,N);
		lL=lL+h;
		uL=uL+h;
		}
	printf("alan= ",sum);
	return 0;
}

double area(double upperL, double lowerL, double h, double f[],int N){
	double res;
	res= ((function(upperL,f,N)+function(lowerL,f,N))*h)/2;
return res;
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
