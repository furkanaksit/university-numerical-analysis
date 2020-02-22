#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

double function(double x, double p[], int num);


int main(int argc, char **argv)
{
	int  N,j,i;
	double f[20],h,x,res;
	
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
		
	printf("give the x of f'(x)");
	scanf("%lf",&x);
	printf("give the h");
	scanf("%lf",&h);
res= (function((x+h),f,N)-function(x,f,N))/h;
printf("f'(%lf)= %lf",x,res);
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
