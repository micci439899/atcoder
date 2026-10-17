#include <bits/stdc++.h>
using namespace std;

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

// 練習、動作確認
void do_union_find(){

  int n = 7;
  DisjointSetUnion dsu(n);

  auto out_group = [&]() {
    cout << "group" << endl;
    for(int i = 0; i < (int)dsu.parents.size(); i++) {
      cout << dsu.find(i) << " ";
    }
    cout << endl << endl;
    return;
  };

  auto out_yn = [&](bool b) {
    if(b) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }   
  };

  cout << "initialize" << endl;
  out_group();

  dsu.unite(1, 2);
  cout << "1 and 2 are united" << endl;
  out_group();

  dsu.unite(2, 3);
  cout << "2 and 3 are united" << endl;
  out_group();

  dsu.unite(5, 6);
  cout << "5 and 6 are united" << endl;
  out_group();

  cout << "are 1 and 3 same group?" << endl;
  out_yn(dsu.is_same(1, 3));
  cout << "are 2 and 5 same group?" << endl;
  out_yn(dsu.is_same(2, 5));
  cout << endl;

  set<int> st;
  for(int i = 0; i < n; i++) {
    int leader = dsu.find(i);
    st.insert(leader);
  }
  cout << "the number of group is " << st.size() << endl;
}

int main() {
  do_union_find();
  return 0;
}
