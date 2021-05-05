#include<stdio.h>
int f(int n){
	int ans=0;
	for(int i=0; i<3; i++){
		ans*=10;
		ans+=n%10;
		n/=10;
	}
	return ans;
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", f(a)>f(b)?f(a):f(b));
}
