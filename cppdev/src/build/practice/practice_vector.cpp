#include <algorithm>
#include <iostream>
// #include <utility>
#include <numeric>
#include <vector>

void out(std::vector<int> &v) {
  for(int i = 0; i < (int)v.size(); i++) {
    if(i) std::cout << " ";
    std::cout << v.at(i);
  }
  std::cout << std::endl;
}

void practice_vector() {
  std::vector<int> v = {3, 1, 4 ,1, 5};

  std::cout << "original vector" << std::endl;
  out(v);

  std::cout << std::endl;
  std::cout << "first element: " << v.front() << std::endl;

  std::cout << "last element: " << v.back() << std::endl;

  std::cout << "2nd element: " << v.at(2) << std::endl;
  std::cout << std::endl;

  int ma = *std::max_element(v.begin(), v.end());
  std::cout << "max element: " << ma << std::endl;

  int mi = *std::min_element(v.begin(), v.end());
  std::cout << "min element: " << mi << std::endl;
  std::cout << std::endl;

  int ma2 = *std::max_element(v.begin(), v.begin()+2);
  std::cout << "max element of interval[0, 2): " << ma2 << std::endl;

  int mi2 = *std::min_element(v.begin(), v.begin()+2);
  std::cout << "min element of interval[0, 2): " << mi2 << std::endl;
  std::cout << std::endl;

  // O(n)
  int target = 1;
  auto it = std::find(v.begin(), v.end(), target);
  if(it != v.end()){
    std::cout << *it << " is in the vector" << std::endl;
  }else{
    std::cout << target << " is not in the vector" << std::endl;
  }

  target = 2;
  it = std::find(v.begin(), v.end(), target);
  if(it != v.end()){
    std::cout << *it << " is in the vector" << std::endl;
  }else{
    std::cout << target << " is not in the vector" << std::endl;
  }
  std::cout << std::endl;

  int cnt1 = std::count(v.begin(), v.end(), 1);
  std::cout << "count of 1: " << cnt1 << std::endl;

  int cnt7 = std::count(v.begin(), v.end(), 7);
  std::cout << "count of 7: " << cnt7 << std::endl;
  std::cout << std::endl;

  std::vector<int> v2 = v;
  sort(v2.begin(), v2.end());
  std::cout << "sort asc" << std::endl;
  out(v2);

  sort(v2.rbegin(), v2.rend());
  std::cout << "sort desc" << std::endl;
  out(v2);
  std::cout << std::endl;

  std::vector<std::pair<int, int>> v3;
  for(int i = 0; i < (int)v.size(); i++) {
    std::pair<int, int> p = std::make_pair(v.at(i), v2.at(i));
    v3.push_back(p);
  }

  std::cout << "paif of origin and sort desc" << std::endl;
  for(int i = 0; i < (int)v3.size(); i++) {
    if(i) std::cout << " ";
    std::cout << "(" << v3.at(i).first << ", " << v3.at(i).second << ")";
  }
  std::cout << std::endl;

  // first昇順、second降順
  sort(v3.begin(), v3.end(), [](std::pair<int, int> &a, std::pair<int, int> &b){
    if(a.first == b.first){
      return a.second > b.second;
    }else{
      return a.first < b.second;
    }
  });
  std::cout << "sort origin asc desc desc" << std::endl;
  for(int i = 0; i < (int)v3.size(); i++) {
    if(i) std::cout << " ";
    std::cout << "(" << v3.at(i).first << ", " << v3.at(i).second << ")";
  }
  std::cout << std::endl;
  std::cout << std::endl;


  // sort後にuniqueする必要あり
  std::vector<int> v4 = v;
  sort(v4.begin(), v4.end());
  std::cout << "sort and unique" << std::endl;
  v4.erase(unique(v4.begin(), v4.end()), v4.end());
  out(v4);
  std::cout << std::endl;



  std::vector<int> v5 = v;
  sort(v5.begin(), v5.end());
  out(v5);
  auto it5 = std::lower_bound(v5.begin(), v5.end(), 1);
  std::cout << "lower_bound " << 1 << " index:" << it5-v5.begin() << std::endl;
  it5 = std::lower_bound(v5.begin(), v5.end(), 10);
  std::cout << "lower_bound " << 10 << " index:" << it5-v5.begin() << std::endl;

  it5 = std::upper_bound(v5.begin(), v5.end(), 1);
  std::cout << "upper_bound " << 1 << " index:" << it5-v5.begin() << std::endl;
  it5 = std::upper_bound(v5.begin(), v5.end(), 10);
  std::cout << "upper_bound " << 10 << " index:" << it5-v5.begin() << std::endl;
  std::cout << std::endl;

  // pythonのrange相当
  std::vector<int> v6(10);
  std::iota(v6.begin(), v6.end(), 0);
  std::cout << "iota 0 ~ 9" << std::endl;
  out(v6);
  std::cout << std::endl;

  std::vector<int> v7(10);
  std::iota(v7.begin(), v7.end(), -4);
  std::cout << "iota -4 ~ 5" << std::endl;
  out(v7);

  std::swap(v7.at(1), v7.at(3));
  std::cout << "swap 1st and 3rd" << std::endl;
  out(v7);

  std::reverse(v7.begin()+1, v7.begin()+5);
  std::cout << "reverse [1, 5)" << std::endl;
  out(v7);
  std::cout << std::endl;

  // O(n)
  v7.insert(v7.begin(), 1);
  v7.insert(v7.begin()+4, 10);
  std::cout << "insert 1 at 0-index" << std::endl;
  std::cout << "insert 10 at 4-index" << std::endl;
  out(v7);
  std::cout << std::endl;

  v7.push_back(99);
  std::cout << "push back 99" << std::endl;
  out(v7);
  std::cout << std::endl;

  v7.pop_back();
  v7.pop_back();
  v7.pop_back();
  std::cout << "pop back 3 times" << std::endl;
  out(v7);
  std::cout << std::endl;


  std::vector<int> v8(10);
  std::iota(v8.begin(), v8.end(), 1);
  out(v8);

  int sm = std::accumulate(v8.begin(), v8.end(), 0);
  std::cout << "default accumulate, sum of 1 ~ 10: " << sm << std::endl;

  int prod = std::accumulate(v8.begin(), v8.end(), 1, [](int acc, int cur){
    return acc * cur;
  });
  std::cout << "designated accumulate, product of 1 ~ 10: " << prod << std::endl;
  std::cout << std::endl;

  // Python, JavaScriptなどのmap相当
  // 直感的じゃないな...
  std::vector<int> v9;
  std::transform(v8.begin(), v8.end(), std::back_inserter(v9), [](int x){
    return x * 2;
  });
  std::cout << "twice all element" << std::endl;
  out(v9);
  std::cout << std::endl;



  // 2d
  std::vector<std::vector<int>> vv(10, std::vector<int>(10));
  for(int i = 0; i < 10; i++) {
    std::iota(vv.at(i).begin(), vv.at(i).end(), i*10);
  }

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++) {
      if(j) std::cout << " ";
      std::cout << vv.at(i).at(j);
    }
    std::cout << std::endl;
  }

  // zip_viewはおいておく...
  // C++でzipは使わない...
}

int main() {
  practice_vector();
  return 0;
}