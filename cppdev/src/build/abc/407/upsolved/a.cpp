# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  int A, B;
  cin >> A >> B;

  int c = (A * 10 / B) % 10;
  int d = A / B;

  if(c < 5) {
    cout << d << endl;
  } else {
    cout << (d+1) << endl;
  }


  return 0;
}
