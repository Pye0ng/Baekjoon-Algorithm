#include<iostream>
#include<math.h>
#include<set>
using namespace std;
typedef long double ld;
typedef long long ll;
ld a, b, c, d, x;

ll D(ld p, ld q, ld r){
	ld rt=q*q-4*p*r;
	return rt;
}

int main(){
	cout.precision(9);
	cout<<fixed;
	int t;
	cin>>t; 
	while(t--){
		cin>>a>>b>>c>>d;
		for(int i=0; i<2000001; i++){
			if(a*i*i*i+b*i*i+c*i+d==0) x=i;
			if(a*i*i*i-b*i*i+c*i-d==0) x=-i;
		}
		d=a*x*x+b*x+c; c=a*x+b; b=a;
		set<ld> s;
		s.insert(x);
		if(D(b, c, d)>=0){ 
			s.insert((-c+sqrt(D(b,c,d)))/(2*b));
            s.insert((-c-sqrt(D(b,c,d)))/(2*b));
		}
		for(auto i=s.begin(); i!=s.end(); i++) cout<<*i<<' ';
		cout<<'\n';
	}
}
