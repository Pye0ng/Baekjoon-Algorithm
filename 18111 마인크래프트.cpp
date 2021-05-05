#include<stdio.h>
int d[250001];
int min=256, max;
int el, ad, hg;
int tm=128000000;

int main(){
	int n, m, b, i, j;
	scanf("%d %d %d", &n, &m, &b);
	for(i=0; i<n*m; i++){
			scanf("%d", &d[i]);
			if(d[i]>max) max=d[i];
			if(d[i]<min) min=d[i];
	}
	for(i=min; i<=max; i++){
		ad=0; el=0;
		for(j=0; j<n*m; j++){
				if(i>=d[j]) ad+=i-d[j];
				else el+=d[j]-i;
		}
		if(el*2+ad<=tm&&ad<=el+b){
			tm=el*2+ad;
			hg=i;
		}
	}
	printf("%d %d", tm, hg); 
}
