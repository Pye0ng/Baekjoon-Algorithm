#include<stdio.h>
#include<stack>
using namespace std;
stack<int> s[200200];
int t[200200];

int main(){
	int n, m, p, q, i;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d", &p);
		while(p--){
			scanf("%d", &q);
			s[i].push(q);
			if(p==0) t[q]=i;
		}
	}
	for(i=1; i<=n; i++){
		if(t[i]==0){
			printf("No");
			return 0;
		}
		p=t[i]; t[i]=0; s[p].pop();
		if(!s[p].empty()) t[s[p].top()]=p;
	}
	printf("Yes");
}
