#include <vector>

// FenwickTree(Binary Indexed Tree)
// 下記参考
// https://qiita.com/DaikiSuyama/items/7295f5160a51684554a7
// https://algo-logic.info/binary-indexed-tree/
template<typename T>
struct FenwickTree {
  int n;
  std::vector<T> bit;

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
