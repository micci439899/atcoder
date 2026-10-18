# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  int N, S;
  cin >> N >> S;

  int prev = 0;
  rep(i, N) {
    int T;
    cin >> T;

    if (T - prev >= S + 1) {
      cout << "No" << endl;
      return 0;
    }
    prev = T;
  }

  cout << "Yes" << endl;



  return 0;
}
