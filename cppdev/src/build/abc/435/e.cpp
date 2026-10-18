# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

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

  // 1点更新
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

  // 指定区間に対する演算結果を取得
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




int main() {
  ll n, q;
  cin >> n >> q;

  vector<ll> c(n, 0);

  auto f = [&](ll a, ll b) -> int {
    // int cnt = 0;
    // if(a==1)cnt++;
    // if(b==1)cnt++;
    // return cnt;
    return a+b;
  };
  ll e = 0;
  SegmentTree<ll> seg = SegmentTree<ll> (n, f, e);

  while(q--){
    int l, r;
    cin >> l >> r;
    l--; r--;

    // cout << "l:" << l << " r:" << r << endl;

    for(int i = l; i <= r; i++){
      seg.set(i, 1);
    }

    // seg.out();

    int cnt = seg.prod(0, n);

    // cout << "cnt:" << cnt << endl;
    cout << (n-cnt) << endl;
  }

  return 0;  
}









