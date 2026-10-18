# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)



int find_max(vector<pair<int, int>> ps, int n) {
  int max_val=0;
  rep(i, n) {
    if(ps.at(i).second > 0) continue;
    if(ps.at(i).first > max_val) max_val = ps.at(i).first;
  }
  return max_val;
}

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> ps(n);
  rep(i, n) {
    int p;
    cin >> p;
    ps.at(i) = make_pair(p, 0);
  }


  //auto cmp = [](pair<int, int> &a, pair<int, int> &b) {
  //  return a.first < b.first;
  //};

  int r = 1;
  int sz = 0;
  while(true) {
    if(sz >= ps.size())break;

    //pair<int, int> max_value_pair = *max_element(begin(ps), end(ps), cmp);
    int max_value = find_max(ps, n);
    int cnt = 0;
    rep(i, n) {
      if(ps.at(i).second > 0)continue;

      //if(ps.at(i).first == max_value_pair.first) {
      if(ps.at(i).first == max_value) {
        ps.at(i).second = r;
        cnt++;
      }
    }
    r += cnt;
    sz += cnt;
  }

  rep(i, n) {
    cout << ps.at(i).second << endl;
  }


  return 0;

}











