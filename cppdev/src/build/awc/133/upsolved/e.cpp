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

template <typename T>
struct SegmentTree{
  // 1-indexedのSegment Tree

  function<T(T,T)> op;
  T e;
  int n;
  vector<T> x;

  SegmentTree(int N, function<T(T,T)> op, T e) : op(op), e(e){
    n = 1;
    while(n < N) n *= 2;
    x.assign(2*n, e);
  }

  // 1点更新(O(log N))
  // i: 0-indexed
  void set(int i, T val){
    // 実データは[n, 2n)
    i += n;
    x.at(i) = val;

    // 親をたどる
    while(i > 1){
      i /= 2;
      x.at(i) = op(x.at(2*i), x.at(2*i+1));
    }
  }

  // 指定区間に対する演算結果を取得(O(log N))
  // [l, r)
  T prod(int l, int r){
    // 実データは[n, 2n)
    l += n;
    r += n;
    T l_val = e;
    T r_val = e;

    while(l < r){
      // lが親から見て右の子のときlの値を計算
      if(l % 2 == 1){
        l_val = op(l_val, x.at(l));
        l++;
      }

      // r-1が親から見て左の子のときr-1の値を計算
      if(r % 2 == 1){
        r--;
        r_val = op(r_val, x.at(r));
      }
      // 親（1段上）に
      l /= 2;
      r /= 2;
    }
    return op(l_val, r_val);
  }

  // debug用
  void out(){
    // 改行する要素番号（0-indexed）
    int br_num = 1;
    rep(i, x.size()){
      if(i == 0) continue;
      cout << x.at(i) << " ";
      if(br_num == i){
        cout << endl;
        // 2^(n-1) - 1から2^n - 1
        br_num = (br_num+1)*2-1;
      }
    }
  }
};

const ll INFL = 1LL<<60;

void solve(){
  int n, m, k ,t; cin >> n >> m >> k >> t;

  auto f1 = [](ll a, ll b) -> ll {return min(a, b);};
  ll e1 = INFL;

  auto f2 = [](ll a, ll b) -> ll {return max(a, b);};
  ll e2 = - INFL;

  ll cnt = 0;
  rep(i, n){
    SegmentTree<ll> seg1 = SegmentTree<ll>(m, f1, e1);
    SegmentTree<ll> seg2 = SegmentTree<ll>(m, f2, e2);

    rep(i, m){
      ll s; cin >> s;
      seg1.set(i, s);
      seg2.set(i, s);
    }

    ll score = - INFL;
    rep(i, m-k+1){
      ll mi = seg1.prod(i, i+k);
      ll ma = seg2.prod(i, i+k);
      chmax(score, ma-mi);
    }
    if(score >= t) cnt++;
  }
  cout << cnt << endl;
}

int main() {

  solve();

  return 0;
}