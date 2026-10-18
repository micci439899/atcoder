# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  string s;
  cin >> s;

  cout << 0 << endl;

/*
  if(n == 1LL){
    cout << 0 << endl;
    return 0;
  }

  ll a_cnt = 0LL;
  ll b_cnt = 0LL;


  ll ans = 0;
  for(int l=0; l < n; l++){
    int r = l;
    while(true){
      if(s.at(r) == 'a'){
        a_cnt++;
      }else{
        b_cnt++;
      }

      r++;
      // 最後まで行った or 条件を満たすところまできた
      if(r >= n || (a_cnt >= a && b_cnt < b)) break;
    }

    if(r >= n) break;

    while(true){
      if(s.at(r) == 'a'){
        a_cnt++;
      }else{
        b_cnt++;
      }

      ans++;
      r++;
      // 最後まで行った or 条件を満たさなくなった
      if(r >= n || (a_cnt < a || b_cnt >= b)) break;
    }
  }


  cout << ans << endl;
*/



/*
  // int s_idx = 0;
  // int e_idx = 0;

  ll ans = 0;
  for(int s_idx = 0; s_idx < n; s_idx++){
    int e_idx = s_idx;
    //while(e_idx < n && (a_cnt < a || b_cnt >= b)){
    cout << "not ok" << endl;
    while(true){
      cout << e_idx << endl;
      if(s.at(e_idx) == 'a'){
        a_cnt++;
      }else{
        b_cnt++;
      }
      e_idx++;

      if(e_idx >= n) break;

      if(e_idx < n && (a_cnt < a || b_cnt >= b)) break;
    }

    if(e_idx >= n) break;

    cout << "ok" << endl;
    while(true){
      cout << e_idx << endl;
      if(s.at(e_idx) == 'a'){
        a_cnt++;
      }else{
        b_cnt++;
      }
      e_idx++;

      if(a_cnt >= a && b_cnt < b) ans++;

      if(e_idx >= n) break;
      if(e_idx < n && (a_cnt < a || b_cnt >= b)) break;
    }
    if(a_cnt >= a && b_cnt < b) ans++;
    cout << "s_idx: " << s_idx << " e_idx: " << e_idx << endl;
    cout << "a_cnt: " << a_cnt << " b_cnt: " << b_cnt << endl;
    cout << endl;
  }

  cout << ans << endl;
*/


/*
  ll a_cnt = 0LL;
  ll b_cnt = 0LL;
  int s_idx = 0;
  if(s.at(0) == 'a'){
    a_cnt++;
  }else{
    b_cnt++;
  }

  ll ans = 0;
  for(int e_idx = 1; e_idx < n; e_idx++){
    cout << "s_idx: " << s_idx << " e_idx: " << e_idx << endl;
    cout << "a_cnt: " << a_cnt << " b_cnt: " << b_cnt << endl;
    cout << endl;
    if(s.at(e_idx) == 'a'){
      a_cnt++;
    }else{
      b_cnt++;
    }

    if(e_idx - s_idx < a) continue;

    if(a_cnt >= a && b_cnt < b){
      ans++;
    }else{
      if(s.at(s_idx) == 'a'){
        a_cnt--;
      }else{
        b_cnt--;
      }
      s_idx++;
    }
  }

  cout << ans << endl;
*/




  return 0;  
}
