# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)


int main() {
  int n, m;
  cin >> n >> m;

  vector<string> ss(n);
  rep(i, n) {
    string s;
    cin >> s;
    ss.at(i) = s;
  }

  vector<int> scores(n);


  rep(i, m) {
    int one_cnt = 0;
    int zero_cnt = 0;
    rep(j, n) {
      if(ss.at(j).at(i) == '1') {
        one_cnt++;
      } else {
        zero_cnt++;
      }
    }

    rep(j, n) {
      if(one_cnt == 0 || zero_cnt == 0) {
        scores.at(j)++;
        continue;
      }
      if(ss.at(j).at(i) == '1' && one_cnt < zero_cnt) {
        scores.at(j)++;
      }
      if(ss.at(j).at(i) == '0' && zero_cnt < one_cnt) {
        scores.at(j)++;
      }
    }
  }

  int max_score = *max_element(begin(scores), end(scores));

  rep(j, n) {
    if(scores.at(j) == max_score){
      cout << j+1 << " ";
    }
  }
  cout << endl;


  return 0;

}











