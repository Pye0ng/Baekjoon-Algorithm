#include<stdio.h>
#include<algorithm>
int n, k, cnt, d[101];

int main(){
	int i, j, lb=-1;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &d[i]);
	std::sort(d, d+n);
	scanf("%d", &k);
	for(i=0; i<n-1; i++){
		if(d[i]==k||d[i+1]==k){
			printf("0");
			return 0;
		}
		if(d[i]<k&&k<d[i+1]) lb=i;
	}
	if(lb==-1){
		for(i=1; i<=k; i++)
			for(j=k; j<d[0]; j++){
				if(i==j) continue;
				else cnt++;
			}	
	}
	else{
		for(i=d[lb]+1; i<=k; i++)
			for(j=k; j<d[lb+1]; j++){
				if(i==j) continue;
				else cnt++;
			}
	}
	printf("%d", cnt);
}
