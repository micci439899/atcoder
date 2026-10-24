// The template file is below
// https://github.com/micci439899/atcoder

#include <bits/stdc++.h>
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
template<class T>ostream&operator<<(ostream&os, const multiset<T>&st){os<<"{";int idx=0;for(auto &e : st){cout << e;if(idx != st.size()-1){cout << ",";}idx++;}os<<"}";return os;}
template<class T, class U>ostream&operator<<(ostream&os, map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}
int ctoi(char c){return int(c-'0');} // e.g.) a -> 49, 1 -> 1
char itoc(int x){return x+'0';}

void solve(){
  int n, q; cin >> n >> q;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  // 0, a_0, a_0+a_1, ..., a_0+...+a_{n-1}
  vector<ll> cum_a(n+1, 0);
  rep(i, n) cum_a.at(i+1) = cum_a.at(i) + a.at(i);

  // 0, a_0, (a_0)+(a_0+a_1), ..., (a_0)+(a_0+a_1)+...+(a_0+...+a_{n-1})
  vector<ll> cumcum_a(n+2, 0);
  rep(i, n+1) cumcum_a.at(i+1) = cumcum_a.at(i) + cum_a.at(i);
  cumcum_a.erase(cumcum_a.begin());

  // 0, 1, 1+2, 1+2+3, ...
  vector<ll> len_a(n+1, 0);
  rep(i, n) len_a.at(i+1) = len_a.at(i) + i+1;

  while(q--){
    ll l, r; cin >> l >> r;
    l--; r--;

    ll l_idx = upper_bound(len_a.begin(), len_a.end(), l) - len_a.begin()-1;
    ll l_idx2 = len_a.at(l_idx);
    ll l_sm1 = cumcum_a.at(l_idx);
    ll l_sm2 = l_sm1 + cum_a.at(l-l_idx2);

    ll r_idx = upper_bound(len_a.begin(), len_a.end(), r+1) - len_a.begin()-1;
    ll r_idx2 = len_a.at(r_idx);
    ll r_sm1 = cumcum_a.at(r_idx);
    ll r_sm2 = r_sm1 + cum_a.at(r+1-r_idx2);

    ll ans = r_sm2 - l_sm2;
    cout << ans << endl;
  }
}

int main() {
  solve();
  return 0;
}
