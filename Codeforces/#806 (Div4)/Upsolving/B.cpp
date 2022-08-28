#include<stdio.h>

int main(){
    int t, n, i;
    scanf("%d", &t);
    while(t--){
        char c[52];
        int ans=0, d[30]={};
        scanf("%d", &n);
        scanf("%s", c);
        for(i=0; i<n; i++) d[c[i]-'A']++;
        for(i=0; i<26; i++) ans+=d[i]+(d[i]>0);
        printf("%d\n", ans);
    }
}