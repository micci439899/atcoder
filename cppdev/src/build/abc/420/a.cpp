# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  int x, y;
  cin >> x >> y;

  if ((x + y) % 12 == 0){
    cout << 12 << endl;
  } else {
    cout << (x+y)%12 << endl;
}


  return 0;
}
