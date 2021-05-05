#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
queue<char> in, r, p, z, zero;
int n, cnt, len;
char input[11], s[11];

bool check(){
	queue<char> q;
	q=in;
	while(!z.empty()){
		if(z.front()!=q.front()) return false;
		z.pop();
		q.pop();
	}
	return true;
}

bool find(int k){
	z=zero;
	for(int i=0; i<k; i++){
		char fr=p.front();
		p.pop();
		p.push(fr);
	}
	for(int i=1; i<=len; i++){
		z.push(p.front());
		p.pop();
	}
	if(check()) return true;
	else return false;
}

int main(){
	int i, j;
	scanf("%s %d", input, &n);
	len=strlen(input);
	for(i=0; i<len; i++) in.push(input[i]);
	for(i=1; i<=n; i++){
		r=zero;
		scanf("%s", s);
		for(j=0; j<10; j++) r.push(s[j]);
		for(j=0; j<10; j++){
			p=r;
			if(find(j)){
				cnt++;
				break;
			}
		}
	}
	printf("%d", cnt);
}
