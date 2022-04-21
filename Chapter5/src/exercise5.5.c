#include "../include/exercise5.5.h"

int exercise5_5(){
    int n = 6;
    char s[100] = "0123456789", t[] = "6666666666";
    char *cpy, *cat;
    int cmp;
    printf("string source: '%s', target: '%s'\n", s, t);
    printf("calling strncpy('%s', '%s', %d).\n", s, t, 2);
    cpy = strncpyVersion(s, t, 2);
    printf("result: '%s'\n", cpy);
    printf("calling strncat('%s', '%s', %d).\n", s, t, 4);
    cat = strncatVersion(s, t, 4);
    printf("result: '%s'\n", cat);
    printf("calling strncmp('%s', '%s', %d).\n", s, t, 5);
    cmp = strncmpVersion(s, t, 5);
    printf("result: %d\n", cmp);
    return 0;
}
/* copy at most n characters of string ct to string s. return s. */
char *strncpyVersion(char *s, char *ct, int n){
    char *ps = s, *pct = ct;
    while(n-- > 0 && (*ps++ = *pct++) != '\0')
        ;
    while (n-- > 0)
        *ps = '\0';
    return s;
}
/* copy at most n characters of string ct to end of string s. return s. */
char *strncatVersion(char *s, char *ct, int n){
    char *ps = s;
    strncpyVersion(ps + strlen(ps), ct, n);
    return s;
}
/* compare at most n characters of string cs to string ct.
 * return <0 if cs<ct, 0 if cs==ct, or >0 if cs>ct. */
int strncmpVersion(char *cs, char *ct, int n){
    char *ps = cs, *pct = ct;
    while (n > 0 && *ps == *pct) {
        n--;
        ps++;
        pct++;
    }
    if (n == 0)
        return 0;
    return *ps - *pct;
}