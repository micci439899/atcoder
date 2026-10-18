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
int ctoi(char c){return int(c-'0');}
char itoc(int x){return x+'0';}

vector<ll> a;
vector<vector<ll>> g;

set<ll> st;
ll cnt = 0;
vector<bool> ans;

void dfs(ll v, ll prev){
  bool found = false;
  auto it = st.find(a.at(v));
  if(it != st.end()){
    found = true;
  }else{
    st.insert(a.at(v));
  }

  if(found) cnt++;
  if(cnt > 0) ans.at(v) = true;

  for(ll u : g.at(v)){
    if(u == prev) continue;
    dfs(u, v);
  }

  // 帰りがけ
  if(found) cnt--;
  if(!found) st.erase(a.at(v));
}

void solve(){
  ll n;
  cin >> n;

  a.resize(n);
  g.resize(n);
  ans.assign(n, false);

  rep(i, n) cin >> a.at(i);

  rep(i, n-1){
    ll u, v; cin >> u >> v; u--; v--;
    g.at(u).push_back(v);
    g.at(v).push_back(u);
  }

  dfs(0, -1);

  rep(i, n){
    out_yn(ans.at(i));
  }
}


int main() {

  solve();

  return 0;
}
