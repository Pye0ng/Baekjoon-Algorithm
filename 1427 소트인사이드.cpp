#include<stdio.h>
#include<algorithm>
int cnt, a[11];

bool cmp(int p, int q){
	if(p>q) return 1;
	else return 0;
}

int main(){
	int n, i;
	scanf("%d", &n);
	while(n!=0){
		a[cnt++]=n%10;
		n/=10;
	}
	std::sort(a, a+cnt, cmp);
	for(i=0; i<cnt; i++) printf("%d", a[i]);
}
