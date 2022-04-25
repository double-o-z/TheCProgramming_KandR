#include "../include/exercise5.10.h"

int sp = 0; /* next free stack position */
double val [MAXVAL]; /* value stack */
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
double t; /* varialbe for top element */

/* push: push f onto value stack */
void push (double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf ("Error: stack is full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return (val[--sp]);
    else
    {
        printf ("Error: stack empty\n");
        return 0.0;
    }
}

/* top: print top element without poping it. */
double top(){
    t = '\0';
    if (sp > 0){
        t = val[--sp];
        sp++;
        printf("\t%.8g\n", t);
    }
    else
        printf ("Error: stack empty\n");
    return t;
}

/* duplicate: print top element, then push a copy of it. */
void duplicate(){
    t = top();
    if (t != '\0')
        push(t);
}

/* swap: swap top two elements (if they exist), and print them. */
void swap(){
    if (sp > 1){
        sp -= 2;
        t = val[sp];
        printf("\t%.8g ", (val[sp] = val[++sp]));
        printf("%.8g\n", (val[sp++] = t));
    }
    else
        printf ("Error: stack doesn't contain two elements.\n");
}

/* clear: clears the stack. */
void clear(){
    sp = 0;
    val[sp] = '\0';
    printf ("Stack is cleared.\n");
}

/* getop: get next operator or numeric operand */
int getop (char s[])
{
    int i, c;
    while ((s[0] = c = my_getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = my_getch()))
            ;
    if (c == '-')
    {
        while (isdigit(s[++i] = c = my_getch()))
            ;
        if (i == 1 && c != '.') /* minus sign alone */
        {
            my_ungetch(c);
            return '-';
        }
    }
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = my_getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        my_ungetch (c);
    return NUMBER;
}

int my_getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0 ? buf[--bufp] : getchar());
}

void my_ungetch (int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf ("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int exercise5_10(int argc, char *argv[]){
    int i;
    printf("argc: %d\n", argc);
    for (i = 1; argc > 0; argc--, i++) {
        printf("argv[%d]: %s\n", i, *argv++);
    }
    return 0;
}

int exercise5_10B() /* reverse Polish calculator */
{
    int type;
    double op2;
    char s[MAXOP];
    char last_type;
    while((type = getop(s)) != EOF){
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("Error: zero devisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int) pop() % (int) op2);
                else
                    printf("Error: zero devisor\n");
                break;
            case '\n':
                if (last_type != 't' && last_type != 'd' && last_type != 's' && last_type != 'c')
                    printf("\t%.8g\n", pop());
                break;
            case 't':  /* print top element */
                (void) top();
                break;
            case 'd': /* duplicate top element */
                duplicate();
                break;
            case 's': /* swap top two elemnts */
                swap();
                break;
            case 'c': /* clear stack */
                clear();
                break;
            default:
                printf("Error: unknown command\n");
                break;
        }
        last_type = type;
    }

    return 0;
}