#include "../include/exercise5.3.h"

int exercise5_3(){
    printf("exercise 5.3\n");
    char s[] = "the", t[] = "batman";
    printf("calling strcatp on s: %s, t: %s\n", s , t);
    strcatp(s, t);
    printf("result s: %s\n", s);
    return 0;
}

void strcatp(char s[], char t[]){
    char *sp = s;
    char *tp = t;
    while (*sp++ != '\0')
        ;
    sp--;
    while ((*sp++ = *tp++) != '\0'){
        ;
    }
}