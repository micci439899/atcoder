# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int n, r;
  cin >> n >> r;

  vector<int> l(n);
  rep(i, n) cin >> l.at(i);

  // 開いてるドアのうち一番左（0-indexed）
  int min_id = 2*n;
  rep(i, n){
    if(l.at(i) == 0){
      min_id = i;
      break;
    }
  }

  // 開いてるドアが1つもないとき
  if(min_id > n){
    cout << 0 << endl;
    return 0;
  }

  // 開いてるドアのうち一番右（0-indexed）
  int max_id = -1;
  for(int i = l.size()-1; i > 0; i--){
    if(l.at(i) == 0){
      max_id = i;
      break;
    }
  }

  ll ans = 0;

  // 部屋0, ドア1, 部屋1, ドア2, ..., ドアR, 部屋R（高橋君）, ドアR+1, ..., ドアN, 部屋N

  if(max_id < r){
    // 開いてるドアが高橋君の左側にしかないとき
    // ドア1 ~ ドアR
    // -> 0 ~ r-1
    for(int i = min_id; i < r; i++){
      ans += l.at(i) == 0 ? 1 : 2;
    }
  }else if(r < min_id){
    // 開いてるドアが高橋君の右側にしかないとき
    // ドアR+1 ~ ドアN
    // -> r ~ n-1
    for(int i = r; i <= max_id; i++){
      ans += l.at(i) == 0 ? 1 : 2;
    }
  }else{
    // 開いてるドアが高橋君の右にも左にもあるとき
    // -> min_id ~ max_id
    for(int i = min_id; i <= max_id; i++){
      ans += l.at(i) == 0 ? 1 : 2;
    }
  }

  cout << ans << endl;

  return 0;  
}
