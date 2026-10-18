# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  int n;
  cin >> n;

  vector<string> ss(n);

  rep(i, n){
    cin >> ss.at(i);
  }

  auto cmp = [](const string &a, const string &b) { return a.size() < b.size();};
  sort(ss.begin(), ss.end(), cmp);

  string ans = "";
  for(auto s : ss){
    ans += s;
  }

  cout << ans << endl;




  return 0;

}











