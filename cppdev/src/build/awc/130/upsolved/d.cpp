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

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

// 素集合データ構造（Union-Find）
struct DisjointSetUnion {
  vector<int> parents;
  vector<int> sizes;

  // 初期化子リスト
  DisjointSetUnion(int n) : parents(n, -1), sizes(n, 1) {}

  // xが属しているグループの代表（根）を取得
  int find(int x) {
    if(parents.at(x) == -1) return x;

    // 経路圧縮
    parents.at(x) = find(parents.at(x));
    return parents.at(x);
  }

  // xとyが同じグループに属しているかどうか
  bool is_same(int x, int y) {
    return find(x) == find(y);
  }

  // xが属しているグループとyが属しているグループを併合する
  // xとyが既に同じグループに属しているときfalse、そうでないときtrueを返す
  bool unite(int x, int y) {
    int x_r = find(x);
    int y_r = find(y);

    if(x_r == y_r) return false;

    // union by size（木の深さをなるべく小さくする）
    if(sizes.at(x_r) < sizes.at(y_r)) swap(x_r, y_r);

    parents.at(y_r) = x_r;
    sizes.at(x_r) += sizes.at(y_r);
    return true;
  }

  // xが属しているグループの要素数を返す
  int size(int x) {
    return sizes.at(find(x));
  }
};

void solve(){
  int h, w, n; cin >> h >> w >> n;

  vector<vector<int>> imos(h+1, vector<int>(w+1, 0));
  rep(i, n){
    int a, b, c, d; cin >> a >> b >> c >> d;
    a--; b--; c--; d--;
    imos.at(a).at(c)++;
    imos.at(a).at(d+1)--;
    imos.at(b+1).at(c)--;
    imos.at(b+1).at(d+1)++;
  }

  rep(i, h)rep(j, w+1){
    imos.at(i+1).at(j) += imos.at(i).at(j);
  }
  rep(i, h+1)rep(j, w){
    imos.at(i).at(j+1) += imos.at(i).at(j);
  }

  auto to_1d = [&](int i, int j){
    return i*w + j;
  };
  auto is_within = [&](int i, int j){
    if(i < 0 || h-1 < i) return false;
    if(j < 0 || w-1 < j) return false;
    return true;
  };
  DisjointSetUnion dsu(h*w);
  rep(i, h)rep(j, w){
    if(imos.at(i).at(j)%2==0) continue;
    rep(k, 4){
      int ni = i + dy.at(k);
      int nj = j + dx.at(k);
      if(!is_within(ni, nj)) continue;
      if(imos.at(ni).at(nj)%2==0) continue;
      dsu.unite(to_1d(i, j), to_1d(ni, nj));
    }
  }

  vector<int> leaders(h*w, 0);
  vector<int> sizes(h*w, 0);
  rep(i, h)rep(j, w){
    leaders.at(to_1d(i, j)) = dsu.find(to_1d(i, j));
    sizes.at(to_1d(i, j)) = dsu.size(to_1d(i, j));
  }

  int m; cin >> m;
  rep(i, m){
    int p, q, r, s; cin >> p >> q >> r >> s;
    p--; q--; r--; s--;

    int cnt1 = 0;
    for(int i = p; i <= q; i++)for(int j = r; j <= s; j++){
      if(imos.at(i).at(j)%2==0) continue;
      cnt1++;
    }

    // key: dsuの根, value: (p,r) ~ (q,s)の範囲内にあり、根がkeyとなるマスの個数
    unordered_map<int, int> mp;
    for(int i = p; i <= q; i++)for(int j = r; j <= s; j++){
      if(imos.at(i).at(j)%2!=0) mp[leaders.at(to_1d(i, j))]++;
    }
    int cnt2 = 0;
    for(auto p : mp){
      if(sizes.at(p.first) == p.second) cnt2++;
    }
    cout << cnt1 << " " << cnt2 << endl;
  }
}

int main() {

  solve();

  return 0;
}
