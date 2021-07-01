#include <stdio.h>
#define MAXLINE 80
#define MAXFILE 1000

int getlinex(char line[], int maxline);
int appendline(char fi[], char line[], int maxfile);
int removecomments(char fi[], char newfi[]);

int main() {
    char fi[MAXFILE];
    char newfi[MAXFILE];
    char line[MAXLINE];
    int llen, flen;

    while((llen = getlinex(line, MAXLINE))>0 && (flen = appendline(fi, line, MAXFILE))>0)
        ;//printf("%d,%d", llen, flen);
    removecomments(fi, newfi);

    printf("before:\n%s", fi);
    printf("after:\n%s", newfi);

    return 0;

}

int getlinex(char s[], int maxline) {
    int i,c; 

    i = 0;
    while(i<maxline-1 && (c=getchar())!=EOF && c!='\n')
        s[i++] = c;
    
    if (c=='\n') 
        s[i++] = c;
    s[i] = '\0';

    return i;
}

int appendline(char fi[], char line[], int maxfile) {
    int i,j,c;

    for(i=0;fi[i]!='\0';i++);
    for(j=0;line[j]!='\0' && i<maxfile-1;i++,j++)
        fi[i] = line[j];

    fi[i] = '\0';

    if(i>maxfile-1)
        return 0;
    return i;
}

/* remove c comments */
int removecomments(char fi[], char newfi[]) 
{
    int i,j;
    char prechar;

    i = j= 0;
    prechar = ' ';
    while(fi[i] != '\0' && prechar != '\0') {
        if(prechar == '/' && fi[i] == '/') {
            j--;
            while(fi[i] != '\n' && fi[i] != '\0')
                i++;
            if(fi[i] != '\0')
                i++;
        }
        else 
            if(prechar == '/' && fi[i]=='*') {
                j--;
                prechar = ' ';
                while(!(prechar == '*' && fi[i] == '/') && fi[i] != '\0')
                   prechar = fi[i++]; 
                if(fi[i] != '\0')
                    i++;
        }
        
        prechar = fi[i];
        newfi[j++] = fi[i++];
    }
    newfi[j] = '\0';
    return 0;
}