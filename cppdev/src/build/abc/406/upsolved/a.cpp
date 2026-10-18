# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  if (C < A) {
    cout << "Yes" << endl;
  } else if(C == A){
    if (D < B) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
  }
  } else {
    cout << "No" << endl;
  }



  return 0;
}
