#include<stdio.h>
int max(int p, int q){ return p>q?p:q; }
int la, lb, d[1010][1010];
char a[1010], b[1010];

int main(){
    int i, j;
    scanf("%s", a);
    scanf("%s", b);
    for(i=0; a[i]!='\0'; i++) la++;
    for(i=0; b[i]!='\0'; i++) lb++;
    for(i=1; i<=la; i++)
        for(j=1; j<=lb; j++) d[i][j]=a[i-1]==b[j-1]?d[i-1][j-1]+1:max(d[i][j-1], d[i-1][j]);
    printf("%d", d[la][lb]);
}