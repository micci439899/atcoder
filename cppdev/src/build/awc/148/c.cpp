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
  ll n, t, s; cin >> n >> t >> s;

  vector<pll> cp(n);
  vector<vector<ll>> dp(n, vector<ll>(t-s+1, 0));
  rep(i, n){
    ll c, p; cin >> c >> p;
    cp.at(i) = {c, p};
  }


/*
  rep(i, n){
    auto [c, p] = cp.at(i);
    rep(j, t-s+1){
      if(j+c < t-s+1){
        dp.at(i).at(j+c) = max(dp.at(i).at(j) + p, dp.at(i).at(j+c));
        if(dp.at(i).at(j+c) == 400){
          debug(c);
          debug(p);
          debug(dp.at(i));
        }
      }
    }
  }
*/

  rep(i, n){
    auto [c1, p1] = cp.at(i);
    rep(j, n){
      if(i == j) continue;
      // auto [c2, p2] = cp.at(j);

      rep(k, t-s+1){
        if(k+c1 < t-s+1){
          dp.at(j).at(k+c1) = max(dp.at(j).at(k+c1), dp.at(i).at(k) + p1);
        }
      }
    }
  }


  // debug(dp);

  ll ans = 0;
  rep(i, n)rep(j, t-s+1){
    chmax(ans, dp.at(i).at(j));
  }
  cout << ans << endl;

}

int main() {

  solve();

  return 0;
}
