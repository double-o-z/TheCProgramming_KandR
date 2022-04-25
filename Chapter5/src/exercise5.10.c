#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define STK_SIZE 20
static int stk_ptr = 0;
static int stack[STK_SIZE]; /* stack and stack pointer */
void push (int val)
{
    if (stk_ptr >= STK_SIZE)
    {
        printf ("push: stack overflow\n");
        exit (1);
    }
    else
        stack[stk_ptr++] = val;
}
int pop(void)
{
    if (stk_ptr <= 0)
    {
        printf("pop: stack underflow\n");
        exit(2);
    }
    return(stack[--stk_ptr]);
}
int main (int argc, char *argv[])
{
    int i;
    int tmp;
    if (argc == 1) /* no arguments */
    return (0);
    for (i = 1; i < argc; i++){
        printf("argv[%d]: %c\n", i, *argv[i]);
        if (isdigit(*argv[i]))
            push(atoi(argv[i]));
        else
            switch(*argv[i])
            {
                case '+':
                    push (pop( ) + pop( ));
                    break;
                case 'x':
                    push (pop( ) * pop( ));
                    break;
                case '-':
                    tmp = pop( );
                    push (pop( ) - tmp);
                    break;
                case '/':
                    tmp = pop( );
                    push (pop( ) / tmp);
                    break;
                case ' ':
                    break;
                default:
                    printf ("Unknown operator %c\n", *argv[i]);
                    break;
            }
    }

    printf ("%d\n", pop( ));
    return 0;
}