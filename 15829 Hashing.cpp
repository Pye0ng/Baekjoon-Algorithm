#include<stdio.h>
#include<iostream>
using namespace std;
string a;

int main(){
	int n, i;
	unsigned long long int k=1, sum=0;
	cin>>n>>a;
	for(i=0; i<n; i++){
		sum+=((int)(a[i]-96)*k);
		sum%=1234567891;
		k*=31;
		k%=1234567891;
	}
	cout<<sum;
}
