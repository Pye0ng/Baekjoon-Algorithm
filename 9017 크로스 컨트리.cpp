#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v;
int s[210], p1[210], p2[210], f[210]; 

int main(){
	int n, t, m, sc, w, i;
	scanf("%d", &n);
	s[0]=100000; f[0]=10001;
	while(n--){
		m=0; sc=1; scanf("%d", &t);
		for(i=1; i<=t; i++){
			scanf("%d", &w);
			v.push_back(w);
			if(w>m) m=w;
			p1[w]++;
		} 
		for(i=0; i<t; i++){
			if(p1[v[i]]!=6) continue;
			if(p2[v[i]]<4) s[v[i]]+=sc;
			else if(p2[v[i]]==4) f[v[i]]=sc;
			sc++; p2[v[i]]++;
		} w=0;
		for(i=1; i<=m; i++){
			if(p1[i]!=6) continue;
			if(s[i]<s[w]||(s[i]==s[w]&&f[i]<f[w])) w=i;
		}
		printf("%d\n", w);
		for(i=1; i<=m; i++){ s[i]=0; p1[i]=0; p2[i]=0; f[i]=0; }
		v.clear();
	}
}
