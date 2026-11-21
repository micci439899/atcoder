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

const ll INFL = 1LL<<60;

void solve(){
  ll n, m; cin >> n >> m;

  vector<vector<ll>> c(n, vector<ll>(m));
  rep(i, n)rep(j, m) cin >> c.at(i).at(j);

  vector<vector<ll>> dp(n, vector<ll>(m, INFL));
  rep(j, m){
    dp.at(0).at(j) = c.at(0).at(j);
  }




/*
  // O(NM^2)...
  rep(i, n-1){
    rep(j, m){
      ll mi = INFL;
      for(int k = 0; k <= j; k++){
        mi = min(mi, dp.at(i).at(k));
      }
      chmin(dp.at(i+1).at(j), c.at(i).at(j)+mi);
    }
  }
*/


  rep(i, n-1){
    ll mi = INFL;
    rep(j, m){
      mi = min(mi, dp.at(i).at(j));
      dp.at(i+1).at(j) = mi + c.at(i+1).at(j);
      // chmin(dp.at(i+1).at(j), dp.at(i).at(j)+c.at(i+1).at(j));
    }
  }

/*
  rep(i, n){
    if(i == 0) continue;
    ll mi = INFL;
    for(int j = 0; j < m; j++){
      // chmin(dp.at(i).at(j), dp.at(i-1).at(j) + c.at(i).at(j));
      // mi = min(mi, dp.at(i-1).at(j) + c.at(i).at(j));
      mi = min(mi, dp.at(i-1).at(j));
      dp.at(i).at(j) = mi + c.at(i).at(j);
    }
  }
*/
  // debug(dp);
  // cout << dp.at(n-1).at(m-1) << endl;

  ll ans = INFL;
  rep(i, m) chmin(ans, dp.at(n-1).at(i));
  cout << ans << endl;

}

int main() {
  solve();
  return 0;
}
