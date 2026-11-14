#include <algorithm>
#include <iostream>
// #include <vector>
#include <string>

void practice_string() {
  std::string s = "abcdeababab";

  std::cout << "origin" << std::endl;
  std::cout << s << std::endl;
  std::cout << std::endl;

  std::cout << "sub string: 3 characters from 2nd" << std::endl;
  std::string s_sub = s.substr(2, 3);
  std::cout << s_sub << std::endl;
  std::cout << std::endl;

  int cnt = std::count(s.begin(), s.end(), 'a');
  std::cout << "count of a: " << cnt << std::endl;
  std::cout << std::endl;

  std::cout << "first: " << s.front() << std::endl;
  std::cout << "last: " << s.back() << std::endl;
  std::cout << "min: " << *min_element(s.begin(), s.end()) << std::endl;
  std::cout << "max: " << *max_element(s.begin(), s.end()) << std::endl;
  std::cout << std::endl;

  std::string t = s;
  reverse(t.begin(), t.end());
  std::cout << "reverse" << std::endl;
  std::cout << t << std::endl;
  std::cout << std::endl;

  t = s;
  sort(t.begin(), t.end());
  std::cout << "sort" << std::endl;
  std::cout << t << std::endl;
  std::cout << std::endl;

  std::string many_alpha = "";
  for(int i = 0; i < 26; i++) {
    // 指定した文字の繰り返しができる
    std::string alpha(i+1, 'a'+i);
    many_alpha += alpha;
  }
  std::cout << "alphabet concat a, bb, ccc, ..." << std::endl;
  std::cout << many_alpha << std::endl;
  std::cout << std::endl;


  auto it = std::lower_bound(t.begin(), t.end(), 'b');
  int idx = it - t.begin();
  std::cout << "lower bound b index: " << idx << std::endl;

  it = std::upper_bound(t.begin(), t.end(), 'b');
  idx = it - t.begin();
  std::cout << "upper bound b index: " << idx << std::endl;
  std::cout << std::endl;

  int x = 9e8;
  std::string xs = std::to_string(x);
  std::cout << "integer: " << x << ", integer to string: " << xs << std::endl;

  long long y = 1e18;
  std::string ys = std::to_string(y);
  std::cout << "long long: " << y << ", long long to string: " << ys << std::endl;

  std::string zs = "1234567890";
  int zi = std::stoi(zs);
  std::cout << "string: " << zs << ", string to integer: " << zi << std::endl;

  std::string ws = "12345678901234567";
  // error
  // int wi = std::stoi(ws);
  long long wl = std::stoll(ws);
  std::cout << "string: " << ws << ", string to long long: " << wl << std::endl;

}

int main() {
  practice_string();
  return 0;
}