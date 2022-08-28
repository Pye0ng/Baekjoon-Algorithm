#include<stdio.h>
int m=-1, t, s[1000100], p[1000100];

int main(){
    int n, i, j;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &s[n-1-i]);
    for(i=1, j=0; i<n; i++){
        while(j>0&&s[i]!=s[j]) j=p[j-1];
        if(s[i]==s[j]) p[i]=++j;
    }
    for(i=0; i<n; i++){
        if(p[i]>m){ m=p[i]; t=1; }
        else if(p[i]==m) t++;
    }
    if(m>0) printf("%d %d", m, t);
    else printf("-1");
}