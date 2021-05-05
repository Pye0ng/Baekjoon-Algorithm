#include<stdio.h>
#include<math.h>
int n;
char d[100][100];

bool check(int a, int b, int size){
	int s=d[a][b];
	for(int i=a; i<a+size; i++)
		for(int j=b; j<b+size; j++)
			if(d[i][j]!=s) return 1;
	return 0;
}

void tr(int a, int b, int size){
	if(size==1){
		printf("%d", d[a][b]-48);
		b++;
		printf("%d", d[a][b]-48);
		a++; b--;
		printf("%d", d[a][b]-48);
		b++;
		printf("%d", d[a][b]-48);
	}
	else{
		if(check(a, b, size)){
			printf("(");
			if(size==2) tr(a, b, 1);
			else{
				tr(a, b, size/2);
				tr(a, b+size/2, size/2);
				tr(a+size/2, b, size/2);
				tr(a+size/2, b+size/2, size/2);
			}
			printf(")");
		}
		else printf("%d", d[a][b]-48);
	}
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%s", d[i]);
	tr(0, 0, n);
}
