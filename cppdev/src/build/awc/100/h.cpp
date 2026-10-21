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

vector<bool> visited;
vector<vector<pll>> g;
vector<ll> ans;

void dfs(ll v){
  if(visited.at(v)) return;
  visited.at(v) = true;
  ans.push_back(v);

  bool b = false;
  for(auto bu : g.at(v)){
    if(b) break;
    if(visited.at(bu.second)) continue;
    dfs(bu.second);
    b = true;
  }
}

void solve(){
  int n, m; cin >> n >> m;
  visited.assign(n, false);
  g.resize(n);

  vector<ll> b(n);
  rep(i, n) cin >> b.at(i);

  rep(i, m){
    ll u, v; cin >> u >> v;
    u--; v--;
    g.at(u).emplace_back(b.at(v), v);
  }

  rep(i, n){
    sort(g.at(i).rbegin(), g.at(i).rend());
  }

  vector<pair<ll, ll>> b2(n);
  rep(i, n){
    if(i == 0) b2.at(i) = {INFL, i};
    else b2.at(i) = {b.at(i), i};
  }
  sort(b2.rbegin(), b2.rend());

  rep(i, n){
    dfs(b2.at(i).second);
  }

  rep(i, ans.size()){
    if(i) cout << " ";
    cout << ans.at(i)+1;
  }
  cout << endl;

}

int main() {

  solve();

  return 0;
}
