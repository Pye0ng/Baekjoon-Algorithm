#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
char key[12], s[210];
vector<pair<char, int> > v;
vector<pair<int, int> > p;

bool cmp1(pair<char, int> a, pair<char, int> b){
	if(a.first<b.first) return 1;
	else if(a.first==b.first) return a.second<b.second;
	else return 0;
}

bool cmp2(pair<int, int> a, pair<int, int> b){
	if(a.first<b.first) return 1;
	else if(a.first==b.first) return a.second<b.second;
	else return 0;
}

int main(){
	int len_k, len_s, m, i, j;
	scanf("%s", key); len_k=strlen(key);
	scanf("%s", s); len_s=strlen(s);
	for(i=0; key[i]!='\0'; i++) v.push_back({key[i], i});
	sort(v.begin(), v.end(), cmp1);
	for(i=0; i<v.size(); i++) p.push_back({v[i].second, i});
	sort(p.begin(), p.end(), cmp2);
	m=(int)len_s/len_k;
	for(i=0; i<m; i++)
		for(j=0; j<p.size(); j++) printf("%c", s[m*p[j].second+i]);
}
