# include <bits/stdc++.h>
using namespace std;


int main() {
  string S, T;
  cin >> S >> T;

  bool is_contained = true;
  for (int i = 1; i < S.size(); i++) {
    if(isupper(S.at(i))) {
      if(T.find(S.at(i-1)) == string::npos) {
        is_contained = false;
        break;
      }
    }
  }

  if(is_contained) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}











