# include <bits/stdc++.h>
using namespace std;


bool is_target(string s) {
  if (s.size() < 3) {
    return false;
  }

  if (s.at(0) != 't' || s.at(s.size()-1) != 't') {
    return false;
  }

  return true;
}

long double find_t_rate(string s) {
  int cnt = 0;
  for (auto c : s) {
    if (c == 't') {
      cnt++;
    }
  }

  return (cnt-2.0) / (s.size()-2.0);
}

int main() {
  string S;
  cin >> S;

  long double ans = 0;
  if (is_target(S)){
    ans = find_t_rate(S);
  }

  for (int i = 3; i <= (int)S.size(); i++) {
    for (int j = 0; j < S.size()-i; j++) {
      string T = S.substr(j, i);
      if(!is_target(T)){
        continue;
      }
      double t_rate = find_t_rate(T);
      if (ans < t_rate) {
        ans = t_rate;
      }
    }
  }

  cout << setprecision(11) << ans << endl;
  return 0;
}











