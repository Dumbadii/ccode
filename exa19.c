#include <stdio.h>
#define MAXLINE 10    /*  maximum input line length */

int getaline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main()
{
    int len;    /* current line length */
    int max;    /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longestline[MAXLINE];  /* longest line saved here */

    max = 0;
    while((len = getaline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longestline, line);
        }
    }

    if (max > 0) 
        printf("%s\n", longestline);

    return 0;
}

/* getline: read a line into s, return length */
int getaline(char s[], int lim) {
    char c, i;

    for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c=='\n') 
        s[i++] = c;
    s[i] = '\0';

    printf("%s", s);
    printf("%d\n", i);
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
    int i = 0;
    while (from[i]!=0) {
        to[i] = from[i];
        i++;
    }
}