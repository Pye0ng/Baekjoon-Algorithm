#include<stdio.h>
#include<stack>
using namespace std;

int main(){
	int t, m, i;
	scanf("%d", &t);
	while(t--){
		stack<char> s; m=0;
		char c[200200];
		int a[30];
		scanf("%s", c);
		for(i=0; i<26; i++) a[i]=0;
		for(i=0; c[i]!='\0'; i++){
			if(a[c[i]-'a']){
				while(!s.empty()&&s.top()!=c[i]){ a[s.top()-'a']=0; s.pop(); m++; }
				if(!s.empty()){ a[s.top()-'a']=0; s.pop(); }
			}
			else{
				s.push(c[i]);
				a[c[i]-'a']=1;
			}
		}
		printf("%d\n", m+s.size());
	}
}
