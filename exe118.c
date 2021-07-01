
#include <stdio.h>
#define MAXLINE 100 /* maximum input line length */
#define PRINTLINE 10 /* print the line when length > this */
#define ON 1 /* blank or tab state */
#define OFF 0 /* blank or tab state */

int getline_trim_tail(char line[], int maxline);

int main(){
    char line[MAXLINE];
    int len;

    while ((len=getline_trim_tail(line,MAXLINE)) > 0) 
        if (len > PRINTLINE)
            printf("%s", line);

    return 0;
}

int getline_trim_tail(char line[], int maxline) {
    char c;
    int blankstate;
    int i = 0;

    blankstate = OFF;
    while(i<maxline-1 && (c=getchar())!=EOF && c!='\n') {
        if ((c=='\t' || c==' ') && blankstate==ON) 
            continue;
        blankstate = (c!='\t' && c!=' ')? OFF: ON;
        line[i++] = c;
    }

    if (i>0 && line[i-1]==' ')
        i--;

    if (c == '\n') 
        line[i++] = c;
    
    line[i] = '\0';

    return i;
}
