%{
#include<stdio.h>
int flag = 0;
%}

%token LABEL OPR MACRO OP COMMA END START MEND NUM
%%
A : LABEL START LABEL B LABEL END LABEL
//X : LABEL F C
//F : OP | MACRO | LABEL
B : C | B C
C : LABEL OP D | LABEL LABEL COMMA | E
D : LABEL  | OPR  | NUM  | COMMA 
E : LABEL MACRO COMMA B LABEL MEND LABEL | LABEL MACRO LABEL B LABEL MEND LABEL | LABEL MACRO NUM B LABEL MEND LABEL
%%

int main() 
{
printf("enter the string\n");
yyparse();
if ( flag == 0)
        {
                printf("valid\n");
                exit(0);
        }
else
        {
                printf("invalid\n");
                exit(0);
        }
return 0;
}

int yyerror()
{
flag =1;

}
