# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

vector<ll> fib(11, -1);

ll f(ll x){
  string x_s = to_string(x);
  reverse(x_s.begin(), x_s.end());
  return stoll(x_s);
}

ll func(ll i){
  if(i == 0){
    return fib.at(0);
  } else if(i == 1){
    return fib.at(1);
  } else {
    if(fib.at(i) > 0){
      return fib.at(i);
    }

    fib.at(i) = f(func(i-1) + func(i-2));
    return fib.at(i);
  }
}


int main() {
  ll x, y;
  cin >> x >> y;
  fib.at(0) = x;
  fib.at(1) = y;

  func(9LL);

  cout << fib.at(9LL) << endl;

  return 0;

}











