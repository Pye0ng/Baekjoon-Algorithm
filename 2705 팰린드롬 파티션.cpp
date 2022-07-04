#include<stdio.h>
int d[1010];

int main(){
    int t, n, i, j;
    scanf("%d", &t);
    d[0]=d[1]=1; d[2]=d[3]=2;
    for(i=4; i<1001; i++)
        for(j=0; 2*j<=i; j++) d[i]+=d[j];
    while(t--){
        scanf("%d", &n);
        printf("%d\n", d[n]);
    }
}