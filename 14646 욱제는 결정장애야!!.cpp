#include<stdio.h>
int n,k,m,s,i,d[100010];int main(){scanf("%d", &n);for(i=1;i<=2*n;i++){scanf("%d", &k);if(d[k]){s--;d[k]++;}else{if(++s>m)m=s;d[k]++;}}printf("%d",m);}
