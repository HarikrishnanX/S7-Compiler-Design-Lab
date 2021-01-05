%{
#include<stdio.h>
%}
%token FOR ID BOP UOP NUMBER
%%
prg: FOR '(' lexp ';' lexp ';' lexp ')' lbody 	{printf("Valid For Loop");}
   ;
lbody: stmt
     | codeblock
     ;
codeblock:'{' stmt_list '}'
         ;
stmt_list: stmt_list stmt
         |
         ;
stmt: lexp ';'
    ;
lexp: fexp			
    |				
    ;
fexp: fexp ',' exp		
    |exp
    |'(' fexp ')'			
    ;
exp: ID BOP exp			
   | ID UOP			
   | UOP ID
   | ID
   | NUMBER
   ;
%%
int main()
{
yyparse();
}
yyerror(char *s)
{
printf("Error!!");
}