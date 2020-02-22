#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>


double derfunc(double x);
double power(double num1,double num2);
double function(double x);

int main(int argc, char **argv)
{
	

	int s;
	double Xs,Xo,Xi,ErrorA,ErrorH;
		
	printf("give the approximate error= ");
	scanf("%lf",&ErrorA);

	printf("give the starting value of x(i-1)= ");
	scanf("%lf",&Xi);
	printf("give the starting value of x(i)= ");
	scanf("%lf",&Xo);
	
	printf("\n\n starting to calculations\n\n");
	s=0;
	do{ 
		s=s+1;
		Xs=Xo-((function(Xo)*(Xi-Xo))/(function(Xi)-function(Xo)));
		
		ErrorH=((Xs-Xo)/Xs)*100;
		if(ErrorH<0){ErrorH=(-1)*ErrorH;
			}
				
		printf("X(i-1)= %.9lf\t",Xi);
		printf("X(i)= %.9lf",Xo);
		printf("X(i+1)= %.9lf",Xs);
		printf("\tErrorH= %.9lf",ErrorH);
		printf("\n\n");
		
		Xi=Xo;
		Xo=Xs;
		
		//i'm making it slow to show the steps
		Sleep(750);
	    	}while(ErrorH>ErrorA);
	
	
	printf("The root between the borders you gave is %.9lf.", Xs);
	printf("\n\n it took %d steps to find the root",s);
	return 0;
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

double function(double x){
//put our function here 
//f(x)=x^2-2*x-3  
//*********************		 
		double res; 
		res=(-3)*power(x,3)-2*power(x,2)-8*x+1;

return res;
}

