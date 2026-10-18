# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  int n;
  char c1, c2;
  cin >> n >> c1 >> c2;

  string s;
  cin >> s;

  for(auto c : s){
    if(c != c1){
      cout << c2;
    }else{
      cout << c;
    }
  }
  cout << endl;




  return 0;
}
