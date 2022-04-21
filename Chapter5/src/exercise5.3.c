#include "../include/exercise5.3.h"

int exercise5_3(){
    char s[] = "the", t[] = " batman";
    char *result;
    printf("exercise 5.3\n");
    printf("calling strcatp on s: '%s', t: '%s'\n", s , t);
    result = strcatp(s, t);
    printf("result: \n'");
    for (; *result != '\0'; result++) {
        putchar(*result);
    }
    printf("'\n");
    return 0;
}

char *strcatp(char *s, char *t){
    char *keep = s;
    while (*s != '\0')
        s++;
    while ((*s++ = *t++) != '\0')
        ;
    return keep;
}