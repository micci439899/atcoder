#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  vector<pair<int, int>> ranges;
  int start = -1;
  int end = 0;
  bool is_last_necessary = false;
  bool is_all_o = true;
  for (int i = 0; i < (int)S.size(); i++) {
    if (S.at(i) == '#') {
      if (start < 0) {
        pair<int, int> range(0, i);
        ranges.push_back(range);
        start = i;
      } else {
        pair<int, int> range(start, i);
        ranges.push_back(range);
        start = i;
      }
      is_all_o = false;
    } else {
      if(i == (int)S.size()-1) {
        is_last_necessary = true;
      }
    }
  }
  
  //if(is_last_necessary) {
  //  pair<int, int> range(end, (int)S.size()-1);
  //  ranges.push_back(range);
  //}
  
  string T = S;
  for (int i= 0; i < (int)ranges.size(); i++) {
    pair<int, int> range = ranges.at(i);
    //cout << range.first << range.second << endl;
    for (int j = range.first+1; j < range.second-1; j++) {
      T.at(j) = 'o';
      break;
    }
  }
  
  if (ranges.size() > 0 && T.at(T.size()-1) == '.') {
    T.at(T.size()-1) = 'o';
  }
  
  if (is_all_o) {
    T.at(0) = 'o';
  }

  cout << T << endl;
  
  

  
}