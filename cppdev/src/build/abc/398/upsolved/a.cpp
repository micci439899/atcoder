# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  int n;
  cin >> n;

  bool is_even = n%2 == 0;
  int center = n/2;

  string s = "";
  rep(i, n) {
    if(is_even) {
      if(i == center || i == center - 1) {
        s.push_back('=');
      } else {
        s.push_back('-');
      }
    } else {
      if(i == center) {
        s.push_back('=');
      } else {
        s.push_back('-');
      }
    }
  }






  cout << s << endl;




  return 0;
}
