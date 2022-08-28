#include<stdio.h>
int p[1000100];

int main(){
    int n, i, j;
    while(1){
        char s[1000100];
        scanf("%s", s); n=0;
        if(s[0]=='.') break;
        while(s[n]!='\0') n++;
        for(i=1, j=0; i<n; i++){
            while(j>0&&s[i]!=s[j]) j=p[j-1];
            if(s[i]==s[j]) p[i]=++j;
        }
        printf("%d\n", n%(n-p[n-1])==0?n/(n-p[n-1]):1);
        for(i=1; i<n; i++) p[i]=0;
    }
}