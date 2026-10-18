# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  if(a + b == c || b + c == a || c + a == b || a == b && a == c){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }


  return 0;
}
