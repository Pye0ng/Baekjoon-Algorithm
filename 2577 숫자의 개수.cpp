#include<stdio.h>
#include<math.h>
int s[11];
int num(int m){	return floor(log10(m)); }

int main(){
	int a, b, c, n;
	scanf("%d %d %d", &a, &b, &c);
	n=a*b*c;
	for(int i=1; i<=num(a*b*c)+1; i++){
		s[n%10]++;
		n/=10;
	}
	for(int i=0; i<10; i++) printf("%d ", s[i]);
}
