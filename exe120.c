#include <stdio.h>
#define MAXLINE 20
#define N 8 /* tab width */
#define ON 1 /* space to tab possible */
#define OFF 0 /* space to tab impossible */

void detab(char from[], char to[]);
void entab(char from[], char to[]);
int getlinex(char[], int maxline);

int main()
{
    int len = 0;
    char line[MAXLINE];
    char chgline[MAXLINE];

    while ((len=getlinex(line,MAXLINE)) > 0 )
    {
        detab(line, chgline);
        printf("%s", chgline);

        entab(chgline, line);
        printf("%s", line);
    }

    return 0;
}

int getlinex(char s[], int lim)
{
    char c;
    int i;

    for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';i++)
        s[i] = c;

    if (c=='\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}

void detab(char from[], char to[])
{
    int i,j;
    i = j = 0;
    for(;from[i]!='\0';i++)
    {
        if(from[i]=='\t')
        {
            to[j++] = ' ';
            while((j) % N != 0)
                to[j++] = ' ';
        }
        else
            to[j++] = from[i];
    }

    to[j] = '\0';
}

void entab(char from[], char to[])
{
    int i,j,spacenum;

    i = j = spacenum = 0;

    for(;from[i]!='\0';i++) {
        to[j++] = from[i];
        if(from[i] == ' ')
            spacenum++;
        else
            spacenum = 0;

        if(i % N == N - 1) {
            if (spacenum > 1){
                j -= spacenum;
                to[j++] = '\t';
            }
            spacenum = 0;
        }
    }

    to[j] = '\0';
}