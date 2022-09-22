%{
    #include <stdio.h>
%}

%%

.*000.* {printf("Accepted\n");}
.* {printf("Not Accepted\n");}

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}