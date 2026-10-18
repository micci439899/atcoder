# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void print_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void print_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}

int main() {
  ll n, r;
  cin >> n >> r;

  //ll left_num = 0;
  //ll right_num = 0;
  ll min_idx = -1;
  ll max_idx = -1;

  bool is_first = true;
  vector<ll> l(n);
  rep_ll(i, n){
    cin >> l.at(i);
    if(l.at(i) == 1){
      // 左のロック数、右のロック数
      //if(i < r){
      //  left_num++;
      //}else{
      //  right_num++;
      //}
    }else{
      // 0の左端、右端
      if(is_first){
        min_idx = i;
        is_first = false;
      }else{
        max_idx = i;
      }
    }
  }

  cout << "min:" << min_idx << endl;
  cout << "max:" << max_idx << endl;
  cout << "r:" << r << endl;

  if(max_idx < r){
    ll ans = 0;
    for(ll i = min_idx; i < r; i++){
      if(l.at(i) == 1){
        ans += 2;
      }else{
        ans++;
      }
    }
    cout << ans << endl;
    return 0;
  }

  if(r < min_idx){
    ll ans = 0;
    for(ll i = r+1; i < max_idx; i++){
      if(l.at(i) == 1){
        ans += 2;
      }else{
        ans++;
      }
    }
    cout << ans << endl;
    return 0;
  }

  ll ans = 0;
  for(ll i = min_idx; i < max_idx+1; i++){
    if(l.at(i) == 1){
      ans += 2;
    }else{
      ans++;
    }
  }
  cout << ans << endl;
  return 0;



  // rep_ll(i, n){
  //   if(l.at(i) == 1){
  //     if(max_idx < r){
  //       if(i < min_idx){
  //         continue;
  //       }

  //     }
  //     if(i < min_idx){
  //       continue;
  //     }


  //   }
  // }

  //if(left_num == 0 && right_num == 0){
  //  cout << 0 << endl;
  //  return 0;
  //}

  // ll ans = (left_num-1) + (r-left_num) + (right_num-1) + (n-right_num);

  // cout << ans << endl;


  return 0;
  
}
