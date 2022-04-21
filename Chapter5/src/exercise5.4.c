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
    int sizet;

    for (; *sp != '\0'; sp++) /* progress sp to end of string */
        ;
    for (sizet = 0; *tp != '\0'; tp++) /* progress tp to end of string, and get size of t string. */
        sizet++;

    while (*sp-- == *tp-- && sizet > 0)
        sizet--;

    return (sizet == 0);  /* returns 1 if sp and tp where reversed back sizet times, otherwise 0. */
}