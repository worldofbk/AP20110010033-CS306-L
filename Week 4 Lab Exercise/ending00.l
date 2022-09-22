%{
    #include <stdio.h>
%}

%%

.*00 {printf("Accepted\n");}
.* {printf("Not Accepted\n");}

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}