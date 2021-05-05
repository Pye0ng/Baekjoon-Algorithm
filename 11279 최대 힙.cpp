#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, less<int> > q;
int n, k;

void heap_pop(){
	if(q.size()){
		printf("%d\n", q.top());
		q.pop();	
	}
	else printf("0\n");
}

int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &k);
		if(k==0) heap_pop();
		else q.push(k);
	}
}
