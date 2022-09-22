%{
	#include<stdio.h>
%}

%%
[aeiouAEIOU] {printf("%s is vowel\n", yytext);}
[a-zA-Z] {printf("%s is consonant\n", yytext);}
. {printf("%s is invalid lexeme", yytext);}
%%

int main()
{
	yylex();
	return 0;
}

int yywrap()
{
	return 1;
}