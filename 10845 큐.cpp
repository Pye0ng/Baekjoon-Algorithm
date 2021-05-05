#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
queue<int> Q;
char s[12];

int main(){
	int n, k;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%s", s);
		if(!strcmp(s, "push")){
			scanf("%d", &k);
			Q.push(k);
		}
		else if(!strcmp(s, "size")) printf("%d\n", Q.size()); 
		else if(!strcmp(s, "empty")) printf("%d\n", Q.empty());
		else if(!strcmp(s, "front")){
			if(Q.empty()) printf("-1\n");
			else printf("%d\n", Q.front());
		}
		else if(!strcmp(s, "back")){
			if(Q.empty()) printf("-1\n");
			else printf("%d\n", Q.back());
		}
		else if(!strcmp(s, "pop")){
			if(Q.empty()) printf("-1\n");
			else{ printf("%d\n", Q.front()); Q.pop(); }
		}
	}
}
