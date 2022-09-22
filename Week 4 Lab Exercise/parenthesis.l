%{
/* Checking if it is a well formed paranthesis or not */
/* Give the input file name as a command line argument */

int flag=0;
char text[100];
int i = 0;

%}

%%

"(" {flag++; text[i++] = yytext[0];}

")" { flag--; text[i++] = yytext[0];}

[\n] {
    text[i] = '\0';
    i = 0;
	if(flag==0)
		printf("\n%s - Well-formed parenthesis\n\n", text);
	else
		printf("\n%s - Not well-formed parenthesis\n\n", text);
}

. {text[i++] = yytext[0];}

%%

int main(int argc, char *argv[])
{	
	yyin=fopen(argv[1],"r+");
	yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
Footer
© 2022 GitHub, Inc.