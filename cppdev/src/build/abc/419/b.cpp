# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)


int main() {
  int Q;
  cin >> Q;

  map<int, int> m;
  rep(i, Q) {
    int q_type;
    cin >> q_type;

    if (q_type == 1) {
      int x;
      cin >> x;
      if(m.count(x)){
        m.at(x) = m.at(x) + 1;
      } else {
        m[x] = 1;
      }
    } else {
      for (auto p : m) {
        if (p.second == 0) {
          continue;
        }
        cout << p.first << endl;
        m[p.first]--;
        break;
      }
    }
  }


  return 0;
}











