**Commands to run the respective files:**

***c program:***

gcc filename.c

./a.out

***lex program:***

flex filename.l

gcc lex.yy.c

./a.out

***yacc program:***

*in replit:*

yacc -d filename.y

flex filename.l

gcc lex.yy.c y.tab.c -lfl

./a.out

*in pc:*

yacc -d filename.y

lex filename.l

cc lex.yy.c y.tab.c -ll
./a.out
