# include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> as(N);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    as.at(i) = a;
  }

  int K;
  cin >> K;

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (K <= as.at(i)){
      cnt++;
    }
  }

  cout << cnt << endl;


  return 0;
}
