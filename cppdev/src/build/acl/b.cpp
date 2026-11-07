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

// FenwickTree(Binary Indexed Tree)
// 下記参考
// https://qiita.com/DaikiSuyama/items/7295f5160a51684554a7
// https://algo-logic.info/binary-indexed-tree/
template<typename T>
struct FenwickTree {
  int n;
  vector<T> bit;

  FenwickTree(int n_) : n(n_+1), bit(n_+1, 0){}

  // 1点更新
  // 0-indexed
  void add(int i, T x){
    // 内部的には1-indexed
    i++;
    for(int idx = i; idx < n; idx += (idx & -idx)){
      bit.at(idx) += x;
    }
  }

  // a_0 + ... + a_i
  // 0-indexed
  T sum(int i){
    // 内部的には1-indexed
    i++;
    T sm(0);
    for(int idx = i; idx > 0; idx -= (idx & -idx)){
      sm += bit.at(idx);
    }
    return sm;
  }
};

void solve(){
  ll n, q; cin >> n >> q;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  FenwickTree<ll> tree(n);
  rep(i, n){
    tree.add(i, a.at(i));
  }

  while(q--){
    int type; cin >> type;
    if(type == 0){
      ll p, x; cin >> p >> x;
      tree.add(p, x);
    }else{
      ll l, r; cin >> l >> r;
      ll sm_l = tree.sum(l-1);
      ll sm_r = tree.sum(r-1);
      cout << sm_r - sm_l << endl;
    }
  }
}

int main() {

  solve();

  return 0;
}
