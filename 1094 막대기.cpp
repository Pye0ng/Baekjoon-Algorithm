#include<stdio.h>
#include<math.h>
int n, cnt;

int find(int k){
	int p;
	for(int i=0; i<60; i++)
		if(pow(2, i)<=k&&k<pow(2, i+1)) p=i;
	return k-pow(2, p);
}

int main(){
	scanf("%d", &n);
	while(n!=0){
		n=find(n);
		cnt++;
	}
	printf("%d", cnt);
}
