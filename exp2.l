%{

/*
Program: Lexical Analyzer using Lex Tool

Three Parts of the Lex File: Declaration, Translation Rules & Auxiliary Procedure

Input File:
int a = 5, b;

Output:
int => Keyword
  => Space
a => Identifier
  => Space
= => Operator
  => Space
5 => Number
, => Symbol
  => Space
b => Identifier
; => Symbol
*/

%}

%%

if|int|for|float|char|return {printf("\n%s => Keyword\n", yytext);}
[a-zA-Z][a-zA-Z0-9]* {printf("\n%s => Identifier\n", yytext);}
[0-9]+|[-][0-9]+ {printf("\n%s => Number\n", yytext);}
[>|<|>=|<=|==|=|+|-|/|x] {printf("\n%s => Operator\n", yytext);}
'[^']*' { printf("\n%s\n => Literal\n", yytext); }
[" "] {printf("\n%s => Space\n", yytext);}
[{|}|,|(|)|[|]|;|] {printf("\n%s => Symbol\n", yytext);}
.|\n {ECHO;}

%%

int main(){
yyin = fopen("input.txt", "r");
yylex();
return 0;
}

int yywrap(){
return 1;
}
