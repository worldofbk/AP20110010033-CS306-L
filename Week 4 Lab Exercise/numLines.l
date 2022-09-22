%{
	int num_lines=0;
	char *c;
%}

%%
[\n] {++num_lines; c = yytext;}
.
%%

int main()
{
	yylex();
	printf("no of lines = %d\n", num_lines);
}
int yywrap()
{
	return 1;
}