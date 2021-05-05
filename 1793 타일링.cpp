#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string d[260];
int n, i;

string add(string a, string b){
	int k=0; string c="";
	while(!a.empty()||!b.empty()||k){
		if(!a.empty()){
			k+=a.back()-'0';
			a.pop_back();
		}
		if(!b.empty()){
			k+=b.back()-'0';
			b.pop_back();
		}
		c.push_back((k%10)+'0');
		k/=10;
	}
	reverse(c.begin(), c.end());
	return c;
}

int main(){
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	d[0]=d[1]="1"; d[2]="3";
	for(i=3; i<=255; i++) d[i]=add(d[i-1], add(d[i-2], d[i-2]));
	while(~scanf("%d", &n))	cout<<d[n]<<"\n";
}
