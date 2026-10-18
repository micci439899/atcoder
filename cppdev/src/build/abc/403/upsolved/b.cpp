# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)


int main() {
  string t, u;
  cin >> t >> u;

  vector<int> que_idx_vec;
  rep(i, t.size()){
    if(t.at(i) == '?') que_idx_vec.push_back(i);
  }

  string alphabet = "abcdefghijklmnopqrstuvwxyz";

  for(auto c1 : alphabet) {
    t.at(que_idx_vec.at(0)) = c1;
    for(auto c2 : alphabet) {
      t.at(que_idx_vec.at(1)) = c2;
      for(auto c3 : alphabet) {
        t.at(que_idx_vec.at(2)) = c3;
        for(auto c4 : alphabet) {
          t.at(que_idx_vec.at(3)) = c4;
          if (t.contains(u)) {
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  }

  cout << "No" << endl;

  return 0;
}











