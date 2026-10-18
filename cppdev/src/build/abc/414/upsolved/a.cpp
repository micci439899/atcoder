#include <bits/stdc++.h>
using namespace std;


int main() {
  int N, L, R;
  cin >> N >> L >> R;
  
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    int X, Y;
    cin >> X >> Y;
    if (X <= L && R <= Y) {
      cnt++;
    }
  }
  cout << cnt << endl;
  
}
