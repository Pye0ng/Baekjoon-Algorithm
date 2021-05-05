#include<stdio.h>
int m[1000001];

int main(){
    int n, i, max=-1000000, min=1000000;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &m[i]);
        if(m[i]>max) max=m[i];
        if(m[i]<min) min=m[i];
    }
    printf("%d %d", min, max);
} 
