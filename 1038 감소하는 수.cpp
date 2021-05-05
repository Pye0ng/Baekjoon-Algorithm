#include<stdio.h>
#include<queue>
using namespace std;
queue<int> q;

int main(){
	int n, i;
	scanf("%d", &n);
	if(n==0){
		printf("0");
		return 0;
	}
	if(n==1022){
		printf("9876543210");
		return 0;
	}
	if(n>=1023){
		printf("-1");
		return 0;
	}
	for(i=1; i<=9; i++) q.push(i);
	while(!q.empty()){
		int m=q.front();
		q.pop();
		if(--n==0){
			printf("%d", m);
			return 0;
		}
		int l=m%10;
		for(i=0; i<l; i++) q.push(m*10+i);
	}
} 
