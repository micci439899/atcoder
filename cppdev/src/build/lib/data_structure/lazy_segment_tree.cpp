#include <bits/stdc++.h>
using namespace std;

template<class T, class F> struct LazySegmentTree {
  // 1-indexedのLazy Segment Tree
  // ただし、外からは0-indexedとみなすことができる
  
  // 演算、単位元
  function<T(T,T)> op;
  T e;

  // 作用素、恒等写像
  function<T(F,T)> mapping;
  F id;

  // 作用素の合成
  function<F(F,F)> composition;

  // 元のデータサイズ
  int n;

  // SegmentTreeで管理するデータ
  vector<T> x;

  vector<F> lazy;

  // SegmentTreeで確保したデータから実データにアクセスするためのoffset
  int offset;

  // SegmentTreeの高さ
  int height;

  LazySegmentTree(int N, const function<T(T,T)> op, const function<T(F,T)> mapping, const function<F(F,F)> composition, const T e, const F id) : op(op), mapping(mapping), composition(composition), e(e), id(id) {
    initialize(N);
  }
  LazySegmentTree(const vector<T> &v, const function<T(T,T)> op, const function<T(F,T)> mapping, const function<F(F,F)> composition, const T e, const F id) : op(op), mapping(mapping), composition(composition), e(e), id(id) {
    initialize((int)v.size());
    build(v);
  }

  void initialize(int N) {
    n = N;
    offset = 1;
    height = 0;
    while(offset < N) offset *= 2, height++;
    x.assign(2*offset, e);
    lazy.assign(2*offset, id);
  }

  void build(const vector<T> &v) {
    for(int i = 0; i < (int)v.size(); i++) x.at(i + offset) = v.at(i);
    for(int i = offset-1; i > 0; i--) pull(i);
  }

  void pull(int i) {
    x.at(i) = op(x.at(i*2), x.at(i*2+1));
  }

  // i番目のデータを正しい値に直し、遅延分を溜める
  void apply(int i, const F &f) {
    x.at(i) = mapping(f, x.at(i));
    if(i < offset) lazy.at(i) = composition(f, lazy.at(i));
  }

  // 遅延させていた分を子に渡す
  void push(int i) {
    apply(i*2, lazy.at(i));
    apply(i*2+1, lazy.at(i));
    lazy.at(i) = id;
  }

  // 子のデータを自身に反映
  void deep_pull(int i){
    for(int h = 1; h <= height; h++) pull(i>>h);
  }

  void deep_push(int i) {
    for(int h = height; h >= 1; h--) push(i>>h);
  }

  void set(int i, const T &val) {
    int k = i + offset;
    deep_push(k);
    x.at(k) = val;
    deep_pull(k);
  }

  T get(int i) {
    int k = i + offset;
    deep_push(k);
    return x.at(k);
  }

  void apply(int l, int r, const F &f) {
    if(l == r) return;
    l += offset, r += offset;

    for(int h = height; h >= 1; h--) {
      int l_k = l>>h;
      int r_k = r>>h;
      if((l_k << h) != l) push(l_k);
      if((r_k << h) != r) push((r-1)>>h);
    }

    int original_l = l, original_r = r;
    for(; l < r; l>>=1, r>>=1) {
      if(l & 1) {
        apply(l, f);
        l++;
      }
      if(r & 1) {
        r--;
        apply(r, f);
      }
    }

    l = original_l, r = original_r;
    for(int h = 1; h <= height; h++) {
      int l_k = l>>h;
      int r_k = r>>h;
      if((l_k << h) != l) pull(l_k);
      if((r_k << h) != r) pull((r-1)>>h);
    }
  }

  T prod(int l, int r) {
    if(l == r) return e;
    l += offset, r += offset;

    for(int h = height; h >= 1; h--) {
      int l_k = l>>h;
      int r_k = r>>h;
      if((l_k << h) != l) push(l_k);
      if((r_k << h) != r) push(r_k);
    }

    T l_val = e, r_val = e;
    for(; l < r; l>>=1, r>>=1) {
      if(l & 1) {
        l_val = op(l_val, x.at(l));
        l++;
      }
      if(r & 1) {
        r--;
        r_val = op(x.at(r), r_val);
      }
    }
    return op(l_val, r_val);
  }

  // SegmentTree上の二分探索
  // [l, r)に対する演算がtrueとなるrを返す
  int max_right(const function<bool(T)> func, int l = 0) {
    if(l == n) return n;
    l += offset;
    deep_push(l);
    T sm = e;
    do {
      while(l%2 == 0) l >>= 1;
      if(!func(op(sm, x.at(l)))) {
        while(l < offset) {
          deep_push(l);
          l = l * 2;
          if(func(op(sm, x.at(l)))) {
            sm = op(sm, x.at(l));
            l++;
          }
        }
        return l - offset;
      }
      sm = op(sm, x.at(l));
      l++;
    } while((l & -l) != l);

    return n;
  }

  // SegmentTree上の二分探索
  // [l, r)に対する演算がtrueとなるlを返す
  int min_left(const function<bool(T)> func, int r = -1) {
    if(r == 0) return 0;
    if(r == -1) r = n;
    r += offset;
    deep_push(r-1);
    T sm = e;
    do {
      r--;
      while(r > 1 && (r%2)) r >>= 1;
      if(!func(op(x.at(r), sm))) {
        while(r < offset) {
          deep_push(r);
          r = r * 2 + 1;
          if(func(op(x.at(r), sm))) {
            sm = op(x.at(r), sm);
            r--;
          }
        }
        return r + 1 - offset;
      }
      sm = op(x.at(r), sm);
    } while((r & -r) != r);

    return 0;
  }

  void out() {
    // 改行する要素番号（0-indexed）
    int br_num = 1;
    for(int i = 0; i < (int)x.size(); i++) {
      if(i == 0) continue;
      cout << x.at(i) << ", (" << lazy.at(i) << ") ";
      if(br_num == i){
        cout << endl;
        // 2^(n-1) - 1から2^n - 1
        br_num = (br_num+1)*2-1;
      }
    }
  }
};

void do_lazy_segment_tree(){
  auto f = [](int a, int b) -> int {return min(a, b);};
  int e = 1<<30;

  auto mapping = [](int f, int x){return f + x;};
  auto composition = [](int g, int f){return g + f;};
  int id = 0;

  vector<int> v = {1, 4, 3, 9, 4, 6, 2, 2, 3};
  
  LazySegmentTree<int, int> seg = LazySegmentTree<int, int>(v, f, mapping, composition, e, id);

  //                1
  //        1               3
  //    1       2       3       e
  //  1   3   4   2   3   e   e   e
  // 1 4 3 9 4 6 2 2 3 e e e e e e e

  int mi_1 = seg.prod(1, 3);  
  int mi_2 = seg.prod(0, 9);
  int mi_3 = seg.prod(5, 8);
  int mi_4 = seg.prod(5, 5);

  cout << "min of interval[1, 3) is " << mi_1 << endl;
  cout << "min of interval[0, 9) is " << mi_2 << endl;
  cout << "min of interval[5, 8) is " << mi_3 << endl;
  cout << "min of interval[5, 5) is " << mi_4 << endl;

  cout << "seg out" << endl;
  seg.out();


  seg.apply(0, 3, 3);
  mi_1 = seg.prod(1, 3);  
  mi_2 = seg.prod(0, 9);
  mi_3 = seg.prod(5, 8);
  mi_4 = seg.prod(5, 5);

  cout << "min of interval[1, 3) is " << mi_1 << endl;
  cout << "min of interval[0, 9) is " << mi_2 << endl;
  cout << "min of interval[5, 8) is " << mi_3 << endl;
  cout << "min of interval[5, 5) is " << mi_4 << endl;

  cout << "seg out" << endl;
  seg.out();
}

int main() {
  do_lazy_segment_tree();
  return 0;
}
