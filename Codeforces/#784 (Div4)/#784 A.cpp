#include<stdio.h>
#include<vector>
#define x first
#define y second
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int main(){
	int n, m, t, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &m);
		if(m<=1399) t=4;
		else if(m<=1599) t=3;
		else if(m<=1899) t=2;
		else t=1;
		printf("Division %d\n", t);
	}	
}
