#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, Q;
  cin >> N >> Q;

  vector<int> as(N);
  for (int i = 0; i < N; i++) {
    as.at(i) = i+1;
  }

  ll shifted_idx = 0;
  for (int i = 0; i < Q; i++) {
    int q_type;
    cin >> q_type;

    if (q_type == 1) {
      int p, x;
      cin >> p >> x;
      int idx = (p-1 + shifted_idx) % N;
      as.at(idx) = x;

    } else if (q_type == 2) {
      int p;
      cin >> p;
      int idx = (p-1 + shifted_idx) % N;
      cout << as.at(idx) << endl;

    } else {
      ll k;
      cin >> k;
      shifted_idx = (shifted_idx + k) % N;

    }
  }

  
}
