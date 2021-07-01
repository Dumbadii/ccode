#include <stdio.h>
#define MAXLINE 100
#define COLS 10
#define N 8     /* tab width */

int getlinex(char s[], int maxline);
void rtrim(char s[]);
void copyslice(char from[], char to[], int start, int len);
int detab(char from[], char to[]);

int main()
{
    int len,detablen;
    int rows;
    char line[MAXLINE]; 
    char detabline[MAXLINE];
    char aslice[COLS+1];

    while ((len=getlinex(line,MAXLINE))>0) {
        detablen = detab(line, detabline);
        printf("detab:%s\n", detabline);
        rows = detablen / COLS;
        if(len % COLS > 0)
            rows++;

        for(int i=0;i<rows;i++) {
            copyslice(detabline, aslice, i*COLS, COLS);
            rtrim(aslice);
            printf("%d:%s\n", i, aslice);
        }
    }
}

int getlinex(char s[], int maxline) {
    int c,i;

    i = 0;
    while(i<maxline-1 && (c=getchar())!=EOF && c!='\n') {
        s[i++] = c;
    }

    if (c == '\n')
        s[i++] = '\n';

    s[i] = '\0';
    
    return i;
}

int detab(char from[], char to[])
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
    return j;
}

void copyslice(char *from, char *to, int start, int len)
{
    int i,j;
    j = 0;
    for(i=start;i<start+len && from[i]!='\0';i++) 
        to[j++] = from[i];
    to[j] = '\0';
}

void rtrim(char s[]) {
    int i,num;
    num = 0;
    for(i=0;s[i]!='\0';i++) {
        if (s[i] == ' ' || s[i] == '\t')
            num++;
        else
            num = 0;
    }

    s[i-num] = '\0';

}