#include<stdio.h>
int sq[101][101], sum;

int main(){
	int i, j, a, b, c, d;
	for(i=1; i<=4; i++){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for(j=a; j<c; j++)
			for(int k=b; k<d; k++) sq[j][k]=1;
	}
	for(i=1; i<=100; i++)
		for(j=1; j<=100; j++)
			if(sq[i][j]) sum++;
	printf("%d", sum);
}
