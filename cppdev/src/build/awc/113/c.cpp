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
  ll n, m, k, q, t; cin >> n >> m >> k >> q >> t;
  t--;

  vector<vector<ll>> g(n);
  rep(i, m){
    ll u, v; cin >> u >> v;
    u--; v--;
    g.at(u).push_back(v);
    g.at(v).push_back(u);
  }

  vector<ll> s(k);
  rep(i, k){
    ll si; cin >> si;
    si--;
    s.at(i) = si;
  }

  set<ll> p_st;
  rep(i, q){
    ll pi; cin >> pi;
    pi--;
    p_st.insert(pi);
  }

  bool ok = true;
  rep(i, k)if(s.at(i) != t){
    ok = false;
    break;
  }
  if(ok){
    cout << 0 << endl;
    return;
  }

  vector<vector<ll>> dist(k, vector<ll>(n, INFL));

  queue<pll> que;
  rep(i, k){
    if(p_st.count(s.at(i))){
      cout << -1 << endl;
      return;
    }
    dist.at(i).at(s.at(i)) = 0;
    que.push({i, s.at(i)});
  }

  while(!que.empty()){
    auto [i, si] = que.front(); que.pop();

    for(ll v : g.at(si)){
      ll nd = dist.at(i).at(si) + 1;
      if(p_st.count(dist.at(i).at(v))) continue;
      if(dist.at(i).at(v) < nd) continue;
      dist.at(i).at(v) = nd;
      que.push({i, v});
    }
  }

  ll ans = -1;
  rep(i, k){
    if(dist.at(i).at(t) == INFL){
      cout << -1 << endl;
      return;
    }
    chmax(ans, dist.at(i).at(t));
  }
  cout << ans << endl;
}



int main() {

  solve();

  return 0;
}
