%{
int i=0;

/*
Title: Count No. of words using lex

Input File:
Hello World.

Output:
No. of words: 2

*/
%}

%%

[" "]|[.] {i++;}

%%

int main(){
yyin = fopen("in.txt", "r");
yylex();
printf("\nNo. of words: %d\n", i);
return 0;
}

int yywrap(){
return 1;
}