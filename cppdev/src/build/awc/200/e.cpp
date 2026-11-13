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
template<class T, class U>ostream&operator<<(ostream&os, map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p.first<<":"<<p.second;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}
template<class T, class U>ostream&operator<<(ostream&os, unordered_map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p.first<<":"<<p.second;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}
int ctoi(char c){return int(c-'0');} // e.g.) a -> 49, 1 -> 1
char itoc(int x){return x+'0';}

void solve(){
  ll n, m; cin >> n >> m;

  vector<ll> s(n);
  rep(i, n) cin >> s.at(i);
  sort(s.rbegin(), s.rend());

  ll r_sm = 0;
  vector<tuple<ll, ll, ll>> pri(m);
  rep(i, m){
    ll p, r; cin >> p >> r;
    pri.at(i) = {p, r, i};
    r_sm += r;
  }

  if(r_sm > n){
    cout << -1 << endl;
    return;
  }

  sort(pri.begin(), pri.end(), [&](const tuple<ll, ll, ll> &a, const tuple<ll, ll, ll> &b){
    auto [pa, ra, ia] = a;
    auto [pb, rb, ib] = b;

    if(pa == pb){
      return ia < ib;
    }else{
      return pa > pb;
    }
  });


  vector<pll> ans(m);
  ll s_idx = 0;
  rep(i, m){
    auto [p, r, idx] = pri.at(i);

    ll ans0 = 0;
    rep(j, r){
      ans0 += s.at(s_idx);
      s_idx++;
    }
    // cout << ans << endl;
    ans.at(i) = {idx, ans0};
  }
  sort(ans.begin(), ans.end());

  rep(i, m){
    cout << ans.at(i).second << endl;
  }


}

int main() {
  solve();
  return 0;
}
