# include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    if (A < B) {
      cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}
