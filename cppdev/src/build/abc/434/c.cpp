# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

bool is_ok(ll cur_l, ll cur_u, ll next_l, ll next_u, ll diff_mi, ll diff_t){
  bool a = (double)diff_mi/(double)diff_t <= 1LL;
  if(cur_u < next_l){
    return a;
  }else if(cur_l > next_u){
    return a;
  }else{
    return true;
  }
}


int main() {
  int t;
  cin >> t;

  while(t--){
    ll n, h;
    cin >> n >> h;

    vector<ll> t(n);
    vector<ll> l(n);
    vector<ll> u(n);
    rep(i, n){
      cin >> t.at(i) >> l.at(i) >> u.at(i);
    }

    bool is_valid = true;

    ll next_t = t.at(n-1);
    ll next_l = l.at(n-1);
    ll next_u = u.at(n-1);
    for(int i = n-2; i >= 0; i--){
      ll cur_t = t.at(i);
      ll cur_l = l.at(i);
      ll cur_u = u.at(i);

      vector<ll> diff = {
        abs(next_l - cur_l), abs(next_l - cur_u), abs(next_u - cur_l), abs(next_u - cur_u)
      };

      ll diff_mi = *min_element(diff.begin(), diff.end());

      ll diff_t = next_t - cur_t;

      if(!is_ok(cur_l, cur_u, next_l, next_u, diff_mi, diff_t)){
        out_yn(false);
        is_valid = false;
        break;
      }else{
        next_t = cur_t;
        next_l = max(cur_l, next_l - diff_t);
        next_u = min(cur_u, next_u + diff_t);
      }
    }
    if(is_valid){
      out_yn((double)abs(next_l - h)/double(next_t) <= 1 && (double)abs(next_u - h)/double(next_t) <= 1);
    }
  }





  return 0;  
}
