%{
int j=0;

/*
Title: Count No. of vowels using lex

Input File:
Hello World.

Output:
No. of vowels: 3

*/
%}

%%

[a|e|i|o|u|A|E|I|O|U] {j++;}

%%

int main(){
yyin = fopen("in.txt", "r");
yylex();
printf("\nNo. of vowels: %d\n", j);
return 0;
}

int yywrap(){
return 1;
}