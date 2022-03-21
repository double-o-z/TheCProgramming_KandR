#include <stdio.h>

/* print Fahrenheit-Celsius table */

main(){
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	printf("Fahr Celsius\n");
	while (fahr <= upper) {
		celsius = (5/9.0) * (fahr-32);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
