# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  stack<int> s;

  rep(i, 100){
    s.push(0);
  }

  int q;
  cin >> q;
  rep(i, q){
    int q_type;
    cin >> q_type;
    if(q_type == 1) {
      int x;
      cin >> x;
      s.push(x);
    } else {
      cout << s.top() << endl;
      s.pop();
    }
  }




  return 0;

}











