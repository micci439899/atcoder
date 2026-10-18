# include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string T, A;
  cin >> N >> T >> A;

  bool exist = false;
  for (int i = 0; i < N; i++) {
    if (T.at(i) == 'o' && A.at(i) == 'o') {
      exist = true;
      break;
    }
  }

  if (exist) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }




  return 0;
}
