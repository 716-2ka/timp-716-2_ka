#include <stdio.h> 
#include <math.h>
int main(void) 
{ 
	double n,x,summ; 
	summ=0; 
	scanf("%lf",&n); 
	for (double i=1;i<=n;i++)
	{ 
		scanf("%lf", &x); 
		summ=summ+pow(-1,i)*x*x; 
	} 
	printf("%lf\n",summ); 
	return 0; 
}
