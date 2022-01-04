#include<stdio.h>
#include<queue>
using namespace std;
int d[26]={3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
char a[2020], b[2020];
queue<int> q;

int main(){
	int s, p, i;
	scanf("%s", a); scanf("%s", b); 
	for(i=0; a[i]!='\0'; i++){
		q.push(d[a[i]-'A']);
		q.push(d[b[i]-'A']);
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
