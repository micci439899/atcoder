#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int Q;
  cin >> Q;

  //queue<ll> q;
  queue<pair<ll, ll>> q;
  for (int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    
    if (t == 1) {
      ll c, x;
      cin >> c >> x;
      
      //for (int i = 0; i < c; i++) {
      //  q.push(x);
      //}
      pair<ll, ll> p(c, x);
      q.push(p);

    } else {
      ll k;
      cin >> k;
      ll sm = 0;
      while (!q.empty() && q.front().first <= k) {
        sm += q.front().first * q.front().second;
        k -= q.front().first;
        q.pop();
      }
      if (k != 0) {
        q.front().first -= k;
        sm += k * q.front().second;
      }

      //for (int i = 0; i < k; i++) {
      //  sm += q.front();
      //  q.pop();
      //}
      cout << sm << endl;
    }
  }

}