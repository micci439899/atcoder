# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  string s;
  cin >> s;

  rep(i, s.size()){
    if(s.at(i) == '2'){
      cout << s.at(i);
    }
  }
  cout << endl;



  return 0;
}
