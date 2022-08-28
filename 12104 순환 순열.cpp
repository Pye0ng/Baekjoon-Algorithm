#include<stdio.h>
char a[100100], b[200200];
int n, ans, p[100100];

int main(){
    int i, j;
    scanf("%s", a);
    scanf("%s", b);
    while(a[n]!='\0') n++;
    for(i=0; i<n; i++) b[n+i]=b[i];
    for(i=1, j=0; i<n; i++){
        while(j>0&&a[i]!=a[j]) j=p[j-1];
        if(a[i]==a[j]) p[i]=++j;
    }
    for(i=0, j=0; i<2*n-1; i++){
        while(j>0&&b[i]!=a[j]) j=p[j-1];
        if(b[i]==a[j]){
            if(j==n-1){ ans++; j=p[j]; }
            else j++;
        }
    }
    printf("%d", ans);
}