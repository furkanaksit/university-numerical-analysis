#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double valfunc(double x, double *p, int num);
double power(double num1,double num2);
int signum(double a);

int main(int argc, char **argv)
{
	int    i,j,N,a;
	double delx,eE,rE,x,sx,f[20];

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
			printf("+");
			}else{printf("=");}
		i--;		
		}
		printf("0\n");
	printf("\ngive the accural(amount of increase each round)= ");
	scanf("%lf",&delx);
	printf("\ngive the expected error= ");
	scanf("%lf",&eE);
	printf("\ngive the starting point = ");
	scanf("%lf",&x);
	a=sizeof(f);
	while(valfunc(x,f,a)!=0){
	sx=x;
    rE=eE+1;	
    while(rE>eE){	
    	while((signum(valfunc(x,f,a))==signum(valfunc(sx,f,a)))&&(rE>eE)){
			sx=x+delx;
			rE=abs(valfunc(sx,f,a)-valfunc(x,f,a));
			            }
			if(rE>eE){
				delx=delx/2;
				     }
				}
			}	
	printf("\none of roots is %lf", sx);
	getchar();
	return 0;
}

	
double valfunc(double x, double *p, int num){
	double sum;
	int i;
	sum=0;
	for(i=0;i<=num;i++){
		sum=sum+(*(p+i)*power(x,(num-i)));
		}
	return sum;
	}
	
	
		
double power(double num1,double num2){
	//pow function misfunctioned everytime so i wrote mine
	int i;
	double pow;
	pow=1;
	for(i=1; i<=num2; i++){
		pow=pow*num1;
		}
	return pow;
	}
	
	
int signum(double a){
	// 0 for negative, 1 for positive
	int b;
	if(a<0){
		b=0;
		}else if(a>0){
		b=1;
		}else if (a==0){
			b=2; }
			return b;}
			
	
	
