#include <stdio.h>

/* print Fahrenheit-Celsius table */
int fahr_to_celsius(int fahr);

int main(){
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	printf("Fahr Celsius\n");
	while (fahr <= upper) {
		celsius = fahr_to_celsius(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}

int fahr_to_celsius(int fahr){
	int celsius;
	celsius = (5/9.0) * (fahr-32);
	return celsius;
}
