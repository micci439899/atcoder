# include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define debug(x) cerr << #x << " " << x << " " << endl;

template<class T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T>bool chmax(T&a, T b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T&a, T b){if(b<a){a=b;return true;}return false;}

template<class T, class U>ostream&operator<<(ostream&os, pair<T,U>p){os<<"("<<p.first << "," << p.second<<")";return os;}
template<class T>ostream&operator<<(ostream&os, const vector<T>&v){os<<"[";for(int i = 0; i < v.size(); i++){cout << v.at(i);if(i != v.size()-1){cout << ",";}}os<<"]";return os;}
template<class T>ostream&operator<<(ostream&os, const set<T>&st){os<<"{";int idx=0;for(auto &e : st){cout << e;if(idx != st.size()-1){cout << ",";}idx++;}os<<"}";return os;}
template<class T, class U>ostream&operator<<(ostream&os, map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}
int ctoi(char c){return int(c-'0');} // e.g.) a -> 49, 1 -> 1
char itoc(int x){return x+'0';}

void solve(){
  ll n, q; cin >> n >> q;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  // l = kで固定すると
  // \sum_{r=k}^{R_i} \sum_{j=k}^r A_j
  // = \sum_{r=k}^{R_i} (A_k + ... + A_r)
  // =   A_k
  //   + A_k + A_{k+1}
  //   ...
  //   + A_k + ... + A_{R_i}
  // l=kのときA_kは(R_i-k+1)個
  // l=k-1のときもA_kは(R_i-k+1)個
  // ...
  // l=L_iのときA_kは(R_i-Li+1)個
  // すなわち、A_kは(k-Li+1)(R_i-k+1)個
  // \sum k=Li^Ri (k-Li+1)(R_i-k+1) A_k
  // = \sum (-k^2 A_k + (R_i+Li) k A_k + (-Li+1)(R_i+1) A_k)
  vector<ll> cum_a0(n+1, 0);
  vector<ll> cum_a1(n+1, 0);
  vector<ll> cum_a2(n+1, 0);
  rep(i, n){
    cum_a2.at(i+1) += cum_a2.at(i) + 1LL*i*i*a.at(i);
    cum_a1.at(i+1) += cum_a1.at(i) + i*a.at(i);
    cum_a0.at(i+1) += cum_a0.at(i) + a.at(i);
  }

  while(q--){
    ll l, r; cin >> l >> r;
    l--; r--;

    ll a2 = cum_a2.at(r+1) - cum_a2.at(l);
    ll a1 = cum_a1.at(r+1) - cum_a1.at(l);
    ll a0 = cum_a0.at(r+1) - cum_a0.at(l);

    ll ans = - a2 + (r+l) * a1 + (r+1)*(-l+1) * a0;
    cout << ans << endl;
  }
}

int main() {

  solve();

  return 0;
}