# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i, n){
    cin >> a.at(i);
  }

  bool exist = false;
  rep(i, n-2){
    if(a.at(i) == a.at(i+1) && a.at(i) == a.at(i+2)){
      exist =true;
      break;
    }
  }

  if(exist){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }






  return 0;
}
