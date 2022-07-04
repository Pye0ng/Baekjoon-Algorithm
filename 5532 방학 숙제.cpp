#include<stdio.h>
#include<algorithm>
using namespace std; 

int main(){
	int l, a, b, c, d;
	scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
	printf("%d", l-max(a%c?a/c+1:a/c, b%d?b/d+1:b/d));
}
