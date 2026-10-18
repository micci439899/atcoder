# include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  string s1, s2;
  cin >> s1 >> s2;


  if(s1 == "sick" && s2 == "sick"){
    cout << 1 << endl;
  } else if(s1 == "sick" && s2 == "fine"){
    cout << 2 << endl;
  } else if(s1 == "fine" && s2 == "sick"){
    cout << 3 << endl;
  } else {
    cout << 4 << endl;
  }



  return 0;
}
