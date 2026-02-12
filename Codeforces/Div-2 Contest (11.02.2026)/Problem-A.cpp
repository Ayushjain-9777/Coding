#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll Md1 = 1e9 + 7;
const ll Md2 = 998244353;

ll countSum(ll n) {
     ll sum{};
     while(n) {
          sum += n % 10;
          n /= 10;
     }
     return sum;
}

int main() {
     ll t; cin >> t;
     while(t--) {
          ll x; cin >> x;
          ll ans{};
          for(ll i = 0; i < 200; ++i){
              ll cand = x + i;
              ll sm = countSum(cand); 
              if(cand - sm == x) ans++;
          }
          cout << ans << "\n";

     }


    return 0;
}