#include "../include/exercise5.4.h"

int exercise5_4(){
    int result;
    char s[] = "the batman", t[] = "batman";
    printf("exercise 5.4\n");
    printf("calling strend on s: %s, t: %s\n", s , t);
    result = strend(s, t);
    printf("result: %d\n", result);
    return result;
}

int strend(char s[], char t[]){
    char *sp = s;
    char *tp = t;
    while (*sp++ != '\0')
        ;
    sp--;
    while ((*sp++ = *tp++) != '\0'){
        ;
    }
    return 0;
}