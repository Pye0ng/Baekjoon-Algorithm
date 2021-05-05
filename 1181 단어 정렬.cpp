#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; 
vector<string> v;

bool check(string a, string b){
	for(int i=0; i<v.size(); i++){
		if(a.size()==b.size()) return a<b;
		else return a.size()<b.size();
	}
}

int main(){
	int n, i, j;
	string ch;
	scanf("%d", &n);
	v.resize(n);
	for(i=0; i<v.size(); i++) cin>>v[i];
	sort(v.begin(), v.end(), check);
	for(i=0; i<v.size(); i++){
		if(ch==v[i]) continue;
		cout<<v[i]<<'\n';
		ch=v[i];
	}
}
