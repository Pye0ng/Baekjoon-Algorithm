#include<stdio.h>
#include<string.h>
#include<deque>
using namespace std;
deque<int> D;
char s[12];

int main(){
	int n, k;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%s", s);
		if(!strcmp(s, "push_front")){
			scanf("%d", &k);
			D.push_front(k);
		}
		else if(!strcmp(s, "push_back")){
			scanf("%d", &k);
			D.push_back(k);
		}
		else if(!strcmp(s, "size")) printf("%d\n", D.size()); 
		else if(!strcmp(s, "empty")) printf("%d\n", D.empty());
		else if(!strcmp(s, "front")){
			if(D.empty()) printf("-1\n");
			else printf("%d\n", D.front());
		}
		else if(!strcmp(s, "back")){
			if(D.empty()) printf("-1\n");
			else printf("%d\n", D.back());
		}
		else if(!strcmp(s, "pop_front")){
			if(D.empty()) printf("-1\n");
			else{ printf("%d\n", D.front()); D.pop_front(); }
		}
		else if(!strcmp(s, "pop_back")){
			if(D.empty()) printf("-1\n");
			else{ printf("%d\n", D.back()); D.pop_back(); }
		}
	}
}
