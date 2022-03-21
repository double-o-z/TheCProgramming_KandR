#include <stdio.h>

main(){
	float fahr, celsius;
	int lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;
	fahr = lower;
	while (fahr <= upper)
	{
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf ("%d, %3.1f, %6.1f\n", fahr, celsius);
		/* change of format */
		fahr = fahr + step;
	}
}
