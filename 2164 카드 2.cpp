#include<stdio.h>
#include<queue>
using namespace std;
queue<int> q;

int main(){
	int n, k, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) q.push(i);
	while(q.size()>1){
		q.pop();
		k=q.front();
		q.pop();
		q.push(k);
	}
	printf("%d", q.front());
}
