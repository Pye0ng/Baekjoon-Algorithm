#include<iostream>
#include<memory.h>
#include<vector>
#include<string>
using namespace std;
vector<int> v[30];
string s;
bool ch, visited[30];
int n;

void find(int a, int k){
	visited[a]=1;
	if(a==k) ch=1;
	else{
		for(int i=0; i<v[a].size(); i++)
			if(!visited[v[a][i]]) find(v[a][i], k);
	}
}

int main(){
	int i;
	cin>>n;
	cin.ignore();
	for(i=1; i<=n; i++){
		getline(cin, s); 
		v[s[0]-96].push_back(s[5]-96);
	}
	cin>>n;
	cin.ignore();
	for(i=1; i<=n; i++){
		ch=0;
		getline(cin, s);
		find(s[0]-96, s[5]-96);
		memset(visited, 0, sizeof(visited));
		if(ch) cout<<"T\n";
		else cout<<"F\n";
	}
}
