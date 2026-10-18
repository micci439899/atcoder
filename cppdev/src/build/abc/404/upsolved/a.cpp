# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  string S;
  cin >> S;

  string T = "abcdefghijklmnopqrstuvwxyz";
  for(auto c : S) {
    rep(i, T.size()){
      if(c == T.at(i)){
        T.erase(T.begin() + i);
      }
    }
  }


  cout << T.at(0) << endl;





  return 0;
}
