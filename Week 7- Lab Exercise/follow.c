#include <stdio.h>
#include <ctype.h>

void FIRST(char *, char);
void FOLLOW(char *, char);
void addToArray(char *, char);
void printArray(char *);

int n;
char production[20][20];

int main()
{
    int i, j = 0, k, foundNt = 0;
    char c, result[20], nt[20];
    nt[0] = '\0';

    FILE *fp = fopen("input.txt", "r");

    fscanf(fp, "%d", &n);
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%s", production[i]);
        printArray(production[i]);
        printf("\n");
        addToArray(nt, production[i][0]);
    }

    fclose(fp);

    printf("\n\n");

    for (k = 0; nt[k] != '\0'; k++)
    {
        c = nt[k];
        FIRST(result, c);
        printf("FIRST(%c)= { ", c);
        printArray(result);
        printf("}\n");
    }

    printf("\n\n");

    for (k = 0; nt[k] != '\0'; k++)
    {
        c = nt[k];
        FOLLOW(result, c);
        printf("FOLLOW(%c)= { ", c);
        printArray(result);
        printf("}\n");
    }

    printf("\n\n");

    return 0;
}

void FIRST(char *Result, char c)
{
    int i, j, k;
    char subResult[20];
    int foundEpsilon;
    subResult[0] = '\0';
    Result[0] = '\0';
    if (!(isupper(c)))
        addToArray(Result, c);
    else
        for (i = 0; i < n; i++)
        {
            if (production[i][0] == c)
            {
                if (production[i][2] == '^')
                    addToArray(Result, '^');
                else
                {
                    for (j = 2; production[i][j] != '\0'; j++)
                    {
                        foundEpsilon = 0;
                        FIRST(subResult, production[i][j]);

                        for (k = 0; subResult[k] != '\0'; k++)
                            if (subResult[k] == '^')
                                foundEpsilon = 1;
                            else
                                addToArray(Result, subResult[k]);
                        if (!foundEpsilon)
                            break;
                    }
                }
            }
        }
    return;
}

void FOLLOW(char *Result, char c)
{
    Result[0] = '\0';
    if (c == production[0][0])
    {
        addToArray(Result, '$');
    }
    for (int i = 0; i < n; i++)
    {
        int done = 0;
        for (int j = 2; production[i][j] != '\0'; j++)
        {
            if (production[i][j] == c)
            {
                // printArray(production[i]);
                // printf("\n");
                if (production[i][j + 1] != '\0')
                {
                    int flag = 1;
                    char first[20];
                    for (int k = j + 1; production[i][k] != '\0' && flag; k++) {
                        flag = 0;
                        first[0] = '\0';
                        FIRST(first, production[i][k]);
                        // printArray(first);
                        // printf("\n");
                        for (int l = 0; first[l] != '\0'; l++) {
                            if (first[l] == '^') {
                                flag = 1;
                            } else {
                                addToArray(Result, first[l]);
                            }
                        }
                    }
                    if (flag)
                    {
                        char follow[20];
                        follow[0] = '\0';
                        FOLLOW(follow, production[i][0]);
                        // printArray(follow);
                        // printf("\n");
                        for (int k = 0; follow[k] != '\0'; k++)
                        {
                            addToArray(Result, follow[k]);
                        }
                    }
                }
                else
                {
                    char follow[20];
                    follow[0] = '\0';
                    FOLLOW(follow, production[i][0]);
                    for (int k = 0; follow[k] != '\0'; k++)
                    {
                        addToArray(Result, follow[k]);
                    }
                }
                done = 1;
                break;
            }
        }
        if (done) break;
    }
}

void addToArray(char *Result, char val)
{
    int k;
    for (k = 0; Result[k] != '\0'; k++)
        if (Result[k] == val)
            return;
    Result[k] = val;
    Result[k + 1] = '\0';
}

void printArray(char *a)
{
    int i = 0;
    for (i = 0; a[i] != '\0'; i++)
        printf("%c ", a[i]);
}
