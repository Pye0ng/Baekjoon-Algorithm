#include<stdio.h>
#include<stack>
using namespace std;
stack<int> s;
int cnt, sum, v[1000100], t[1000100];

int main(){
	int n, p=1, a, b, c, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a);
		if(a){
			scanf("%d %d", &b, &c); 
			v[p]=b; t[p]=c-1; 
			if(t[p]!=0) s.push(p);
			p++;
		}
		else if(!a&&!s.empty()){
			t[s.top()]--;
			if(t[s.top()]==0) s.pop();
		}
	}
	for(i=1; i<p; i++)
		if(t[i]==0) sum+=v[i];
	printf("%d", sum);
}
