  
%{
#include "harikrishnanv_cs7a_27_cycle2_prog7.tab.h"
%}
num	[0-9]+
id	[a-zA-Z]+
bop	=|<|>|!=|<=|>=|==|&&|"||"|[+-/*]
uop	"++"|"--"
%%
"for"	{return FOR;}
{bop}	{return BOP;}
{uop}	{return UOP;}
{num}	{return NUMBER;}
{id}	{return ID;}
[ \t]	{;}
[\n]    {return 0;} 
.	{return yytext[0];}
%%
int yywrap()
{
    return 1;
}