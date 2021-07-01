#include <stdio.h>
#define MAXLINE 100 /* maximum input line length */
#define PRINTLINE 10 /* print the line when length > this */

int getlinex(char line[], int maxline);

int main(){
    char line[MAXLINE];
    int len;

    while ((len=getlinex(line,MAXLINE)) > 0) 
        if (len > PRINTLINE)
            printf("%s\n", line);

    return 0;
}

int getlinex(char line[], int maxline) {
    char c, i;

    i = 0;
    while(i<maxline-1 && (c=getchar())!=EOF && c!='\n')
        line[i++] = c;
    
    if (c == '\n') {
        line[i++] = c;
    
    line[i] = '\0';
    
    return i;
    }
}
