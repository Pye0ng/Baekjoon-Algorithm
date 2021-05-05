#include<stdio.h>
#include<vector>
using namespace std;

vector<int> v(1010);
int n, k, cnt, sz=1;

int lower_bound(int s){
	if(s>v[0]) return 0;
	for(int i=1; i<sz; i++)
		if(v[i-1]>s&&s>v[i]) return i;
	return -1;
}

int main(){
	int i;
	scanf("%d", &n);
	v[0]=1010;
	for(i=1; i<=n; i++){
		scanf("%d", &k);
		if(k<v[sz-1]){
			v[sz]=k;
			sz++;
			cnt++;
		}
		else{
			int s=lower_bound(k);
			if(s!=-1) v[s]=k;
		} 
	}
	printf("%d", cnt);
}
