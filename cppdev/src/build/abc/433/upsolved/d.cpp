# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

// 立式すると
// a_i * 10^k + a_j \equiv 0 (mod M)
// \iff a_j \equiv - a_i * 10^k (mod M)

// a_jが1のとき、kは1
// a_jが10^9のとき、kは10

int main() {
  int n;
  ll m;
  cin >> n >> m;

  vector<int> a(n);
  rep(i, n) cin >> a.at(i);

  // 剰余を桁数毎にリストで保持（10まであれば良い）
  vector<vector<int>> b(11);
  rep(i, n){
    int digit = to_string(a.at(i)).size();
    b.at(digit).push_back(a.at(i) % m);
  }

  rep(i, b.size()){
    sort(b.at(i).begin(), b.at(i).end());
  }

  ll ans = 0;
  rep(i, n){
    ll a_i = a.at(i);
    for(int j = 1; j < b.size(); j++){
      // a_i * 10^k(mod M)
      a_i *= 10;
      a_i %= m;

      // - a_i * 10^k(mod M)
      int target = (m - a_i) % m;

      // modの値が同じ個数を求めたい
      // 0 ~ m-1が重複ありで単調増加しているはず
      // 同じ値の個数は同じ値の最左から1加算した分の最左
      ll cnt = lower_bound(b.at(j).begin(), b.at(j).end(), target+1)
                - lower_bound(b.at(j).begin(), b.at(j).end(), target);
      ans += cnt;
    }
  }

  cout << ans << endl;

  return 0;
}
