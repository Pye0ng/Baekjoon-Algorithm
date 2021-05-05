#include<stdio.h>
#include<iostream>
#include<string>
#include<deque>
using namespace std;
deque<int> q, zero;
int t, n, rev=1;

int D(string p){
	int cnt=0;
	for(int i=0; p[i]!='\0'; i++)
		if(p[i]=='D') cnt++;
	return cnt;
}

int main(){
	int i, j;
	char c;
	scanf("%d", &t);
	for(i=1; i<=t; i++){
		rev=1, j=1; q=zero;
		string p, in;
		cin>>p>>n>>in;
		int d=D(p);
		while(j<in.length()){
			string temp="\n";
			while(1){
				if(in[j]==','||in[j]==']') break;
				else{
					temp+=in[j];
					j++;
				}
			}
			if(temp=="\n") break;
			else q.push_back(stoi(temp));
			j++;
		}
		if(d>n){
			cout<<"error"<<'\n';
			continue;
		}
		else if((d==n&&n!=0)||n==0){
			cout<<"[]"<<'\n';
			continue;
		}
		for(j=0; p[j]!='\0'; j++){
			if(p[j]=='R') rev=-rev;
			else{
				if(rev==1) q.pop_front();
				else q.pop_back();
				n--;
			}
		}
		printf("[");
		for(j=0; j<n-1; j++){
			if(rev==1){	
				cout<<q.front()<<',';
				q.pop_front();
			}
			else{
				cout<<q.back()<<',';
				q.pop_back();
			}
		}
		cout<<q.front()<<']'<<'\n';
	}
}
