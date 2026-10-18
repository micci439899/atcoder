# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {

  vector<int> x(4);
  rep(i, 4){
    cin >> x.at(i);
  }
  sort(x.begin(), x.end());

  if(x.at(0) < x.at(1) && x.at(1) == x.at(2) && x.at(1) == x.at(3)
    || x.at(1) < x.at(2) && x.at(0) == x.at(1) && x.at(2) == x.at(3)
    || x.at(2) < x.at(3) && x.at(0) == x.at(1) && x.at(1) == x.at(2)){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }


  return 0;
}
