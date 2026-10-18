# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  double x;
  cin >> x;

  if(38 <= x) {
    cout << 1 << endl;
  } else if(37.5 <= x && x < 38) {
    cout << 2 << endl;
  } else {
    cout << 3 << endl;
  }


  return 0;
}
