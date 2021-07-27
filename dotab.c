#include <stdio.h>
#include <stdlib.h>
#define MAXTAB 10
#define MAXLINE 100
#define DEFAULTABSPACE 8

int tabspace[MAXTAB];

int getlinex(char*, int);
int tabstop(int, int*, int);
void detab(char*, int*, int);
void entab(char*, int*, int);

int main(int argc, char *argv[])
{
    int tablen[MAXTAB];
    int tabcnt;
    int len;
    char line[MAXLINE];

    printf("Usage example: expr 2 3 4 + p\n");

    tabcnt = 0;
    while (--argc > 0)
        tabspace[tabcnt++] = atoi(*++argv);
    while(tabcnt < MAXTAB)
        tabspace[tabcnt++] = DEFAULTABSPACE;

    while ( (len = getlinex(line, MAXLINE)) > 0) {
        detab(line, tablen, MAXTAB);
    } 
    
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
    while (i < maxline-1 && (c = getchar()) != EOF && c != '\0')
        line[i++] = c;
    
    if (c == '\n')
        line[i++] = c;
    
    line[i] = '\0';

    return i;
}

int tabstop(int pos, int* tablen, int tablim)
{
    int temp;
    temp = pos;
    while (pos > *tablen && tablim-- > 0)
        pos -= *tablen++;
    return temp - pos + *tablen;
}

void detab(char *line, int *tablen, int tablim)
{
    int i,j;
    char c, detabline[MAXLINE];
    i = j = 0;

    while ((c = line[i++]) != '\0') {
        if (c == '\t')
            while (j < tabstop(j, tablen, tablim))
                detabline[j++] = ' ';
        else
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
            if (i == tabstop(i,tablen,tablim)) {
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
