#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  set<string> ss;
  vector<string> s_vec(N);
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    s_vec.at(i) = s;
  }
  
  for (int i = 0; i < N; i++) {
    for (int j= 0; j < N; j++) {
      if (i == j) {
        continue;
      }
      ss.insert(s_vec.at(i) + s_vec.at(j));
    }
  }
  
  cout << ss.size() << endl;

  
}