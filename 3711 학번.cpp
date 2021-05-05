#include<stdio.h>
int k, g[301], c[301];

bool ch1(){
	for(int i=0; i<k-1; i++)
		for(int j=i+1; j<k; j++)
			if(c[i]==c[j]) return 0;
	return 1;
}

bool ch2(int n){
	for(int i=0; i<k; i++) c[i]=g[i]%n;
	if(ch1()) return 1;
	else return 0;
}

int main(){
	int n, i;
	scanf("%d", &n);
	while(n){
		scanf("%d", &k);
		for(i=0; i<k; i++) scanf("%d", &g[i]); 
		for(i=1; i<1000000; i++){
			if(ch2(i)){
				printf("%d\n", i);
				break;
			}
		}
		n--;
	}
}
