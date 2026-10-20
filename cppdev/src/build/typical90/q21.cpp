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

// 下記を参考
// https://drken1215.hatenablog.com/entry/2023/05/06/133900
struct StronglyConnectedComponent {

  vector<vector<int>> g, rg;

  vector<vector<int>> scc;
  vector<int> cmp;
  vector<vector<int>> dag;

  StronglyConnectedComponent(int n) : g(n), rg(n) {}

  void add_edge(int u, int v) {
    g.at(u).push_back(v);
    rg.at(v).push_back(u);
  }

  vector<bool> visited;
  vector<int> vs, rvs;
  void dfs(int v) {
    visited.at(v) = true;
    for(int u : g.at(v)) {
      if(!visited.at(u)) dfs(u);
    }
    vs.push_back(v);
  }
  void rdfs(int v, int k) {
    visited.at(v) = true;
    cmp.at(v) = k;
    for(int u : rg.at(v)) {
      if(!visited.at(u)) rdfs(u, k);
    }
    rvs.push_back(v);
  }

  set<pair<int, int>> new_edges;
  void reconstruct() {
    int n = (int)g.size();
    int dv = (int)scc.size();
    dag.assign(dv, vector<int>());
    new_edges.clear();
    for(int i = 0; i < n; i++) {
      int u = cmp.at(i);
      for(int e : g.at(i)) {
        int v = cmp.at(e);
        if(u == v) continue;
        if(!new_edges.count({u, v})) {
          dag.at(u).push_back(v);
          new_edges.insert({u, v});
        }
      }
    }
  }


  void solve() {
    int n = (int)g.size();
    visited.assign(n, false);
    vs.clear();
    for(int v = 0; v < n; v++) if(!visited.at(v)) dfs(v);

    int k = 0;
    cmp.assign(n, -1);
    visited.assign(n, false);
    for(int i = n-1; i >= 0; i--) {
      if(!visited.at(vs.at(i))) {
        rvs.clear();
        rdfs(vs.at(i), k++);
        scc.push_back(rvs);
      }
    }
    reconstruct();
  }

};

void solve(){
  ll n, m; cin >> n >> m;

  StronglyConnectedComponent scc(n);

  rep(i, m){
    ll a, b; cin >> a >> b;
    a--; b--;
    scc.add_edge(a, b);
  }
  scc.solve();

  ll ans = 0;
  for(vector<int> components : scc.scc){
    ll sz = (ll)components.size();
    ans += sz * (sz - 1) / 2;
  }
  cout << ans << endl;
}

int main() {

  solve();

  return 0;
}
