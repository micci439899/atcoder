#include <bits/stdc++.h>
using namespace std;


int main() {
  // 入力を受け取る
  string S;
  cin >> S;
  
  int first = -1;
  int second = -1;
  int count = 0;
  for (int i = 0; i < (int)S.size(); i++) {
    if(S.at(i) == '#') {
      if(count == 0) {
        first = i+1;
        count++;
      } else {
        second = i+1;
        cout << first << "," << second << endl;
        count = 0;
      }
    }
  }

}