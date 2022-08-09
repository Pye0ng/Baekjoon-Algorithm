#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;
char s[1001000];
int a[30];

int main(){
	int i;
	scanf("%s", s);
	for(i=0; s[i]!='\0'; i++){
		if(s[i]>='a') a[s[i]-'a']++;
		else a[s[i]-'A']++;
	}
	for(i=0; i<26; i++) v.push_back(pii(a[i], i));
	sort(v.begin(), v.end());
	printf("%c", v[25].first==v[24].first?'?':'A'+v[25].second);
}
