#include<stdio.h>
#include<algorithm>
using namespace std;
long long int d[100100];

int main(){
	int n, i;
	long long int m;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%lld", &d[i]);
	m=d[0]; d[0]=0;
	sort(d, d+n); 
	for(i=1; i<n; i++){
		if(m>d[i]) m+=d[i];
		else{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
}
