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
vector<bool> visited;
vector<bool> ans;


//void dfs(ll u, set<ll> st, bool is_ok){
void dfs(ll u, set<ll> st){
  visited.at(u) = true;

  if(a.at(u) == 5){
    debug(u);
    debug(ans);
    debug(st);
    // debug(is_ok);
  }


  for(ll v : g.at(u)){
    if(visited.at(v)) continue;
    // if(is_ok) ans.at(v) = true;
    if(st.find(a.at(v)) != st.end()){
      if(a.at(v) == 5){
        cout<< "found" << endl;
        debug(v);
        debug(st);        
      }
      ans.at(v) = true;
      // is_ok = true;
    }
    st.insert(a.at(v));
    // dfs(v, st, is_ok);
    dfs(v, st);
  }
}

void solve(){
  ll n;
  cin >> n;

  g.resize(n);
  visited.assign(n, false);
  ans.assign(n, false);
  a.resize(n);

  rep(i, n) cin >> a.at(i);

  rep(i, n-1){
    ll u, v;
    cin >> u >> v;
    u--; v--;
    g.at(u).push_back(v);
    g.at(v).push_back(u);
  }


  set<ll> st;
  st.insert(a.at(0));
  // dfs(0, st, false);
  dfs(0, st);

  rep(i, n){
    out_yn(ans.at(i));
  }


}


int main() {

  solve();

  return 0;
}
