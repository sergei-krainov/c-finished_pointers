#include <stdio.h>
#include <string.h>
#define MAXLINES 1000
#define MAXSIZE 100
#define MAXBUF 10000
int readlines(char *lines[], int max);
void writelines(char *lines[], int nl);
int getlinet(char s[], int max);
char *alloct(int n);
void strcpyt(char *a, char *b);
void qsortt(char *lines[], int, int);


void swapt(char *lines[], int, int);


int main() {
    
    char *lines[MAXLINES];
    int nl;
    
    if ( (nl = readlines(lines, MAXLINES)) > 0 ) {
        printf("Hello\n");
        qsortt(lines, 0, nl - 1);
        printf("Sort is fine\n");
        writelines(lines, nl);
    }
    
    
    return 0;
}

int readlines(char *lines[], int max) {
    int i, c;
    char line[MAXSIZE];
    char *p;
    i = 0;
    while ( (c = getlinet(line, MAXSIZE) ) != 0 && i <= max) {
        if ( ( p = alloct(c)) != 0 ) {
            /* line[c-1] = '\0'; */
            strcpyt(line, p);
            
            lines[i++] = p; 
        }
        else {
            return i;
        }
    }
    return i;
}

int getlinet(char s[], int max) {
    int c;
    int i;
    i = 0;
    
    while ( (c = getchar()) != EOF && c != '\n' && i <= max )
        s[i++] = c;
    if ( c == '\n' )
        s[i++] = '\n';
    s[i] = '\0';
    
    return i;
}

static char BUF[MAXBUF];
static char *po = BUF;

char *alloct(int n) {
    /* To store all symbols, without it we don't have place for '\0' */
    n++;
    if ( BUF + MAXSIZE - po  < n )
        return 0;
    po += n;
    return po - n;
}

void strcpyt(char *a, char *b) {
    while ( (*b++ = *a++) )
        ;
}

void writelines(char *lines[], int nl) {
    int i;
    printf("Lines %d\n", nl);
    
    for (i=0; i < nl; i++)
        printf("%s", lines[i]);
    
}

void qsortt(char *lines[], int left, int right) {
    if ( left >= right )
        return;
    printf("left=%d, right=%d\n", left, right);
    
    int i, last;
    last = left;
    for (i = left + 1; i <= right; i++) {
        if ( (strcmp(lines[i], lines[left])) < 0 ) {
            swapt(lines, i, ++last);
        }
    }
    swapt(lines, last, left);
    
    qsortt(lines, left, last-1);
    qsortt(lines, last+1, right);
    
}

void swapt(char *lines[], int a, int b) {
    printf("Success1\n");
    char *tmp;
    
    tmp = lines[a];
    lines[a] = lines[b];
    lines[b] = tmp;
}




