#include <functional>
#include <iostream>
#include <map>
#include <unordered_map>
#include <utility>

// unordered_mapのkeyにpairを用いるときに使用（元々の構造に順序付けがない場合に必要という理解）
// 参考：https://qiita.com/tqk/items/7c4df1eeb5ebaedcf714
template<typename T, typename U>
struct PairHash {
  inline size_t operator()(const std::pair<T, U> &p) const{
    const auto h1 = std::hash<T>()(p.first);
    const auto h2 = std::hash<U>()(p.second);
    return h1 ^ (h2 << 1);
  }
};

void practice_map() {
  std::map<int, int> mp;
  mp[0] = 1;
  mp[10] = 2;
  mp[20] = 3;

  for(auto p : mp) {
    std::cout << p.first << ":" << p.second << std::endl;
  }

  if(mp.count(0)){
    std::cout << "0 is contained, value is " << mp[0] << std::endl;
  }
  if(!mp.count(5)){
    std::cout << "5 is not contained" << std::endl;
  }

  auto it = mp.begin();
  std::cout << "first" << std::endl;
  std::cout << it->first << ":" << it->second << std::endl;

  // keyの二分探索
  it = mp.lower_bound(10);
  if(it != mp.end()){
    std::cout << "lower bound 10 " << it->first << ":" << it->second << std::endl;
  }
  it = mp.upper_bound(10);
  if(it != mp.end()){
    std::cout << "upper bound 10 " << it->first << ":" << it->second << std::endl;
  }


  std::unordered_map<std::pair<long long, int>, std::string, PairHash<long long, int>> ump;
  ump[std::make_pair(1LL, 2)] = "abc";
  ump[std::make_pair(2LL, 3)] = "def";
  ump[std::make_pair(3LL, 4)] = "ghi";

  for(auto p : ump){
    auto [l, t] = p.first;
    std::cout << "(" << l << ", " << t << ") : " << p.second << std::endl;
  }


}

int main() {
  practice_map();
  return 0;
}