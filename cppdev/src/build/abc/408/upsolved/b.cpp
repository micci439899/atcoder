# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)


int main() {
  int N;
  cin >> N;

  set<int> S;

  rep(i, N) {
    int A;
    cin >> A;
    S.insert(A);
  }

  cout << S.size() << endl;
  for (auto s : S) {
    cout << s << " ";
  }



  return 0;
}











