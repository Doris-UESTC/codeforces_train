#include<bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2)%1000000007;
  if (b % 2)
    return ((res * res)%1000000007 * a) % 1000000007;
  else
    return (res * res) % 1000000007;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        long long ans=binpow(n,k)%1000000007;
        cout<<ans<<endl;
    }
}