#include<stdio.h>

int main(){
    int a, b, c, d, e;
    double f;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    f=(double)((c-d)*(a-e)*b)/((a-e)*(c-d)+d*e);
    printf("%.7f", f);
}
