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

/*
struct Edge {
  ll cost;
  ll from;
  ll to;
};
*/

void solve(){
  ll n, m, y; cin >> n >> m >> y;

  // vector<vector<Edge>> g(n+1);
  vector<vector<tuple<ll, ll, ll>>> g(n+1);
  rep(i, m){
    ll u, v, t; cin >> u >> v >> t;
    u--; v--;
    // Edge edge1 = {v, t};
    // Edge edge2 = {u, t};
    // Edge edge1 = {u, v, t};
    // Edge edge2 = {v, u, t};
    tuple<ll, ll, ll> edge1 = {u, v, t};
    tuple<ll, ll, ll> edge2 = {v, u, t};
    g.at(u).push_back(edge1);
    g.at(v).push_back(edge2);
  }

  rep(i, n){
    ll x; cin >> x;
    // g.at(u).push_back({n, x});
    // g.at(n).push_back({u, x+y});
    g.at(i).push_back({i, n, x});
    g.at(n).push_back({n, i, x+y});
  }

  vector<ll> dist(n+1, INFL);
  dist.at(0) = 0;
  // queue<Edge> q;
  // min_priority_queue<pair<ll, Edge>> pq;
  min_priority_queue<pair<ll, tuple<ll, ll, ll>>> pq;
  // for(Edge edge : g.at(0)){
  //   pq.emplace(0LL, edge);
  // }

  // vector<Edge> edges = g.at(0);
  vector<tuple<ll, ll, ll>> edges = g.at(0);
  for(auto edge : edges){
    pair<ll, tuple<ll, ll, ll>> pr = {0LL, edge};
    // pq.push({0LL, edge});
    pq.push(pr);
  }
/*
  rep(i, g.at(0).size()){
    pq.emplace(0LL, g.at(0).at(i));
  }
  */


  while(!pq.empty()){
    auto [d, edge] = pq.top(); pq.pop();
    auto [from, to, cost] = edge;

    // if(dist.at(edge.from) + edge.cost < dist.at(edge.to)){
    if(chmin(dist.at(to), d + cost)){
      for(auto edge2 : g.at(from)){
        pq.emplace(dist.at(to), edge2);
      }
    }
  }


  rep(i, n){
    if(i == 0) continue;
    if(i > 1) cout << " ";
    cout << dist.at(i);
  }
  cout << endl;




}

int main() {

  solve();

  return 0;
}
