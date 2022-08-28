#include<iostream>
using namespace std;
char a[2000200], b[1000100];
int t, p[1000100];

int gcd(int x, int y){
    if(y==0) return x;
    return gcd(y, x%y);
}

int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, i, j;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>a[i];
        a[n+i]=a[i];
    }
    for(i=0; i<n; i++) cin>>b[i];
    for(i=1, j=0; i<n; i++){
        while(j>0&&b[i]!=b[j]) j=p[j-1];
        if(b[i]==b[j]) p[i]=++j;
    }
    for(i=0, j=0; i<2*n-1; i++){
        while(j>0&&a[i]!=b[j]) j=p[j-1];
        if(a[i]==b[j]){
            if(j==n-1){ t++; j=p[j]; }
            else j++;
        }
    }
    cout<<t/gcd(t, n)<<"/"<<n/gcd(t, n);
}