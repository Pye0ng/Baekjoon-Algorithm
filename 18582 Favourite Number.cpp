#include<stdio.h>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<ll> v;
set<ll> ans;

int main(){
    ll k, t, i;
    scanf("%lld", &k);
    for(i=1; i*i<=k; i++){
        v.push_back(i*i);
        v.push_back(-i*i);
    }
    sort(v.begin(), v.end());
    for(i=0; v[i]<0; i++)
        if(v[i]+k==*lower_bound(v.begin(), v.end(), v[i]+k)){
            ans.insert(v[i]);
            ans.insert(-v[i]-k);
        }
    for(i=1; i*i<k; i++)
        if(k%i==0&&((k+i*i)/i)%2==0){
            t=((k+i*i)/i)/2;
            ans.insert(-t*t);
            ans.insert(t*t-k);
        }
    printf("%d\n", ans.size());
    for(auto i:ans) printf("%lld\n", i);
}