# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  string s;
  cin >> s;

  for(auto c : s) {
    if ('A' <= c && c <= 'Z'){
      cout << c;
    }
  }



  return 0;
}
