#include<stdio.h>
int m[10001];

int main(){
    int n, x;
    scanf("%d %d", &n, &x);
    for(int i=0; i<n; i++){
        scanf("%d", &m[i]);
        if(m[i]<x) printf("%d ", m[i]);
    }
} 
