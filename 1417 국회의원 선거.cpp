#include<stdio.h>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, less<int> > q;

int main(){
	int n, d, t, c=0, i;
	scanf("%d %d", &n, &d);
	for(i=1; i<n; i++){
		scanf("%d", &t);
		q.push(t);
	}
	t=q.empty()?0:q.top();
	while(t>=d){
		q.pop();
		q.push(t-1);
		d++; c++;
		t=q.top();
	}
	printf("%d", c);
}
