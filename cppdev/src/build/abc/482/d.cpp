// The template file is below
// https://github.com/micci439899/atcoder

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define debug(x) cerr << #x << " " << x << " " << endl;

template<class T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T>bool chmax(T&a, T b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T&a, T b){if(b<a){a=b;return true;}return false;}

template<class T, class U>ostream&operator<<(ostream&os, pair<T,U>p){os<<"("<<p.first << "," << p.second<<")";return os;}
template<class T>ostream&operator<<(ostream&os, const vector<T>&v){os<<"[";for(int i = 0; i < v.size(); i++){cout << v.at(i);if(i != v.size()-1){cout << ",";}}os<<"]";return os;}
template<class T>ostream&operator<<(ostream&os, const set<T>&st){os<<"{";int idx=0;for(auto &e : st){cout << e;if(idx != st.size()-1){cout << ",";}idx++;}os<<"}";return os;}
template<class T>ostream&operator<<(ostream&os, const multiset<T>&st){os<<"{";int idx=0;for(auto &e : st){cout << e;if(idx != st.size()-1){cout << ",";}idx++;}os<<"}";return os;}
template<class T, class U>ostream&operator<<(ostream&os, map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}
int ctoi(char c){return int(c-'0');} // e.g.) a -> 49, 1 -> 1
char itoc(int x){return x+'0';}

void solve(){
  int n; cin >> n;

  vector<ll> x(n);
  rep(i, n) cin >> x.at(i);

  if(n == 1){
    cout << 0 << endl;
    return;
  }

  if(n == 2){
    cout << (x.back() - x.front())/2 << endl;
    return;
  }

/*
  vector<ll> cum_x(n+1, 0);
  rep(i, n){
    cum_x.at(i+1) = cum_x.at(i) + x.at(i);
  }

  vector<ll> rev_cum_x(n+1, 0);
  for(int i = n-1; i >= 0; i--){
    rev_cum_x.at(i) = rev_cum_x.at(i+1) + x.at(i);
  }

  debug(cum_x);
  debug(rev_cum_x);

  rep(i, n){
    ll l_sm = cum_x.at(i+1);
    ll r_sm = cum_x.at(i);
  }
*/


  rep(i, n){
    ll cand1 = x.at(i) - x.front();
    ll cand2 = x.back() - x.at(i);

    if(i == 3){
      // debug(cand1);
      // debug(cand2);
      // debug(cand1/2);
      // debug(cand2/2);
    }

    ll len;
    if(cand1 == 0){
      len = cand2;
    }else if(cand2 == 0){
      len = cand1;
    }else{
      if(cand1 == cand2){
        ll cand3 = x.at(i) - x.at(i-1);
        ll cand4 = x.at(i+1) - x.at(i);
        // debug(cand3);
        // debug(cand4);

        if(cand3 < cand4){
          // len = ((x.at(i)-cand3/2) - (x.front()+cand3/2)) + cand3;

          ll cand2_1 = (x.back()-cand3/2 - (x.at(i) + cand3/2));
          ll cand2_2 = ((x.at(i) - cand3/2) - (x.front()+cand3/2));

          // debug(cand2_1);
          // debug(cand2_2);
          ll len2 = max(cand2_1, cand2_2);
          cout << len2 + cand3/2 << endl;
          continue;

        }else{
          ll cand2_1 = (x.back()-cand4/2 - (x.at(i) + cand4/2));
          ll cand2_2 = ((x.at(i) - cand4/2) - (x.front()+cand4/2));

          // debug(cand2_1);
          // debug(cand2_2);
          ll len2 = max(cand2_1, cand2_2);
          cout << len2 + cand4/2 << endl;
          continue;
        }

      }else{
        len = max(cand1, cand2);
      }
    }

    cout << len/2 << endl;

  }


}

int main() {
  solve();
  return 0;
}
