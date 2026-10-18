#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  string s;
  cin >> s;

  reverse(s.begin(), s.end());

  for(ll i = 0; i < s.size()-1; i++) {
    if(s.at(i) == 'A' && s.at(i+1) == 'W'){
      s.at(i) = 'C';
      s.at(i+1) = 'A';
    }
  }
  reverse(s.begin(), s.end());

  cout << s << endl;

  return 0;
  
}
