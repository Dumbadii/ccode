#include <stdio.h>
#define MAXLINE 10

void reverse(char s[]);
int getlinex(char s[], int maxline);

int main() {
    char line[MAXLINE];
    int len = 0;

    while ((len=getlinex(line,MAXLINE))>0) {
        reverse(line);
        printf("%s\n", line);
    }

    return 0;
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

void reverse(char s[]) {
    int l,r;
    char c;

    l = r = 0;
    while (s[r]!='\0')
        r++;
    r--;
    while(l < r) {
        c = s[l];
        s[l++] = s[r];
        s[r--] = c;
    }
}