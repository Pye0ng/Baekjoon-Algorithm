#include<iostream>
#include<deque>
#include<cstring>
using namespace std;
deque<int> q;
char s[10];
int n, k;

int main(){
	int i;
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(i=1; i<=n; i++){
		cin>>s;
		if(!strcmp(s, "push")){
			cin>>k;
			q.push_back(k);
		}
		else if(!strcmp(s, "pop")){
			if(q.empty()) cout<<"-1\n";
			else{
				cout<<q.front()<<"\n";
				q.pop_front();
			}
		}
		else if(!strcmp(s, "size")) cout<<q.size()<<"\n";
		else if(!strcmp(s, "empty")) cout<<q.empty()<<"\n";
		else if(!strcmp(s, "front")){
			if(q.empty()) cout<<"-1\n";
			else cout<<q.front()<<"\n";
		}
		else if(!strcmp(s, "back")){
			if(q.empty()) cout<<"-1\n";
			else cout<<q.back()<<"\n";
		}
	}
}
