#include "../include/exercise5.1.h"

/* getint: get next integer from input into *pn */
int getint(int *pn){
    int c, sign;
    while (isspace(c = getc(stdin))) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetc(c, stdin); /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c== '+' || c == '-')
        c = getc(stdin);
    for (*pn = 0; isdigit(c); c = getc(stdin))
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetc(c, stdin);
    return c;
}

int exercise5_1(){
    int i, n, array[SIZE];
    printf("Exercise 5.1\n");
    for (n = 0;  n < SIZE && getint(&array[n]) != EOF; n++)
        ;
    for (i = 0; i < SIZE && *(array+i) != '\0'; i++) {
        printf("array[%d]: %d\n", i, *(array+i));
    }
    return 0;
}