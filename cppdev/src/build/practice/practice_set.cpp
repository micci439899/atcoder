#include <iostream>
#include <set>

void practice_set() {
  std::set<int> st;
  st.insert(1);
  st.insert(1);
  st.insert(2);
  st.insert(3);
  st.insert(10);

  for(auto s : st) {
    std::cout << s << std::endl;
  }

  if(st.count(1)){
    std::cout << "1 is contained" << std::endl;
  }
  if(!st.count(5)){
    std::cout << "5 is not contained" << std::endl;
  }

  // lower_bound(st.begin(), st.end())とすると時間かかる
  auto it = st.lower_bound(1);
  if(it != st.end()){
    std::cout << "lower bound 1: " << *it << std::endl;
  }

  it = st.upper_bound(3);
  if(it != st.end()){
    std::cout << "upper bound 3: " << *it << std::endl;
  }

  bool erased = st.erase(3);
  if(erased){
    std::cout << "3 is contained and erased" << std::endl;
  }
  erased = st.erase(4);
  if(!erased){
    std::cout << "4 is not contained and ignored" << std::endl;
  }

  st.clear();
  st.insert(1);
  st.insert(10);
  st.insert(100);
  st.insert(1000);
  st.insert(10000);
  st.insert(100000);
  it = st.begin();
  it++;
  st.erase(it);
  for(auto s : st) {
    std::cout << s << std::endl;
  }
}

int main() {
  practice_set();
  return 0;
}


