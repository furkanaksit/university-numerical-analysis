#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

double function(double x);

int main(int argc, char **argv)
{
	

	int s;
	double firstX,secondX,ErrorA,ErrorH;
		
	printf("give the approximate error= ");
	scanf("%lf",&ErrorA);

	printf("give the starting value of x= ");
	scanf("%lf",&firstX);
	
	if(function(firstX)==0){
		 printf("starting value is a root");
		 }	
	printf("\n\n starting to calculations\n\n");
	s=0;
	do{ 
		s=s+1;
		secondX=function(firstX);
		ErrorH=((secondX-firstX)/secondX)*100;
		if(ErrorH<0){ErrorH=(-1)*ErrorH;
			}
				
		printf("firstX= %.9lf\t",firstX);
		printf("secondX =f(%.9lf)= %.9lf\t",firstX,secondX);
		printf("ErrorH= %.9lf",ErrorH);
		printf("\n\n");
		
		firstX=secondX;
		
		//i'm making it slow to show the steps
		Sleep(1000);
	    	}while(ErrorH>ErrorA);
	
	
	printf("The root between the borders you gave is %.9lf.", firstX);
	printf("\n\n it took %d steps to find the root",s);
	return 0;
}


double function(double x){
//put our function here 
//f(x)=e^(-x)-x   -----> x=e^(-x) that means next x equals e^(-x)
//*********************		 
		double res; 
		 res=exp(-x);

return res;
}
