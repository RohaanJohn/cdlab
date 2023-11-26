
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[100];
int ip = 0;

char postfix[100];
int pi = 0;

char stack[100];
int tos = -1;

char ti = '1';

void push(char c) {
	stack[++tos] = c;
}

char pop() {
	return stack[tos--];
}

char top() {
	return stack[tos];
}

int prec(char c) {
	switch (c) {
		case '(':
			return 0;
	
		case '/':
		case '*':
			return 3;
	
		case '+':
		case '-':
			return 2;
			
		case ')':
			return 1;
	}
	
	return -1;
} 

int isop(char c) {
	return prec(c) != -1;
}

int main() {
	printf("enter string: ");
	scanf("%s", input);
	
	int len = strlen(input);
	input[len++] = ')';
	
	push('(');
	
	while (ip < len) {
		char ic = input[ip];
	
		if (isop(ic)) {
			while (ic != '(' && tos > -1 && prec(ic) <= prec(top())) {
				char c = pop();
				postfix[pi++] = c;
			}
			ic == ')' ? pop() : push(ic);
		}
		else {
			postfix[pi++] = ic;
		}
		ip++;
	}
	
	int ci = 0;
	
	printf("\nIntermediate code\t\t\top\top1\top2\tres\n");
	
	while (ci < pi) {
		char pc = postfix[ci];
	
		if (isop(pc)) {
			char b = pop();
			char a = pop();
			
			printf("t%c = ", ti);
			isdigit(a) ? printf("t%c", a) : printf("%c", a);
			printf(" %c ", pc);
			isdigit(b) ? printf("t%c", b) : printf("%c", b);
			
			printf("\t\t\t\t");			
			printf("%c\t", pc);
			isdigit(a) ? printf("t%c\t", a) : printf("%c\t", a);
			isdigit(b) ? printf("t%c\t", b) : printf("%c\t", b);
			printf("t%c\n", ti);
			
			printf("\n");
			
			push(ti);
			
			ti++;
		}
		
		else {
			push(pc);
		}
		
		ci++;
	}
	
	return 0;
}


/*
OUTPUT
    
enter string: (a+b)*(b+c)

Intermediate code                       op      op1     op2     res
t1 = a + b                              +       a       b       t1

t2 = b + c                              +       b       c       t2

t3 = t1 * t2                            *       t1      t2      t3

*/
