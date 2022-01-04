#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string fib[510];

string pl(string a, string b){
	int t, sum=0, i;
	string c="";
	while(!a.empty()||!b.empty()||sum){
		if(!a.empty()){
			sum+=a.back()-'0';
			a.pop_back();
		}
		if(!b.empty()){
			sum+=b.back()-'0';
			b.pop_back();
		}
		c.push_back((sum%10)+'0');
		sum/=10;
	}
	reverse(c.begin(), c.end());
	return c;
}

int cmp(string a, string b){
	int A, B, i;
	if(a.length()>b.length()) return 1;
	else if(a.length()<b.length()) return -1;
	else{
		for(i=0; i<a.length(); i++)
			if(a[i]!=b[i]) break;
		A=a[i]-'0'; B=b[i]-'0';
		if(A>B) return 1;
		else if(A<B) return -1;
		else return 0;
	}
}

int ub(string s){
	int p=1, q=500, m, t;
	while(p<q){
		m=(p+q)/2;
		t=cmp(fib[m], s);
		if(t==1) q=m;
		else p=m+1;
	}
	return q;
}

int lb(string s){
	int p=1, q=500, m, t;
	while(p<q){
		m=(p+q)/2;
		t=cmp(fib[m], s);
		if(t==1||t==0) q=m;
		else p=m+1;
	}
	return q;
}

int main(){
	int a, b, i;
	fib[1]="1"; fib[2]="2";
	for(i=3; i<=500; i++) fib[i]=pl(fib[i-1], fib[i-2]);
	string p, q;
	cin>>p>>q;
	while(p!="0"||q!="0"){
		cout<<ub(q)-lb(p)<<"\n";
		cin>>p>>q;
	}
}
