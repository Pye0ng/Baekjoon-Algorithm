#include<stdio.h>
char s[1000100];
int n, p[1000100];

int main(){
    int i, j;
    scanf("%s", s);
    while(s[n]!='\0') n++;
    for(i=1, j=0; i<n; i++){
        while(j>0&&s[i]!=s[j]) j=p[j-1];
        if(s[i]==s[j]) p[i]=++j;
    }
    for(i=1, j=0; i<n; i++){
        if(p[i]==0||(i+1)%(i+1-p[i])) continue;
        printf("%d %d\n", i+1, (i+1)/(i+1-p[i]));
    }
}