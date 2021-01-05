/*Lex program to recognize all strings which do not contain first 4 characters of my name as substring*/
%{
%}

/*Rule Section*/
%%
[a-zA-Z0-9]*[hH]+[aA]+[rR]+[iI]+[a-zA-Z0-9]* {fprintf(yyout,"");}
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