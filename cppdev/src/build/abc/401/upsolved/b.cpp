# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)


int main() {
  int n;
  cin >> n;

  bool has_logged_in = false;
  int cnt = 0;
  rep(i, n) {
    string s;
    cin >> s;
    if (s == "login") {
      has_logged_in = true;
    } else if (s == "logout") {
      has_logged_in = false;
    } else if (s == "private") {
      if(!has_logged_in) {
        cnt++;
      }
    }
  }

  cout << cnt << endl;


  return 0;
}











