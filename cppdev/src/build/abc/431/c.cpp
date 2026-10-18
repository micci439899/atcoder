# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> h(n);
  rep_ll(i, n) cin >> h.at(i);

  vector<ll> b(m);
  rep_ll(i, m) cin >> b.at(i);

  cout << "Yes" << endl;


/*
  sort(h.rbegin(), h.rend());
  sort(b.rbegin(), b.rend());

  cout << "h" << endl;
  out_vec(h);

  cout << "b" << endl;
  out_vec(b);

  ll b_idx = 0LL;
  ll res = 0LL;
  rep_ll(i, n){
    while(h.at(i) > b.at(b_idx)){
      b_idx++;
      if(b_idx >= m){
        out_yn(false);
        return 0;
      }
    }

    if(h.at(i) <= b.at(b_idx)){
      res++;
      b_idx++;

      cout << "h: "<< h.at(i) << " b: " << b.at(b_idx) << " res: " << res << endl;
    }

    if(res == k){
      out_yn(true);
      return 0;
    }
  }

  out_yn(false);
*/


/*
  ll b_idx = 0LL;
  ll res = 0LL;
  rep_ll(i, n){
    if(b_idx >= m){
      out_yn(false);
      return 0;
    }
    if(h.at(i) == b.at(b_idx)){
      res++;
      b_idx++;
      if(res == k){
        out_yn(true);
        return 0;
      }
      continue;
    }

    while(h.at(i) < b.at(b_idx)){
      b_idx++;
      if(b_idx >= m){
        out_yn(false);
        return 0;
      }
    }

    // if(b_idx >= m){
    //   out_yn(false);
    //   return 0;
    // }
    cout << "h: "<< h.at(i) << " b: " << b.at(b_idx) << " res: " << res << endl;


    if(h.at(i) <= b.at(b_idx)){
      res++;
      b_idx++;
      if(res == k){
        out_yn(true);
        return 0;
      }
      continue;
    }

  }

  out_yn(false);
*/


/*
  cout << "h" << endl;
  out_vec(h);

  cout << "b" << endl;
  out_vec(b);

  ll b_idx = 0LL;
  ll res = 0LL;
  rep(i, n){
    if(b_idx >= m){
      cout << "res: " << res << endl;
      cout << "aaa" << endl;
      out_yn(false);
      return 0;
    }

    if(res == k){
      out_yn(true);
      return 0;
    }

    bool is_proceeded = false;
    while(h.at(i) < b.at(b_idx)){
      b_idx++;
      is_proceeded = true;
    }

    res++;
    if(is_proceeded){
      b_idx++;
    }

    // cout << "h: "<< h.at(i) << " b: " << b.at(b_idx) << " res: " << res << endl;

  }

  out_yn(false);
*/

/*
  vector<bool> b_used(m, false);

  sort(h.rbegin(), h.rend());
  sort(b.begin(), b.end());

  ll min_idx = INT_MAX;
  ll res = 0LL;

  cout << "h" << endl;
  out_vec(h);

  cout << "b" << endl;
  out_vec(b);


  rep_ll(i, n){
    auto it = lower_bound(b.begin(), b.end(), h.at(i));
    if(it != b.end()){
      cout << "h_i: " << h.at(i) << " found: " << *it << endl;
      size_t pos = distance(b.begin(), it);
      if(min_idx < pos) continue;

      if(min_idx != INT_MAX && )



      min_idx = min(min_idx, ll(pos-1));
      res++;
      if(res == k){
        out_yn(true);
        return 0;
      }
    }
  }


  out_yn(false);
*/




  return 0;  
}
