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

/*
bool is_ok = true;
// ll ans = 0;

void dfs(ll v, vector<vector<ll>> &g, vector<ll> &u, vector<ll> &rank){
  if(u.at(v) < rank.at(v)){
    is_ok = false;
    return;
  }

  for(ll nv : g.at(v)){
    dfs(nv, g, u, rank);
  }
}
*/

void solve(){
  ll n; cin >> n;

  vector<ll> u(n);
  // vector<vector<ll>> g(n);
  vector<ll> g(n, -1);
  vector<ll> rank(n, 0);
  vector<ll> indeg(n, 0);

  cin >> u.at(0);
  rep(i, n-1){
    ll p, uu; cin >> p >> uu;
    p--;
    // g.at(p).push_back(i+1);
    // g.at(i+1).push_back(p);
    g.at(i+1) = p;
    indeg.at(p)++;
    u.at(i+1) = uu;
  }

  queue<ll> que;
  rep(i, n)if(indeg.at(i) == 0){
    rank.at(i) = u.at(i);
    que.push(i);
  }


  bool is_ok = true;
  while(!que.empty()){
    ll v = que.front(); que.pop();
    // rank.at(v) = u.at(v);
    ll p = g.at(v);
    if(p >= 0){
      ll mi = min(rank.at(v), u.at(p));
      rank.at(p) = max(rank.at(p), mi);
      indeg.at(p)--;
      if(indeg.at(p) == 0){
        que.push(p);
      }
    }
  }
  rank.at(0) = 1;

  ll ans = 0;
  rep(i, n){
    if(rank.at(i) > u.at(i)){
      cout << -1 << endl;
      return;
    }
    ans += rank.at(i);
  }
  cout << ans << endl;
}

int main() {

  solve();

  return 0;
}
