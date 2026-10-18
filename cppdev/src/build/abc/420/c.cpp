#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  ll n, q;
  cin >> n >> q;

  vector<ll> a(n);
  rep(i, n) {
    cin >> a.at(i);
  }

  vector<ll> b(n);
  rep(i, n) {
    cin >> b.at(i);
  }

  ll min_sum_value = 0;
  rep(i, n) {
    min_sum_value += min(a.at(i), b.at(i));
  }


  rep(i, q) {
    string c;
    ll x, v;
    cin >> c >> x >> v;


    if(c == "A") {
      ll bfr = a.at(x-1);
      a.at(x-1) = v;

      ll bfr_min = min(bfr, b.at(x-1));
      ll aftr_min = min(a.at(x-1), b.at(x-1));

      if(bfr_min != aftr_min) {
        min_sum_value += aftr_min;
        min_sum_value -= bfr_min;
      }

      // if(bfr < b.at(x-1) && v < b.at(x-1)) {
      //   cout << min_sum_value << endl;
      //   continue;
      // }
      // min_sum_value += min(a.at(x-1), b.at(x-1));;
      // min_sum_value -= min(a.at(x-1), bfr);

      // if(a.at(x-1) < b.at(x-1)){
      //   min_sum_value += min(a.at(x-1), b.at(x-1));;
      //   min_sum_value -= min(a.at(x-1), bfr);
      // } else {
      //   min_sum_value += min(a.at(x-1), b.at(x-1));;
      //   min_sum_value -= min(a.at(x-1), bfr);
      // }
      cout << min_sum_value << endl;

    } else {
      ll bfr = b.at(x-1);
      b.at(x-1) = v;

      ll bfr_min = min(bfr, a.at(x-1));
      ll aftr_min = min(a.at(x-1), b.at(x-1));

      if(bfr_min != aftr_min) {
        min_sum_value += aftr_min;
        min_sum_value -= bfr_min;
      }
      // if(bfr < a.at(x-1) && v < a.at(x-1)) {
      //   cout << min_sum_value << endl;
      //   continue;
      // }
      // min_sum_value += min(b.at(x-1), a.at(x-1));;
      // min_sum_value -= min(b.at(x-1), bfr);
      // if(b.at(x-1) < a.at(x-1)) {
      //   min_sum_value += min(a.at(x-1), b.at(x-1));;
      //   min_sum_value -= min(b.at(x-1), bfr);
      // } else {
      //   min_sum_value += min(a.at(x-1), b.at(x-1));;
      //   min_sum_value -= min(b.at(x-1), bfr);
      // }
      cout << min_sum_value << endl;
    }
  }



  return 0;
  
}
