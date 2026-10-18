# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;

  int ans = 0;
  rep(i, n) {
    if(s.at(i) != t.at(i)) ans++;
  }

  cout << ans << endl;




  return 0;
}
