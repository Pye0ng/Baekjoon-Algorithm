#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	char c[22];
	int t, i;
	scanf("%d", &t);
	while(t--){
		vector<char> v;
		scanf("%s", c);
		for(i=0; c[i]!='\0'; i++) v.push_back(c[i]);
		sort(v.begin(), v.end());
		do{
			for(i=0; i<v.size(); i++) printf("%c", v[i]);
			printf("\n");
		}while(next_permutation(v.begin(), v.end()));
	}
}
