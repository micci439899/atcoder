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

vector<ll> dijkstra(vector<vector<pll>> &g, ll v){
  ll n = g.size();
  vector<ll> dist(n, INFL);
  dist.at(v) = 0;
  min_priority_queue<pll> pq;
  pq.push({0, v});
  while(!pq.empty()){
    auto [d, u] = pq.top(); pq.pop();

    for(pll p : g.at(u)){
      auto [u2, w] = p;
      ll nd = d + w;

      if(chmin(dist.at(u2), nd)){
        pq.push({nd, u2});
      }
    }
  }
  return dist;
}

void solve(){
  ll n, m; cin >> n >> m;

  vector<vector<pll>> g(n);
  rep(_, m){
    ll a, b, c; cin >> a >> b >> c;
    a--; b--;
    g.at(a).push_back({b, c});
    g.at(b).push_back({a, c});    
  }

  vector<ll> d0 = dijkstra(g, 0);
  vector<ll> d1 = dijkstra(g, n-1);

  rep(i, n){
    ll ans = d0.at(i) + d1.at(i);
    cout << ans << endl;
  }
}

int main() {

  solve();

  return 0;
}
