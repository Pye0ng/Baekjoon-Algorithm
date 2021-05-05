#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
	int a[3]={1, 1, 1};
	while(a[0]&&a[1]&&a[2]){
		scanf("%d %d %d", &a[0], &a[1], &a[2]);
		if(!a[0]&&!a[1]&&!a[2]) break;
		sort(a, a+3);
		if(a[2]*a[2]==a[1]*a[1]+a[0]*a[0]) printf("right\n");
		else printf("wrong\n");	
	}
}
