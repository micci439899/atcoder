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


  // https://drken1215.hatenablog.com/entry/2023/11/14/033300
  // get max r that f(get(l, r)) = True (0-indexed), O(log N)
  // f(IDENTITY) need to be True
  // int max_right(const function<bool(Monoid)> f, int l = 0) {
  int max_right(const function<bool(T)> f, int l = 0) {
    // if (l == N) return N;
    if (l == n) return n;
    // l += offset;
    l += n;
    // Monoid sum = IDENTITY;
    T sum = e;
    do {
      while (l % 2 == 0) l >>= 1;
      // if (!f(OP(sum, dat[l]))) {
      if (!f(prod(sum, x[l]))) {
        // while (l < offset) {
        while (l < n) {
          l = l * 2;
          // if (f(OP(sum, dat[l]))) {
          //   sum = OP(sum, dat[l]);
          if (f(prod(sum, x[l]))) {
            sum = prod(sum, x[l]);
            ++l;
          }
        }
        // return l - offset;
        return l - n;
      }
      // sum = OP(sum, dat[l]);
      sum = prod(sum, x[l]);
      ++l;
    } while ((l & -l) != l);  // stop if l = 2^e
    // return N;
    return n;
  }


  // get min l that f(get(l, r)) = True (0-indexed), O(log N)
  // f(IDENTITY) need to be True
  // int min_left(const function<bool(Monoid)> f, int r = -1) {
  int min_left(const function<bool(T)> f, int r = -1) {
    if (r == 0) return 0;
    // if (r == -1) r = N;
    if (r == -1) r = n;
    // r += offset;
    r += n;
    // Monoid sum = IDENTITY;
    T sum = e;
    do {
      --r;
      while (r > 1 && (r % 2)) r >>= 1;
      // if (!f(OP(dat[r], sum))) {
      if (!f(prod(x[r], sum))) {
        // while (r < offset) {
        while (r < n) {
          r = r * 2 + 1;
          // if (f(OP(dat[r], sum))) {
          //   sum = OP(dat[r], sum);
          if (f(prod(x[r], sum))) {
            sum = prod(x[r], sum);
            --r;
          }
        }
        // return r + 1 - offset;
        return r + 1 - n;
      }
      // sum = OP(dat[r], sum);
      sum = prod(x[r], sum);
    } while ((r & -r) != r);
    return 0;
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
*/


// https://drken1215.hatenablog.com/entry/2023/11/14/033300
// Segment Tree
template<class Monoid> struct SegTree {
    using Func = function<Monoid(Monoid, Monoid)>;

    // core member
    int N;
    Func OP;
    Monoid IDENTITY;
    
    // inner data
    int offset;
    vector<Monoid> dat;

    // constructor
    SegTree() {}
    SegTree(int n, const Func &op, const Monoid &identity) {
        init(n, op, identity);
    }
    SegTree(const vector<Monoid> &v, const Func &op, const Monoid &identity) {
        init((int)v.size(), op, identity);
        build(v);
    }
    void init(int n, const Func &op, const Monoid &identity) {
        N = n;
        OP = op;
        IDENTITY = identity;
        offset = 1;
        while (offset < N) offset *= 2;
        dat.assign(offset * 2, IDENTITY);
    }
    void init(const vector<Monoid> &v, const Func &op, const Monoid &identity) {
        init((int)v.size(), op, identity);
        build(v);
    }
    void build(const vector<Monoid> &v) {
        assert(N == (int)v.size());
        for (int i = 0; i < N; ++i) dat[i + offset] = v[i];
        for (int k = offset - 1; k > 0; --k) dat[k] = OP(dat[k*2], dat[k*2+1]);
    }
    int size() const {
        return N;
    }
    Monoid operator [] (int a) const { return dat[a + offset]; }
    
    // update A[a], a is 0-indexed, O(log N)
    void set(int a, const Monoid &v) {
        int k = a + offset;
        dat[k] = v;
        while (k >>= 1) dat[k] = OP(dat[k*2], dat[k*2+1]);
    }
    
    // get [a, b), a and b are 0-indexed, O(log N)
    Monoid prod(int a, int b) {
        Monoid vleft = IDENTITY, vright = IDENTITY;
        for (int left = a + offset, right = b + offset; left < right;
        left >>= 1, right >>= 1) {
            if (left & 1) vleft = OP(vleft, dat[left++]);
            if (right & 1) vright = OP(dat[--right], vright);
        }
        return OP(vleft, vright);
    }
    Monoid all_prod() { return dat[1]; }
    
    // get max r that f(get(l, r)) = True (0-indexed), O(log N)
    // f(IDENTITY) need to be True
    int max_right(const function<bool(Monoid)> f, int l = 0) {
        if (l == N) return N;
        l += offset;
        Monoid sum = IDENTITY;
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(OP(sum, dat[l]))) {
                while (l < offset) {
                    l = l * 2;
                    if (f(OP(sum, dat[l]))) {
                        sum = OP(sum, dat[l]);
                        ++l;
                    }
                }
                return l - offset;
            }
            sum = OP(sum, dat[l]);
            ++l;
        } while ((l & -l) != l);  // stop if l = 2^e
        return N;
    }

    // get min l that f(get(l, r)) = True (0-indexed), O(log N)
    // f(IDENTITY) need to be True
    int min_left(const function<bool(Monoid)> f, int r = -1) {
        if (r == 0) return 0;
        if (r == -1) r = N;
        r += offset;
        Monoid sum = IDENTITY;
        do {
            --r;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(OP(dat[r], sum))) {
                while (r < offset) {
                    r = r * 2 + 1;
                    if (f(OP(dat[r], sum))) {
                        sum = OP(dat[r], sum);
                        --r;
                    }
                }
                return r + 1 - offset;
            }
            sum = OP(dat[r], sum);
        } while ((r & -r) != r);
        return 0;
    }
    
    // debug
    friend ostream& operator << (ostream &s, const SegTree &seg) {
        for (int i = 0; i < seg.size(); ++i) {
            s << seg[i];
            if (i != seg.size()-1) s << " ";
        }
        return s;
    }
};

void solve(){
  int n, m; cin >> n >> m;

  // vector<ll> p(n);
  vector<pll> p(n);
  rep(i, n) {cin >> p.at(i).first; p.at(i).second = i;}

  // auto f_mi = [](ll a, ll b) -> ll {return min(a, b);};
  auto f_mi = [](pll a, pll b) -> pll {return (a.first < b.first) ? a : b;};
  // ll e_mi = 1LL<<60;
  pll e_mi = {1LL<<60, -1};
  // SegmentTree<ll> seg_mi = SegmentTree<ll>(n, f_mi, e_mi);
  SegTree<pll> seg_mi(p, f_mi, e_mi);

  // auto f_ma = [](ll a, ll b) -> ll {return max(a, b);};
  auto f_ma = [](pll a, pll b) -> pll {return a.first > b.first ? a : b;};
  // ll e_ma = 0;
  pll e_ma = {0, -1};
  // SegmentTree<ll> seg_ma = SegmentTree<ll>(n, f_ma, e_ma);
  SegTree<pll> seg_ma(p, f_ma, e_ma);

/*
  rep(i, n){
    seg_mi.set(i, p.at(i));
    seg_ma.set(i, p.at(i));
  }
*/

  while(m--){
    ll l, r; cin >> l >> r;
    l--; r--;
    // ll mi = seg_mi.prod(l, r+1);
    // ll ma = seg_ma.prod(l, r+1);
    pll mi = seg_mi.prod(l, r+1);
    pll ma = seg_ma.prod(l, r+1);

    // ll idx_mi1 = seg_mi.min_left([&](ll x) -> bool { return x <= mi; }, mi);
    // ll idx_mi2 = seg_mi.max_right([&](ll x) -> bool { return x <= mi; }, mi);
    // ll idx_ma1 = seg_ma.min_left([&](ll x) -> bool { return x >= ma; }, ma);
    // ll idx_ma2 = seg_ma.max_right([&](ll x) -> bool { return x >= ma; }, ma);

    ll idx_mi = mi.second;
    ll idx_ma = ma.second;

    // seg_mi.set(idx_mi, ma);
    // seg_mi.set(idx_ma, mi);
    // seg_ma.set(idx_mi, ma);
    // seg_ma.set(idx_ma, mi);
    seg_mi.set(idx_mi, {ma.first, mi.second});
    seg_mi.set(idx_ma, {mi.first, ma.second});
    seg_ma.set(idx_mi, {ma.first, mi.second});
    seg_ma.set(idx_ma, {mi.first, ma.second});

    swap(p.at(idx_mi), p.at(idx_ma));

    // debug(mi);
    // debug(ma);
    // debug(idx_mi1);
    // debug(idx_mi2);
    // debug(idx_ma1);
    // debug(idx_ma2);
    // debug(p);

  }

  rep(i, n){
    if(i) cout << " ";
    cout << p.at(i).first;
  }
  cout << endl;

}

int main() {

  solve();

  return 0;
}