# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

ll mod = 1e9 + 7;

ll powmod(ll x, ll y){
  if(y == 0LL) return 1LL;

  if(y%2LL == 0LL){
    ll z = powmod(x, y/2LL)%mod;
    return (z * z)%mod;
  }else{
    ll z = powmod(x, y/2LL)%mod;
    // return ((x%mod)*(z%mod)*(z%mod))%mod;
    return (((x*z)%mod)*z)%mod;
  }
}

// ll powmod2(ll x, ll y){
//   ll ans = 1LL;
//   while(y != 0){
//     if(y%2 == 1){
//       ans = ans * x % mod;
//     }
//     x = x*x % mod;
//     y /= 2;
//   }
//   return ans;
// }


int main() {
  ll n, k;
  cin >> n >> k;

  if(n == 1){
    cout << k << endl;
    return 0;
  }

  if(n == 2){
    if(k == 1){
      cout << 0 << endl;
    }else{
      cout << (k*(k-1))%mod << endl;
    }
    return 0;
  }

  if(k < 3){
    cout << 0 << endl;
    return 0;
  }

  ll ans = (((k * (k-1))%mod) * powmod(k-2, n-2))%mod;
  cout << ans << endl;





  return 0;  
}
