# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  string S;
  cin >> S;

  if (S == "red") {
    cout << "SSS" << endl;
  } else if(S == "green") {
   cout << "MMM" << endl;
  } else if(S == "blue") {
   cout << "FFF" << endl;
  } else {
   cout << "Unknown" << endl;
  }


  return 0;
}
