#include <stdio.h>
#include <math.h> /* for atof_custom */
#include <stdlib.h>
#include <ctype.h>

#define BUFSIZE 100
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /* max depth of val stack */

int getop (char []);
void push (double);
double pop (void);
int my_getch(void);
void my_ungetch (int);
int exercise4_3_8();