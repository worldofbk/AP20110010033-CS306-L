integer [-+]?[0-9]*
float [-+]?[0-9]*\.[0-9]*|[-+]?[0-9]*\.[0-9]*e[-+][0-9]*
id [a-zA-Z][a-zA-Z0-9]*
keyword int|float|char|return|for|if|else|while|break|continue
relop <|>|<=|>=|==|!=

%{
    #include <stdio.h>

    void store_symb_tab(char *id);

    char symb_tab[50][20];
    int idx = 0;
%}

%%

{keyword} {fprintf(yyout, "%s - is a keyword\n", yytext);}
{id} {fprintf(yyout, "%s - is an identifier\n", yytext); store_symb_tab(yytext);}
{integer} {fprintf(yyout, "%s - is an integer\n", yytext);}
{float} {fprintf(yyout, "%s - is a float\n", yytext);}
{relop} {fprintf(yyout, "%s - is a relational operator\n", yytext);}
= {fprintf(yyout, "%s - is the assignment operator\n", yytext);}
"//".*\n {fprintf(yyout, "%s - is a single-line comment\n", yytext);}
"/*"[^*/]*"*/" {fprintf(yyout, "%s - is a multi-line-comment\n", yytext);}
.

%%

int main() {
    extern FILE *yyin, *yyout;
    yyin = fopen("input.txt", "r");
    yyout = fopen("output.txt", "w");
    yylex();
    fclose(yyin);
    fclose(yyout);
    return 0;
}

void store_symb_tab(char *id)
{
    int flag = 0, i;
    for (i = 0; i < idx; i++)
    {
        if (strcmp(id, symb_tab[i]) == 0)
        {
            printf("%s - already in symbol table\n", id);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("%s - stored in symbol table\n", id);
        strcpy(symb_tab[idx], id);
        idx++;
    }
}

int yywrap() {
    return 1;
}