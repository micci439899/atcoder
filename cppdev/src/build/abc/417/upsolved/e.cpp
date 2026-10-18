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

bool dfs(vector<vector<int>> &g, set<int> &st, vector<int> &path, int u, int y){
  path.push_back(u);
  st.insert(u);
  if(u == y){
    return true;
  }
  for(int v : g.at(u)){
    if(st.count(v)){
      continue;
    }
    bool b = dfs(g, st, path, v, y);
    if(b) return true;
  }
  path.pop_back();
  return false;
}

void testcase(){
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  x--; y--;

  vector<vector<int>> g(n);
  rep(i, m){
    int u, v; cin >> u >> v;
    u--; v--;
    g.at(u).push_back(v);
    g.at(v).push_back(u);
  }
  rep(i, n){
    sort(g.at(i).begin(), g.at(i).end());
  }

  vector<int> path;
  set<int> st;
  dfs(g, st, path, x, y);
  rep(i, path.size()){
    if(i) cout << " ";
    cout << path.at(i) + 1;
  }
  cout << endl;

}

void solve(){
  int t; cin >> t;
  while(t--){
    testcase();
  }
}

int main() {

  solve();

  return 0;
}