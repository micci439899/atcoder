#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegmentTree {
  // 1-indexedのSegment Tree
  // ただし、外からは0-indexedとみなすことができる

  // 演算、単位元
  function<T(T,T)> op;
  T e;

  // 元のデータサイズ
  int n;

  // SegmentTreeで管理するデータ
  vector<T> x;

  // SegmentTreeで確保したデータから実データにアクセスするためのoffset
  int offset;

  SegmentTree(int N, function<T(T,T)> op, T e) : op(op), e(e) {
    initialize(N);
  }
  SegmentTree(const vector<T> &v, const function<T(T,T)> op, T e) : op(op), e(e) {
    initialize((int)v.size());
    build(v);
  }

  void initialize(int N) {
    n = N;
    offset = 1;
    while(offset < N) offset *= 2;
    x.assign(2*offset, e);
  }

  void build(const vector<T> &v) {
    for(int i = 0; i < (int)v.size(); i++) x.at(i + offset) = v.at(i);
    for(int i = offset-1; i > 0; i--) x.at(i) = op(x.at(i*2), x.at(i*2+1));
  }

  // 1点更新(O(log N))
  // i: 0-indexed
  void set(int i, T val) {
    // 実データは[offset, 2*offset)
    i += offset;
    x.at(i) = val;

    // 親をたどる
    while(i > 1) {
      i /= 2;
      x.at(i) = op(x.at(2*i), x.at(2*i+1));
    }
  }

  // 指定区間に対する演算結果を取得(O(log N))
  // [l, r)
  T prod(int l, int r) {
    // 実データは[offset, 2*offset)
    l += offset;
    r += offset;
    T l_val = e;
    T r_val = e;

    while(l < r) {
      // lが親から見て右の子のときlの値を計算
      if(l % 2 == 1) {
        l_val = op(l_val, x.at(l));
        l++;
      }

      // r-1が親から見て左の子のときr-1の値を計算
      if(r % 2 == 1) {
        r--;
        r_val = op(x.at(r), r_val);
      }
      // 親（1段上）に
      l /= 2;
      r /= 2;
    }
    return op(l_val, r_val);
  }

  // SegmentTree上の二分探索
  // [l, r)に対する演算がtrueとなるrを返す
  int max_right(const function<bool(T)> f, int l = 0) {
    if(l == n) return n;
    l += offset;
    T res = e;
    do {
      while(l%2 == 0) l >>= 1;
      if(!f(op(res, x.at(l)))) {
        while(l < offset) {
          l = l * 2;
          if(f(op(res, x.at(l)))) {
            res = op(res, x.at(l));
            l++;
          }
        }
        return l - offset;
      }
      res = op(res, x.at(l));
      l++;
    } while((l & -l) != l);
    return n;
  }

  // SegmentTree上の二分探索
  // [l, r)に対する演算がtrueとなるlを返す
  int min_left(const function<bool(T)> f, int r = -1) {
    if(r == 0) return 0;
    if(r == -1) r = n;
    r += offset;
    T res = e;
    do {
      r--;
      while(r > 1 && (r%2)) r >>= 1;
      if(!f(op(x.at(r), res))){
        while(r < offset) {
          r = r * 2 + 1;
          if(f(op(x.at(r), res))) {
            res = op(x.at(r), res);
            r--;
          }
        }
        return r + 1 - offset;
      }
      res = op(x.at(r), res);
    } while((r & -r) != r);
    return 0;
  }

  // debug用
  void out() {
    // 改行する要素番号（0-indexed）
    int br_num = 1;
    for(int i = 0; i < (int)x.size(); i++) {
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


void do_segment_tree(){
  auto f = [](int a, int b) -> int {return min(a, b);};
  int e = INT_MAX/2;
  SegmentTree<int> seg = SegmentTree<int>(10, f, e);

  vector<int> v = {1, 4, 3, 9, 4, 6, 2, 2, 3};

  //                1
  //        1               3
  //    1       2       3       e
  //  1   3   4   2   3   e   e   e
  // 1 4 3 9 4 6 2 2 3 e e e e e e e

  for(int i = 0; i < (int)v.size(); i++) {
    seg.set(i, v.at(i));
  }

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
}

int main() {
  do_segment_tree();
  return 0;
}
