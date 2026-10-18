# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  vector<int> a(5);
  rep(i, 5){
    cin >> a.at(i);
  }


  
  bool is_ok1 = a.at(0) == 2 && a.at(1) == 1
  && a.at(2) == 3 && a.at(3) == 4 && a.at(4) == 5;

  bool is_ok2 = a.at(0) == 1 && a.at(1) == 3
  && a.at(2) == 2 && a.at(3) == 4 && a.at(4) == 5;

  bool is_ok3 = a.at(0) == 1 && a.at(1) == 2
  && a.at(2) == 4 && a.at(3) == 3 && a.at(4) == 5;

  bool is_ok4 = a.at(0) == 1 && a.at(1) == 2
  && a.at(2) == 3 && a.at(3) == 5 && a.at(4) == 4;

  if(is_ok1 || is_ok2 || is_ok3 || is_ok4){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }





  return 0;
}
