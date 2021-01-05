%{ 
  #include<stdio.h> 
  #include "harikrishnanv_cs7a_27_cycle2_prog5.tab.h" 
  extern int yylval; 
%} 
%% 
[0-9]+ { 
          yylval=atoi(yytext); 
          return Number; 
       } 
[\t] ; 
[\n] return 0; 
. return yytext[0]; 
%% 
int yywrap() 
{ 
 return 1; 
} 