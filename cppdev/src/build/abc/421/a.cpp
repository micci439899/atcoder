# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  int n;
  cin >> n;

  vector<string> s(n);
  rep(i, n){
    cin >> s.at(i);
  }

  int x;
  string y;
  cin >> x >> y;

  if(s.at(x-1) == y){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }




  return 0;
}
