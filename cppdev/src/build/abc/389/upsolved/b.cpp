# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)


int main() {
  ll x;
  cin >> x;

  ll d = 2;
  while(true){
    x = x/d;
    if(x == 1){
      break;
    }
    d++;
  }

  cout << d << endl;



  return 0;

}











