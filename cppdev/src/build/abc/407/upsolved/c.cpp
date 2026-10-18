#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  string S;
  cin >> S;

  int n = S.size();
  int cnt = 0;
  for (int i = n-1; i >=0; i--) {
    int d = S.at(i) - '0';
    cnt += (d - (cnt % 10) + 10) % 10;
  }

  cnt += n;
  cout << cnt << endl;
  
}
