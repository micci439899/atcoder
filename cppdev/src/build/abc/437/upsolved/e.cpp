// The template file is below
// https://github.com/micci439899/atcoder

#include <bits/stdc++.h>
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
template<class T>ostream&operator<<(ostream&os, const multiset<T>&st){os<<"{";int idx=0;for(auto &e : st){cout << e;if(idx != st.size()-1){cout << ",";}idx++;}os<<"}";return os;}
template<class T, class U>ostream&operator<<(ostream&os, map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}
int ctoi(char c){return int(c-'0');} // e.g.) a -> 49, 1 -> 1
char itoc(int x){return x+'0';}

void solve(){
  // ほぼ解説の写経...
  // 1つのnodeに大きい数字が入るような形式だとライブラリ使えない

  ll n; cin >> n;

  // node毎の
  // key: A_i, value: node_id
  vector<unordered_map<ll, ll>> nxt(n+1);
  // vector<map<ll, ll>> nxt(n+1);

  // nodeに所属するi
  vector<vector<ll>> nodes(n+1);

  // A_iのnode_id
  vector<ll> pos(n+1, -1);
  pos.at(0) = 0;

  ll node_id = 1;
  rep(i, n){
    ll x, y; cin >> x >> y;
    if(!nxt.at(pos.at(x)).count(y)){
      nxt.at(pos.at(x))[y] = node_id;
      node_id++;
    }
    pos.at(i+1) = nxt.at(pos.at(x))[y];
    nodes.at(pos.at(i+1)).push_back(i+1);
  }

  // rep(i, nxt.size()){
  //   debug(nxt.at(i));
  // }
  // debug(nodes);
  // debug(pos);

  vector<ll> ans;

  auto dfs = [&](auto self, ll i) -> void {
    rep(j, nodes.at(i).size()) ans.push_back(nodes.at(i).at(j));

    vector<ll> v;
    for(auto p : nxt.at(i)){
      v.push_back(p.first);
    }
    sort(v.begin(), v.end());

    rep(j, v.size()){
      self(self, nxt.at(i)[v.at(j)]);
    }
  };

  dfs(dfs, 0LL);

  rep(i, ans.size()){
    if(i) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
}

int main() {
  solve();
  return 0;
}
