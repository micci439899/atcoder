#include <bits/stdc++.h>
#include "lazy_segment_tree.hpp"
using namespace std;

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
