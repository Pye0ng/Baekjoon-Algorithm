#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
	int a, b, c, d, e, f, p, q;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	p=max(abs(e-a), abs(f-b));
	q=abs(e-c)+abs(f-d);
	printf("%s", p==q?"tie":p>q?"daisy":"bessie");
}
