#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, L, R;
  string S;
  cin >> N >> L >> R >> S;
  
  bool is_ok = true;
  for (int i= L-1; i <= R-1; i++) {
    if (S.at(i) == 'x') {
      is_ok = false;
    }
  }
  
  if (is_ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  
}