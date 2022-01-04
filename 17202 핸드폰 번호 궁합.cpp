#include<stdio.h>
#include<queue>
using namespace std;
char a[10], b[10];
queue<int> q;

int main(){
	int s, p, i;
	scanf("%s", a); scanf("%s", b); 
	for(i=0; a[i]!='\0'; i++){
		q.push(a[i]-'0');
		q.push(b[i]-'0');
	}
	while(q.size()>2){
		s=q.size();
		for(i=1; i<s; i++){
			p=q.front(); q.pop();
			q.push((p+q.front())%10);
		}
		q.pop();
	}
	printf("%d", q.front());
	q.pop(); printf("%d", q.front());
}
