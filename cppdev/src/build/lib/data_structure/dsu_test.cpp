#include <bits/stdc++.h>
#include "dsu.hpp"
using namespace std;

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