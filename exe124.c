#include <stdio.h>
#define MAXLINE 80
#define MAXFILE 1000

char stack[MAXLINE];
int top = 0;

int push(char c);
int pop();
int isEmpty();
int isFull();
int readTop();

int isLeftMark(char c);
int isRightMark(char c);
int isPair(char l, char r);

int getlinex(char line[], int maxline);
int appendline(char file[], char line[], int maxfile);
int removecomments(char originf[], char destinf[]);
void checkMatchError(char file[]);

int main()
{
    int linelen, filelen;
    char originfile[MAXFILE], newfile[MAXFILE], line[MAXLINE];

    while((linelen = getlinex(line,MAXLINE))>0 && (filelen = appendline(originfile,line,MAXFILE))>0);
    removecomments(originfile, newfile);
    checkMatchError(newfile);

    return 0;
}

int push(char c)
{
    if(isFull())
        return -1;
    stack[top++] = c; 
}

int pop()
{
    if(isEmpty())
        return -1;
    return stack[--top];
}

int isEmpty()
{
    return top==0?1:0;
}

int isFull()
{
    return top==MAXLINE?1:0;
}

int readTop()
{
    if(isEmpty())
        return -1;
    
    return stack[top-1];
}

int isLeftMark(char c)
{
    switch(c) {
        case '(': case '[': case '{':
            return 1;
        default:
            return 0;
    }
}

int isRightMark(char c)
{
    switch(c) {
        case ')': case ']': case '}':
            return 1;
        default:
            return 0;
    }
}

int isPair(char l, char r)
{
    if((l=='(' && r==')') || (l=='[' && r==']') || (l=='{' && r=='}'))
        return 1;
    return 0;
}

void checkMatchError(char file[])
{
    int i,c,t;
    i = 0;

    while((c=file[i])!='\0') {
        if(isLeftMark(c)) 
            push(c);
        
        if (isRightMark(c)) 
            if(!isPair(readTop(), c))
                printf("pos%d, right mark %c not match\n", i, c);
            else
                pop();
        
        i++;
    }

    while(!isEmpty())
        printf("left mark %c has no match\n", pop());
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