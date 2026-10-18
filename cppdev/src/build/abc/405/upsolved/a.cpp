# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  int R, X;
  cin >> R >> X;

  bool is_rated = false;
  if (X == 1) {
    if (1600 <= R && R <= 2999) {
      is_rated = true;
    }
  } else if (X == 2) {
    if (1200 <= R && R <= 2399) {
      is_rated = true;
    }
  }

  if (is_rated) cout << "Yes" << endl;
  else cout << "No" << endl;


  return 0;
}
