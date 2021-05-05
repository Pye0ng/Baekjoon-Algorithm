#include<iostream>
#include<string>
using namespace std;
int n, m, cnt;
string s;

int main(){
	int i;
	cin>>n>>m>>s;
	for(i=0; i<m; i++)
		if(s[i+1]=='O'&&s[i+2]=='I'){
			int p=0;
			while(s[i]=='I'&&s[i+1]=='O'){
				i+=2; p++;
				if(s[i]=='I'&&p==n){
					p--; cnt++;
				}
			}
		}
	printf("%d", cnt);
}
