#include<stdio.h>
#include<vector>
#define x first
#define y second
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int main(){
	int n, t, d, ch, ans, i;
	char p, c[101000];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		scanf("%s", c);
		p=c[0]; ch=0; ans=1;
		for(i=1; i<n; i++){
			if(c[i]=='W'){
				if(p=='W') continue;
				else ans&=ch>0;
				ch=0; p='W';
			}
			else if(p!=c[i]){ 
				if(p!='W') ch++;
				p=c[i];
			}
		}
		if(p!='W'&&ch==0) ans=0;
		printf("%s\n", ans?"YES":"NO");
	}
}
