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

const ll INFL = 1LL<<60;

void solve(){
  ll n, m, s; cin >> n >> m >> s;
  s--;

  vector<vector<pll>> g(n);
  rep(i, m){
    ll u, v, w; cin >> u >> v >> w;
    u--; v--;
    g.at(u).push_back({v, w});
    g.at(v).push_back({u, w});
  }

  vector<ll> dist(n, INFL);
  dist.at(s) = 0;
  min_priority_queue<pll> pq;
  pq.push({0, s});
  while(!pq.empty()){
    auto [d, u] = pq.top(); pq.pop();

    for(pll p : g.at(u)){
      auto [v, w] = p;
      ll nd = d + w;
      if(nd < dist.at(v)){
        dist.at(v) = nd;
        pq.push({nd, v});
      }
    }
  }

  ll ans = 0;
  rep(i, n)if(dist.at(i) != INFL){
    ans += dist.at(i);
  }

  cout << ans << endl;
}

int main() {

  solve();

  return 0;
}
