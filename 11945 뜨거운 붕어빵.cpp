#include<stdio.h>
char c[12][12];

int main(){
    int n, m, i, j;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++) scanf("%s", c[i]);
    for(i=0; i<n; i++){
        for(j=m-1; j>=0; j--) printf("%c", c[i][j]);
        printf("\n");
    }
}