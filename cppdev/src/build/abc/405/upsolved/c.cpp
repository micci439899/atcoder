#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  ll N;
  cin >> N;

  vector<int> A(N);
  rep(i, N) {
    cin >> A.at(i);
  }

  ll ans = 0;
  ll cumsum = A.at(0);

  for(int i = 1; i < N; i++) {
    ans += cumsum * A.at(i);
    cumsum += A.at(i);
  }

  cout << ans << endl;
  
}
