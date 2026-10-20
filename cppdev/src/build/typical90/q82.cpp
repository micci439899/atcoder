# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

const ll mod = 1e9 + 7;

vector<unsigned long long> pows;

void initialize(){
  pows.push_back(1ULL);
  for(int i = 1; i <= 19; i++){
    ll p = pows.at(i-1) * 10ULL;
    pows.push_back(p);
  }
}


ll modpow(ll x, ll y){
  if(y == 0LL) return 1LL;

  if(y%2LL == 0LL){
    ll z = modpow(x, y/2LL)%mod;
    return (z * z)%mod;
  }else{
    ll z = modpow(x, y/2LL)%mod;
    return (((x*z)%mod)*z)%mod;
  }
}

ll modinv(ll a, ll p){
  return modpow(a, p-2);
}

int main() {
  // 1桁
  // 1 2 2 3 3 3 4 4 4 4 ...
  // のとき
  // 1 + 2 + 3 + 4 + ... + 9
  // = (1 + 9) * (9 - 1 + 1) / 2

  // 2桁
  // 10 10 10 10 10 10 10 10 10 10 ...
  // のとき
  // 2 * 10 + 2 * 11 + ... + 2 * 99
  // = 2 * (10 + 11 + ... + 99)
  // = 2 * (10 + 99) * (99 - 10 + 1) / 2

  // k桁
  // k * 10^(k-1) + k * (10^(k-1)+1) + ... + k * (10^(k) - 1)
  // = k * (10^(k-1) + ... + 10^k-1)
  // = k * (10^(k-1) + 10^k-1) * (10^k - 1 - 10^(k-1) + 1) / 2
  // = k * (10^(k-1) + 10^k-1) * (10^k - 10^(k-1)) / 2

  // 18桁
  // 18 * 10^18
  // = 1.8 * 10^19

  unsigned long long l, r;
  cin >> l >> r;

  initialize();

  int l_digit = to_string(l).size();
  int r_digit = to_string(r).size();

  unsigned long long ans = 0;
  for(int i = 1; i <= 19; i++){
    if(i < l_digit) continue;
    if(i > r_digit) break;

    unsigned long long l_val = i == l_digit ? l : pows.at(i-1);
    unsigned long long r_val = i == r_digit ? r : pows.at(i)-1;

    //unsigned long long sm_tmp = ((l_val + r_val) * (r_val - l_val + 1)) % mod;
    unsigned long long sm_tmp1 = (l_val + r_val) % mod;
    unsigned long long sm_tmp2 = (r_val - l_val + 1) % mod;
    unsigned long long sm_tmp = (sm_tmp1 * sm_tmp2) % mod;
    unsigned long long sm = (sm_tmp * modinv(2, mod)) % mod;
    ans = (ans + (i * sm)) % mod;
  }


  cout << ans << endl;





  return 0;  
}
