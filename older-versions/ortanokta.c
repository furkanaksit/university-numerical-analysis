#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>


double function(double x, double p[], int num);


int main(int argc, char **argv)
{
	
	
	int cont, s,N,j,i;
	double lowerX,upperX,midX,ErrorA,ErrorH,f[20];
		
	
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
	//printf("%d",function(5));
  do{	
	printf("give the lower start value= ");
	scanf("%lf",&lowerX);
	
	printf("\ngive the upper start value= ");
	scanf("%lf",&upperX);
	 
	
	 if(function(lowerX,f,N)*function(upperX,f,N)>0){
	 printf("\nthere is no root in between start values\n");
	 }
	 	 
			 
 }while(function(lowerX,f,N)*function(upperX,f,N)>0);
	
	if(function(lowerX,f,N)==0){
		 printf("lower start value is a root");
		 }else if(function(upperX,f,N)==0){
			 printf("upper start value is a root");}else{
	
	midX=(lowerX+upperX)/2;
	printf("\nmidX= %.9lf",midX);}
	
	printf("\n\n starting to calculations\n\n");
	s=0;
	cont=0;
	do{ 
		s=s+1;
		if((function(lowerX,f,N)*function(midX,f,N))==0){
		cont=1;
		printf("%lf is the root", midX);
		//printf("-----------");
	 }else if(function(lowerX,f,N)*function(midX,f,N)<0){
		 //printf("*************");
		 upperX=midX;
		 ErrorH= ((midX-((lowerX+upperX)/2))/midX)*100;
		 midX= (lowerX+upperX)/2;
		 }else{
			 lowerX=midX;
			 ErrorH=(midX-((lowerX+upperX)/2))/((lowerX+upperX)/2)*100;
			 midX= (lowerX+upperX)/2;
			 }
		//abs() fonksiyonu sorun çikartigi icin if kullandim
		if(ErrorH<0){
			ErrorH=(-1)*ErrorH;
			}
			
		printf("\nnew lower border is %.9lf\t",lowerX);
		printf("f(Xl)= %.9lf\t",function(lowerX,f,N));	 
		printf("\nnew upper border is %.9lf\t",upperX);
		printf("f(Xu)= %.9lf\t",function(upperX,f,N));	 	 
		printf("\nnew middle value is %.9lf\t",midX);
		printf("f(Xr)= %.9lf\t",function(midX,f,N));	 
		printf("\ncalculated error is %.9lf",ErrorH);
		printf("\nwanted error is %.9lf",ErrorA);
		printf("\n\n");
		
		//i'm making it slow to show the steps
		Sleep(1000);
	    	}while((ErrorH>ErrorA)&&cont==0);
	
	
	printf("The root between the borders you gave is %lf.", midX);
	printf("\n\n it took %d steps to find the root",s);
	return 0;
}


/*double function(double x){
	 
		double res; 
		 res=power(x,2)-(x*2)-3;

return res;
}*/

double function(double x, double p[], int num){
	double sum;
	int i;
	sum=0;
	for(i=0;i<=num;i++){
		sum=sum+(p[i]*(pow(x,(num-i))));
		}
	return sum;
	}

