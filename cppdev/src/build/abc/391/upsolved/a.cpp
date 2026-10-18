# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  string d;
  cin >> d;

  for(auto c : d) {
    if(c == 'N') {
      cout << 'S';
    } else if(c == 'E') {
      cout << 'W';
    } else if(c == 'W') {
      cout << 'E';
    } else {
      cout << 'N';
    }
  }

  cout << endl;




  return 0;
}
