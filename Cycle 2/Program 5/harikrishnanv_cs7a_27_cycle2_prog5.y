%{ 
  #include<stdio.h> 
  int flag=0; 
%} 
%token Number 
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%% 
ArithmeticExpression: E{ 
                            printf("\nResult=%d\n", $$); 
                            return 0; 
                        }; 
 E:E'+'E {$$=$1+$3;}  
  |E'-'E {$$=$1-$3;} 
  |E'*'E {$$=$1*$3;} 
  |E'/'E {$$=$1/$3;} 
  |E'%'E {$$=$1%$3;} 
  |'('E')' {$$=$2;} 
  | Number {$$=$1;} 
  ; 
%%
void main() 
{ 
   printf("\nEnter Any Arithmetic Expression having operations +,-,*,/,Mod,(,):"); 
   yyparse(); 
   if(flag==0) 
   {
       printf("\nArithmetic Expression is Valid\n\n"); 
   }
} 
  
void yyerror() 
{ 
   printf("\nArithmetic Expression is Invalid!!\n\n"); 
   flag=1; 
} 