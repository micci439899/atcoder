# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  int a;
  cin >> a;

  if(400%a == 0) {
    cout << 400/a << endl;
  } else {
    cout << -1 << endl;
  }



  return 0;
}
