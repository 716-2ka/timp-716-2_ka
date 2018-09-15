#include <stdio.h> 
int main(void) 
{ 
	double n,x,z;  
	z=0;
	scanf("%lf",&n); 
	for (double i=1;i<=n;i++)
	{ 
		scanf("%lf", &x); 
		if(x<=0)
		z=z+1; 
	} 
	printf("%lf\n",z); 
	return 0; 
}
