#include<stdio.h>
int m[10];

int main(){
    int i, max=0, mxp;
    for(i=0; i<9; i++){
        scanf("%d", &m[i]);
        if(m[i]>max){
            max=m[i];
            mxp=i+1;
        }
    }
    printf("%d\n%d", max, mxp);
} 
