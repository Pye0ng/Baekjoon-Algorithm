#include<stdio.h>
int n;

bool pr(int num){
	if(num==0||num==1) return false;
	for(int i=2; i*i<=num; i++)
		if(num%i==0) return false;
	return true;
}

void ca(int num, int len){
	if(n==len){
		printf("%d\n", num);
		return;
	}
	for(int i=1; i<=9; i+=2)
		if(pr(10*num+i)) ca(10*num+i, len+1);
}

int main(){
	scanf("%d", &n);
	ca(2, 1);
	ca(3, 1);
	ca(5, 1);
	ca(7, 1);
}
