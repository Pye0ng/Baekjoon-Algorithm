#include<stdio.h>
#include<algorithm>
using namespace std;
int a[10]; 

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		for(int j=0; j<10; j++) scanf("%d", &a[j]);
		sort(a, a+10);
		printf("%d\n", a[7]);
	}
}
