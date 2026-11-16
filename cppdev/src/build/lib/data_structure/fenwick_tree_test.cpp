#include <iostream>
#include <tuple>
#include <vector>
#include "fenwick_tree.hpp"

void do_fenwick(){

  std::vector<std::tuple<int, long long, long long>> qs;
  qs.emplace_back(1, 1LL, 3LL);
  qs.emplace_back(1, 2LL, 5LL);
  qs.emplace_back(0, 2LL, 10LL);
  qs.emplace_back(1, 3LL, 5LL);

  std::vector<long long> a = {3, 1, 4, 1, 5};
  int n = a.size();

  FenwickTree<long long> tree(n);
  for(int i = 0; i < (int)a.size(); i++) {
    tree.add(i, a.at(i));
  }

  for(int i = 0; i < (int)qs.size(); i++) {
    auto [type, x, y] = qs.at(i);
    if(type == 0){
      x--;
      tree.add(x, y);
    }else{
      x--; y--;
      long long sm_l = tree.sum(x);
      long long sm_r = tree.sum(y);

      std::cout << "0 ~ " << x << ": " << sm_l << std::endl;
      std::cout << "0 ~ " << y << ": " << sm_r << std::endl;
      std::cout << x+1 << " ~ " << y << ": " << sm_r - sm_l << std::endl;
    }
  }
}

int main() {
  do_fenwick();
  return 0;
}
