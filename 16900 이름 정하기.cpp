#include<stdio.h>
long long k, p[500500];
char s[500500];
int n;

int main(){
    int i, j;
    scanf("%s", s);
    scanf("%lld", &k);
    while(s[n]!='\0') n++;
    for(i=1, j=0; i<n; i++){
        while(j>0&&s[i]!=s[j]) j=p[j-1];
        if(s[i]==s[j]) p[i]=++j;
    }
    printf("%lld", k*n-(k-1)*p[n-1]);
}