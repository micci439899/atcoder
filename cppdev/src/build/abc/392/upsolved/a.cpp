# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  int a1, a2, a3;
  cin >> a1 >> a2 >> a3;

  if(a1 * a2 == a3 || a1 * a3 == a2 || a2 * a3 == a1){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }


  return 0;
}
