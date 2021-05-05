#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int n, k;
bool d[25];
char s[7], zero[7];

void set(int m){ for(int i=1; i<=20; i++) d[i]=m; }

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>s;
		if(!strcmp(s, "add")){
			cin>>k;
			d[k]=1;
		}
		else if(!strcmp(s, "remove")){
			cin>>k;
			d[k]=0;
		}
		else if(!strcmp(s, "check")){
			cin>>k;
			cout<<d[k]<<"\n";
		}
		else if(!strcmp(s, "toggle")){
			cin>>k;
			d[k]=!d[k];
		}
		else if(!strcmp(s, "all")) set(1);
		else set(0);
		for(int j=0; j<7; j++) s[j]=zero[j];
	}
}
