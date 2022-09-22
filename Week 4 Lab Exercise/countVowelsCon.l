%{
  int v=0,c=0;
%}

%%
[aeiouAEIOU] ++v;
[a-zA-Z] ++c;
[\n] {
  printf("vowels are : %d\n",v);
  printf("consonants are :%d\n",c);
  v=0;
  c=0;
}
.
%%
main()
{
  yylex();
  
}
int yywrap()
{
 return 1;
}