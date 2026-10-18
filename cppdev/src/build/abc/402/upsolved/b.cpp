# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)


int main() {
  int q;
  cin >> q;

  queue<int> que;
  rep(i, q) {
    int q_type;
    cin >> q_type;
    if(q_type == 1) {
      int x;
      cin >> x;
      que.push(x);
    } else {
      cout << que.front() << endl;
      que.pop();
    }
  }


  return 0;
}











