#include<stdio.h>
#include<queue>
using namespace std;
queue<int> q, p;

void popush(int k){
	for(int i=1; i<=k-1; i++){
		int n=q.front();
		q.pop();
		q.push(n);
	}
}

int main(){
	int n, k, i;
	scanf("%d %d", &n, &k);
	for(i=1; i<=n; i++) q.push(i);
	while(q.size()>0){
		popush(k);
		p.push(q.front());
		q.pop();
	}
	printf("<");
	for(i=1; i<=n-1; i++){
		printf("%d, ", p.front());
		p.pop();
	}
	printf("%d>", p.front());
}
