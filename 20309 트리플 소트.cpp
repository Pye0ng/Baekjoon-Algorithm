#include<stdio.h>
int n,k,i;int main(){scanf("%d",&n);for(i=1;i<=n;i++){scanf("%d", &k);if(i%2!=k%2){printf("NO");return 0;}}printf("YES");}
