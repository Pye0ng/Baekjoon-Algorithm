#include<stdio.h>
char s[1000100];
int p[1000100];

int main(){
    int n, i, j;
    scanf("%d", &n);
    scanf("%s", s);
    for(i=1, j=0; i<n; i++){
        while(j>0&&s[i]!=s[j]) j=p[j-1];
        if(s[i]==s[j]) p[i]=++j;
    }
    printf("%d", n-p[n-1]);
}