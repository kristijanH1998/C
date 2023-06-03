#include <stdio.h>
#include <stdlib.h> /* for atof() */
#define MAXOP 100 /* max size of operand or operator */
//#define NUMBER '0' /* signal that a number was found */
int getop(char []);
void push(double);
double pop(void);
void peek(void);
void clear(void);
int main(void){
	int type;
    double op2;
	double op3;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case '0':
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
                push((int) pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
			case '%':
			op2 = pop();
			if (op2 != 0)
				push ((int) pop() % (int) op2);
			else
				printf("error: zero divisor\n");
			break;
			case 't':
				peek();
			break;
			case 'd':
				push (pop() * 2.0);
			break;
            case '\n':
            	printf("\t%.8g\n", pop());
            break;
			case 's':
				op2 = pop();
				op3 = pop();
				push(op2);
				push(op3);
			break;
			case 'c':
				clear();
			break;
            default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
}
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void clear(void)
{
	if (sp > 0){
		while (sp > 0){
			val[sp - 1] = 0.0;
			sp--;
		}
	}
	else
	{
		printf("Stack is already empty\n");
	}
}

void peek(void)
{
	if(sp > 0)
        printf("The top element is: %f\n", val[sp-1]);
    else
    {
        printf("error: stack empty\n");
    }
}

void push(double f)
{
    if(sp < MAXVAL)
        val[sp++]=f;
    else
        printf("error:stack full, cant push %g\n",f);
}

double pop(void)
{
    if(sp>0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include<ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i,c;

    while((s[0] = c = getch()) == ' ' || c =='\t')
        ;
    s[1] = '\0';
    
    i = 0;
    if(!isdigit(c) && c!='.' && c!='-')
        return c;

    if(c=='-')
        if(isdigit(c=getch()) || c == '.')
            s[++i]=c;
        else
        {
            if(c!=EOF)
                ungetch(c);
            return '-';
        }
    
    if(isdigit(c))
        while(isdigit(s[++i] =c =getch()))
            ;

    if(c=='.')
        while(isdigit(s[++i] = c=getch()))
            ;
    
    s[i] = '\0';
    if(c!=EOF)
        ungetch(c);
    return '0';
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}