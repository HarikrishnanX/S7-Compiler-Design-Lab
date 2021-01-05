%{
    #include<stdio.h>
    int valid=1;
%}
%token Digit Letter
%%
stmt:A
     ;
A: Letter B

B: Letter B
 | Digit B
 |
 ;
%%
int yyerror()
{
    printf("\nInvalid Variable!!");
    valid=0;
    return 0;
}
void main()
{
    printf("Enter the Variable:");
    yyparse();
    if(valid)
    {
        printf("\nValid Variable");
    }
}
