%{
    #include "harikrishnanv_cs7a_27_cycle2_prog4.tab.h"
%}
%%
[0-9]+ {return Digit;}
[a-zA-Z][a-zA-Z0-9]*+ {return Letter;}
[ \t] {;}
\n {return 0;}
. {return yytext[0];}
%%
int yywrap()
{
    return 1;
}