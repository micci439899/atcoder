# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  string s;
  cin >> s;

  int a = int(s.at(0) - '0');
  int b = int(s.at(2) - '0');

  if(b < 8){
    cout << a << "-" << b+1 << endl;
  }else{
    cout << a+1 << "-" << 1 << endl;
  }









  return 0;
}
