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

  vector<pll> a(n);
  rep(i, n){
    ll ai; cin >> ai;
    a.at(i) = {ai, i};
  }
  vector<pll> aa = a;
  sort(a.rbegin(), a.rend());

  vector<vector<ll>> g(n);
  rep(i, m){
    ll u, v; cin >> u >> v;
    u--; v--;
    g.at(u).push_back(v);
    g.at(v).push_back(u);
  }

  vector<ll> ans(n, -1);

  // debug(a);
  // debug(g);

  rep(i, n){
    auto [ai, idx] = a.at(i);

    // debug(ai);
    // debug(idx);

    if(chmax(ans.at(idx), ai)){
      queue<ll> que;
      for(ll u : g.at(idx)){
        // debug(u);
        que.push(u);
        // auto [_, idx] = aa.at(u);
        // debug(u);
        // debug(idx);
        // que.push(idx);
      }

      while(!que.empty()){
        ll u = que.front(); que.pop();
        // debug(u);
        if(chmax(ans.at(u), ai)){
          for(ll v : g.at(u)){
            if(ans.at(v) > 0) continue;
            que.push(v);
          }
        }
      }
    }

    // debug(ans);
  }

  rep(i, n){
    cout << ans.at(i) << endl;
  }
}

int main() {
  solve();
  return 0;
}
