%{
    #include <stdio.h>
    int l = 1;
%}

%%

[\n] {fprintf(yyout, "\n%d ", ++l);}
. {fprintf(yyout, "%s", yytext);}

%%

int main() {
    extern FILE *yyin, *yyout;
    yyin = fopen("input.txt", "r");
    yyout = fopen("output.txt", "w");
    fprintf(yyout, "1 ");
    yylex();
    fclose(yyin);
    fclose(yyout);
    return 0;
}

int yywrap() {
    return 1;
}