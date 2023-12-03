// Program: Recursive Descent Parser

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[100];
int i = 0, error = 0;

/*
Grammar:
  L = {a^2n b^m | n, m >= 0}

  S -> aaAB
  A -> aaA | ε
  B -> bB | ε
*/

void A() {
  if (str[i] == 'a' && str[i + 1] == 'a') {
    i += 2;
    A();
  }
}

void B() {
  if (str[i] == 'b') {
    i++;
    B();
  }
}

void S() {
  A();
  B();
  if (str[i] == '$') {
    error = 0;
  } else {
    error = 1;
  }
}

int main() {
  printf("Enter a string: ");
  scanf("%s", str);

  S();

  if (str[i] == '$' && error == 0)
    printf("String is accepted\n");
  else
    printf("String is not accepted\n");

  return 0;
}

/*
Output:

Enter a string: aaaabb$
String is accepted

Enter a string: aab$
String is accepted

Enter a string: ab$
String is not accepted
*/
