#include<stdio.h>
#include<queue>
using namespace std;
queue<int> q;

int main(){
	int n, k, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) q.push(i);
	while(!q.empty()){
		printf("%d ", q.front());
		q.pop();
		if(!q.empty()){
			q.push(q.front());
			q.pop();
		}
	} 
}
