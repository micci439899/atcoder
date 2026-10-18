# include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;

  vector<int> ds(N-1);
  for (int i = 0; i < N-1; i++) {
    int d;
    cin >> d;
    ds.at(i) = d;
  }

  for(int i = 0; i < N-1; i++) {
    int len = ds.at(i);
    cout << len << " ";
    for(int j = i+1; j < N-1; j++) {
      len += ds.at(j);
      cout << len << " ";
    }
    cout << endl;
  }


  return 0;
}











