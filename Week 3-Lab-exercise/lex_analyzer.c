#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

int size = 0;

char keywords[30][30] = {"int", "while", "break", "for", "do", "if", "float", "char", "switch", "double", "short", "long", "unsigned", "sizeof", "else", "register", "extern", "static", "auto", "case", "break", "volatile", "enum", "typedef"};

char id[20], num[10], op[5];

char symbol_table[50][20];
int idx = 0;

int check_keyword(char s[])
{
    int i;
    for (i = 0; i < 24; i++)
        if (strcmp(s, keywords[i]) == 0)
            return 1;
    return 0;
}

void store_symb_tab(char id[], char symb_tab[][20])
{
    int flag = 0, i;
    for (i = 0; i < idx; i++)
    {
        if (strcmp(id, symb_tab[i]) == 0)
        {
            flag = 1;
        }
    }
    if (flag == 0)
    {
        strcpy(symb_tab[idx], id);
        idx++;
    }
}

void main()
{
    FILE *fileptr1, *fileptr2;
    char c;
    int state = 0;
    int i = 0, j = 0, k = 0;
    fileptr1 = fopen("source.txt", "r"); // File Containg Source Code
    fileptr2 = fopen("result.txt", "w"); // Output File name

    while ((c = fgetc(fileptr1)) != EOF)
    {
        switch (state)
        {
        case 0:
            if (isalpha(c))
            {
                state = 1;
                id[i++] = c;
            }
            else if (isdigit(c))
            {
                state = 3;
                num[j++] = c;
            }
            else if (c == '<' || c == '>')
            {
                state = 5;
                op[k++] = c;
            }
            else if (c == '=' || c == '!')
            {
                state = 8;
                op[k++] = c;
            }
            else if (c == '/')
                state = 10;
            else if (c == ' ' || c == '\t' || c == '\n')
                state = 0;
            else
                fprintf(fileptr2, "\n%c", c);
            break;
        case 1:
            if (isalnum(c))
            {
                state = 1;
                id[i++] = c;
            }
            else
            {
                id[i] = '\0';
                if (check_keyword(id))
                    fprintf(fileptr2, "\n%s : keyword ", id);
                else
                {
                    fprintf(fileptr2, "\n%s : identifier", id);
                    store_symb_tab(id, symbol_table);
                }
                // call a function which stores id in symbol table

                state = 0;
                i = 0;
                ungetc(c, fileptr1);
            }
            break;
        case 3:
            if (isdigit(c))
            {
                num[j++] = c;
                state = 3;
            }
            else
            {
                num[j] = '\0';
                fprintf(fileptr2, "\n%s: number", num);
                state = 0;
                j = 0;
                ungetc(c, fileptr1);
            }
            break;
        case 5:
            if (c == '=')
            {
                // write code to print specific operator like <= or >=
                state = 0;
            }
            else
            {
                // write code to print specific operator like <, >, <= or >=
                state = 0;
                ungetc(c, fileptr1);
            }
            op[k++] = c;
            op[k] = '\0';
            fprintf(fileptr2, "\n%s : relational operator ", op);
            k = 0;
            break;
        case 8:
            if (c == '=')
            {
                op[k++] = c;
                op[k] = '\0';
                fprintf(fileptr2, "\n%s : relational operator ", op);
                k = 0;
                // write code to print specific operator like == or !=
                state = 0;
            }
            else
            {
                ungetc(c, fileptr1);
                state = 0;
            }
            break;
        case 10:
            if (c == '*')
                state = 11;
            else
                fprintf(fileptr2, "\ninvalid lexeme");
            break;
        case 11:
            if (c == '*')
                state = 12;
            else
                state = 11;
            break;
        case 12:
            if (c == '*')
                state = 12;
            else if (c == '/')
                state = 0;
            else
                state = 11;
            break;

        } 
    }     

    if (state == 11){
        fprintf(fileptr2, "comment did not close");
        }
        
    fclose(fileptr1);
    fclose(fileptr2);
}