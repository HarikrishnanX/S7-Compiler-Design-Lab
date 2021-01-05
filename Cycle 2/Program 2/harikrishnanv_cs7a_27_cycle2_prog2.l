/*Lex program to remove white spaces,tabs and comments from a C program file*/
%{
%}

start \/\*
end \*\/

/*Rule Section*/
%%
\/\/(.*) ;
{start}.*{end} ;
[ \t]+ {fprintf(yyout,"");}
.       { fprintf(yyout,"%s",yytext); }
%%

int yywrap(){}

/*Driver Code*/
int main()
{
    extern FILE *yyin,*yyout;
    yyin=fopen("input.txt","r");
    yyout=fopen("output.txt","w");
    yylex();
    return 0;
}