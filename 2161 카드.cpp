#include<stdio.h>
#include<queue>
using namespace std;
queue<int> q;

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) q.push(i);
	while(!q.empty()){
		printf("%d ", q.front());
		q.pop();
		int k=q.front();
		q.pop();
		q.push(k);
	} 
}
