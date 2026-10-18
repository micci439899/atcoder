# include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;

  if (N < 3) {
    cout << "No" << endl;
    return 0;
  }

  char a = S.at(N-3);
  char b = S.at(N-2);
  char c = S.at(N-1);

  if (a == 't' && b == 'e' && c == 'a') {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
