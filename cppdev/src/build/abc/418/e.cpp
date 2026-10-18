#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<ll> xs(N);
  vector<ll> ys(N);
  for (int i = 0; i < N; i++) {
    ll x, y;
    cin >> x >> y;
    xs.at(i) = x;
    ys.at(i) = y;
  }

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      ll x_inc = xs[j] - xs[i];
      ll y_inc = ys[j] - ys[j];

      for (int k = j+1; k < N; k++) {
        for (int l = k+1; l < N; l++) {
          ll x_inc2 = xs[l] - xs[k];
          ll y_inc2 = ys[l] - ys[k];

          if(x_inc * y_inc2 == x_inc2 * y_inc) {
            //cout << "(" << xs[i] << ", " << ys[i] << "), ";
            //cout << "(" << xs[j] << ", " << ys[j] << "), ";
            //cout << "(" << xs[k] << ", " << ys[k] << "), ";
            //cout << "(" << xs[l] << ", " << ys[l] << "), " << endl;
            cnt++;
          }
        }
      }
    }
  }



  cout << cnt << endl;
  
}
