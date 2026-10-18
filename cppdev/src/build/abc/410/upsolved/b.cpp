# include <bits/stdc++.h>
using namespace std;


int main() {
  int N, Q;
  cin >> N >> Q;

  vector<int> boxes(N, 0);

  for (int i = 0; i < Q; i++) {
    int x;
    cin >> x;
    if (x > 0) {
      boxes.at(x-1)++;
      cout << x << " ";

    } else {
      int min = 110;
      int min_idx = 0;
      for (int j = 0; j < N; j++) {
        if (boxes.at(j) < min) {
          min = boxes.at(j);
          min_idx = j;
        }
      }
      boxes.at(min_idx)++;
      cout << min_idx+1 << " ";
    }
  }


  return 0;
}











