# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)


int main() {
  int N, M;
  cin >> N >> M;

  vector<int> A(N);
  set<int> S;
  rep(i, N) {
    int a_i;
    cin >> a_i;
    A.at(i) = a_i;
    S.insert(a_i);
  }

  int ans = 0;
  while(true) {
    set<int> S;
    rep(i, A.size()) {
      S.insert(A.at(i));
    }
    if (S.size() < M) {
      break;
    }
    A.pop_back();
    ans++;
  }


  cout << ans << endl;

  return 0;
}











