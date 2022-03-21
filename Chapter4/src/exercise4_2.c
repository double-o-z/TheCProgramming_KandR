#include "exercise4_2.h"

double atof_custom(char s[]){
    double val, power, exponent;
    int i, sign, e_sign, j;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (tolower(s[i++]) == 'e' && ((e_sign = s[i++]) == '+' || e_sign == '-') && isdigit(s[i])){
        for (j = s[i]-'0', exponent = 1.0; j > 0; j--)
            exponent *= 10.0;
        if (e_sign == '+')
            power /= exponent;
        else
            power *= exponent;
    }
    return sign * val / power;
}

int exercise4_2(){
    sum = 0;
    printf("Input lines of doubles, with exponent.\n");
    while (getline_f(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof_custom(line));
    return 0;
}
