#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

int main() {
  ll n, m, q;
  cin >> n >> m >> q;

  //vector<map<int, bool>> mp_vec(n);
  //vector<unordered_map<int, bool>> mp_vec(n);
  //vector<bool> page_vec(m, false);
  //vector<vector<bool>> user_vec(n, page_vec);
  vector<set<int>> st_vec(n);
  vector<bool> is_all_vec(n, false);
  rep(i, q) {
    int q_type;
    cin >> q_type;
    if(q_type == 1) {
      ll x, y;
      cin >> x >> y;
      //mp_vec.at(x-1)[y] = true;
      //user_vec.at(x-1).at(y-1) = true;
      st_vec.at(x-1).insert(y);
    } else if(q_type == 2) {
      ll x;
      cin >> x;
      is_all_vec.at(x-1) = true;

    } else {
      ll x, y;
      cin >> x >> y;

      if(is_all_vec.at(x-1)){
        cout << "Yes" << endl;
      } else {
        //unordered_map<int, bool> m = mp_vec.at(x-1);
        //if(m.count(y)){
        //if(user_vec.at(x-1).at(y-1)){
        if(st_vec.at(x-1).count(y)){
          cout << "Yes" << endl;
        } else {
          cout << "No" << endl;
        }
      }
    }
  }

  return 0;
  
}
