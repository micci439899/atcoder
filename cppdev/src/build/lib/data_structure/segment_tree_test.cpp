#include <bits/stdc++.h>
#include "segment_tree.hpp"
using namespace std;

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
