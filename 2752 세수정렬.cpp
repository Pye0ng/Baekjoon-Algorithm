#include<stdio.h>
#include<algorithm>

int main(){
	int i, a[3];
	for(i=0; i<3; i++) scanf("%d", &a[i]);
	std::sort(a, a+3);
	for(i=0; i<3; i++) printf("%d ", a[i]);
}
