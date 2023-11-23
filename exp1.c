//Program: Lexical Analyzer using C

#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct IdentifierEntry {
  int serialNo;
  char token[100];
};

struct IdentifierEntry identifierTable[100];
int tableSize = 0;

void printTable() {
  printf("\n");
  printf("%-15s%-15s\n", "ID", "Token");
  for (int i = 0; i < tableSize; i++) {
    printf("%-15d%-15s\n", identifierTable[i].serialNo,
           identifierTable[i].token);
  }
}

int isTokenInTable(char *token) {
  for (int i = 0; i < tableSize; i++) {
    if (strcmp(identifierTable[i].token, token) == 0) {
      return 1;
    }
  }
  return 0;
}

void addToTable(char *token) {
  if (!isTokenInTable(token)) {
    struct IdentifierEntry entry;
    entry.serialNo = tableSize + 1;
    strcpy(entry.token, token);
    identifierTable[tableSize++] = entry;
  }
}

void extractAndPrintIdentifier(char *input, int *f) {
  int lb = *f;
  while (isalnum(input[*f])) {
    (*f)++;
  }
  char identifier[*f - lb + 1];
  strncpy(identifier, input + lb, *f - lb);
  identifier[*f - lb] = '\0';
  printf("Identifier '%s' recognized\n", identifier);
  addToTable(identifier);
}

void extractAndPrintNumber(char *input, int *f) {
  int lb = *f;
  while (isdigit(input[*f]) || input[*f] == '.') {
    (*f)++;
  }
  char number[*f - lb + 1];
  strncpy(number, input + lb, *f - lb);
  number[*f - lb] = '\0';
  printf("Number '%s' recognized\n", number);
}

int main() {
  char input[100];
  int i, lb, f = 0;
  printf("Enter the input:");
  fgets(input, 100, stdin);
  int length = strlen(input) - 1;

  while (f < length) {

    goto state0;

  state0:
    if (input[f] == ' ' || input[f] == ',') {
      f++;
      continue;
    } else if (input[f] == ';') {
      f++;
      printTable();
    } else if (input[f] == 'i') {
      if (input[f + 1] == ' ') {
        f++;
        printf("Identifier 'i' recognized\n");
        addToTable("i");
      } else {
        f++;
        goto state1;
      }
    } else if (input[f] == 'd') {
      if (input[f + 1] == ' ') {
        f++;
        printf("Identifier 'd' recognized\n");
        addToTable("d");
      } else {
        f++;
        goto state3;
      }
    } else if (input[f] == 'f') {
      if (input[f + 1] == ' ') {
        f++;
        printf("Identifier 'f' recognized\n");
        addToTable("f");
      } else {
        f++;
        goto state4;
      }
    } else if (isalpha(input[f])) {
      extractAndPrintIdentifier(input, &f);
    } else if (input[f] == '>') {
      if (input[f + 1] == '=') {
        f++;
        goto state9;
      } else {
        f++;
        printf("Relop '>' recognized\n");
      }
    } else if (input[f] == '<') {
      if (input[f + 1] == '=') {
        f++;
        goto state10;
      } else {
        f++;
        printf("Relop '<' recognized\n");
      }
    } else if (input[f] == '=') {
      if (input[f + 1] == '=') {
        f++;
        goto state11;
      } else {
        f++;
        printf("Assignment Operator '=' recognized\n");
      }
    } else if (isdigit(input[f])) {
      extractAndPrintNumber(input, &f);
    }
  state1:
    if (input[f] == 'f' && input[f + 1] == ' ') {
      f++;
      printf("Keyword 'if' recognized\n");
      continue;
    } else if (input[f] == 'n') {
      f++;
      goto state2;
    } else if (isalnum(input[f])) {
      f = f - 1;
      extractAndPrintIdentifier(input, &f);
      continue;
    }

  state2:
    if (input[f] == 't' && input[f + 1] == ' ') {
      f++;
      printf("Keyword 'int' recognized\n");
      continue;
    } else if (isalnum(input[f])) {
      f = f - 2;
      extractAndPrintIdentifier(input, &f);
      continue;
    }

  state3:
    if (input[f] == 'o' && input[f + 1] == ' ') {
      f++;
      printf("Keyword 'do' recognized\n");
      continue;
    } else if (isalnum(input[f])) {
      f = f - 1;
      extractAndPrintIdentifier(input, &f);
      continue;
    }

  state4:
    if (input[f] == 'o') {
      f++;
      goto state5;
    } else if (input[f] == 'l') {
      f++;
      goto state6;
    } else if (isalnum(input[f])) {
      f = f - 1;
      extractAndPrintIdentifier(input, &f);
      continue;
    }

  state5:
    if (input[f] == 'r' && input[f + 1] == ' ') {
      f++;
      printf("Keyword 'for' recognized\n");
      continue;
    } else if (isalnum(input[f])) {
      f = f - 2;
      extractAndPrintIdentifier(input, &f);
      continue;
    }

  state6:
    if (input[f] == 'o') {
      f++;
      goto state7;
    } else if (isalnum(input[f])) {
      f = f - 2;
      extractAndPrintIdentifier(input, &f);
      continue;
    }

  state7:
    if (input[f] == 'a') {
      f++;
      goto state8;
    } else if (isalnum(input[f])) {
      f = f - 3;
      extractAndPrintIdentifier(input, &f);
      continue;
    }

  state8:
    if (input[f] == 't' && input[f + 1] == ' ') {
      f++;
      printf("Keyword 'float' recognized\n");
      continue;
    } else if (isalnum(input[f])) {
      f = f - 4;
      extractAndPrintIdentifier(input, &f);
      continue;
    }
  state9:
    if (input[f] == '=') {
      f++;
      printf("Relop '>=' recognized\n");
      continue;
    }
  state10:
    if (input[f] == '=') {
      f++;
      printf("Relop '<=' recognized\n");
      continue;
    }
  state11:
    if (input[f] == '=') {
      f++;
      printf("Relop '==' recognized\n");
      continue;
    }
  }
  return 0;
}

/*
Output:
Enter the input:int a = 5, b;
Keyword 'int' recognized
Identifier 'a' recognized
Assignment Operator '=' recognized
Number '5' recognized
Identifier 'b' recognized

ID             Token
1              a
2              b
*/
