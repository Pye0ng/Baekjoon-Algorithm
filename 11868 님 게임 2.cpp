#include<stdio.h>
int ans;

int main(){
	int n, t;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &t);
		ans^=t;
	}
	printf("%s", ans?"koosaga":"cubelover");
}
