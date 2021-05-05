#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
stack<int> S;
char st[12];

int main(){
	int n, k;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%s", st);
		if(!strcmp(st, "push")){
			scanf("%d", &k);
			S.push(k);
		}
		else if(!strcmp(st, "pop")){
			if(S.empty()) printf("-1\n");
			else{ printf("%d\n", S.top()); S.pop(); }
		}
		else if(!strcmp(st, "size")) printf("%d\n", S.size());
		else if(!strcmp(st, "empty")) printf("%d\n", S.empty());
		else if(!strcmp(st, "top")){
			if(S.empty()) printf("-1\n");
			else printf("%d\n", S.top());
		}
	}
}
