#include <stdio.h>
#include <stdlib.h>
#define MAXTAB 10
#define MAXLINE 100
#define DEFAULTABSPACE 8

int getlinex(char*, int);
int tabstop(int, int*);
void detab(char*, int*);
void entab(char*, int*, int);

int main(int argc, char *argv[])
{
    int tablen[MAXTAB+1];
    int tabcnt;
    int len;
    char line[MAXLINE];

    printf("Usage example: expr 2 3 4 + p\n");

    tabcnt = 0;
    while (--argc > 0)
        tablen[tabcnt++] = atoi(*++argv);
    
    if (tabcnt == 0)
        tablen[tabcnt++] = DEFAULTABSPACE;
    tablen[tabcnt] = 0;

    while ( (len = getlinex(line, MAXLINE)) == 0);
    detab(line, tablen);
    return 0;
    
    while ( (len = getlinex(line, MAXLINE)) > 0) {
        entab(line, tablen, MAXTAB);
    } 

    return 0;
}

int getlinex(char *line, int maxline)
{
    char c;
    int i;

    i = 0;
    while (i < maxline-1 && (c = getchar()) != EOF && c != '\n')
        line[i++] = c;
    
    if (c == '\n')
        line[i++] = c;
    
    line[i] = '\0';

    return i;
}

int tabstop(int pos, int* tablen)
{
    int j = 0;
    while (tablen[j])
        j++;
    j--;

   pos %=tablen[j]; 
    while(j > 0 && pos < tablen[j-1] )
        pos %= tablen[--j];
    return tablen[j] - pos;
}

void detab(char *line, int *tablen)
{
    int i,j,k;
    char c, detabline[MAXLINE];
    i = j = 0;

    while ((c = line[i++]) != '\0') {
        if (c == '\t') {
            k = tabstop(j, tablen);
            printf("k:%d\n", k);
            while (k--)
                detabline[j++] = ' ';
        } else
            detabline[j++] = c;
    }

    detabline[j] = '\0';
    printf("after detab:\n%s\n", detabline);
}    

void entab(char *line, int *tablen, int tablim)
{
    int i, j, tmpos;
    char c, entabline[MAXLINE];
    i = j = tmpos = 0;

    while ((c = line[i++]) != '\0') {
        entabline[j] = c;
        if (c == ' ') {
            if (!tmpos) tmpos = j;
            if (i == tabstop(i,tablen)) {
                j = tmpos;
                entabline[j] = '\t';
                tmpos = 0;
            }
        } else
            tmpos = 0;
        j++;
    }
    entabline[j] = '\0';
    printf("after entab:\n%s\n", entabline);
}
