# include <bits/stdc++.h>
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
template<class T, class U>ostream&operator<<(ostream&os, map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}
int ctoi(char c){return int(c-'0');}
char itoc(int x){return x+'0';}

void solve(){
  ll n, l, r; cin >> n >> l >> r;
  // l--; r--;

  string s;
  cin >> s;


  vector<vector<ll>> cum_alpha(26, vector<ll>(n+1, 0));


  vector<ll> cum_a(n+1, 0);
  rep(i, n){
    int alpha = s.at(i) - 'a';

    rep(j, 26){
      if(j == alpha){
        cum_alpha.at(j).at(i+1) = cum_alpha.at(j).at(i) + 1;
      }else{
        cum_alpha.at(j).at(i+1) = cum_alpha.at(j).at(i);
      }
    }
  }

  // cout << "cum alpha" << endl;
  // out_vec2d(cum_alpha);

  ll ans = 0;
  rep(alpha, 26){
    rep(i, n){
      if(s.at(i) - 'a' != alpha) continue;
      int l2 = min(l+i, n);
      int r2 = min(r+i+1, n);
      // ll diff = cum_alpha.at(alpha).at(r2) - cum_alpha.at(alpha).at(l2);
      // ans += (diff - cum_alpha.at(alpha).at(i));
      ans += cum_alpha.at(alpha).at(r2) - cum_alpha.at(alpha).at(l2);
    }
  }
  cout << ans << endl;













  /*
  vector<vector<int>> alpha_idx(26);

  rep(i, n){
    int alpha = s.at(i) - 'a';
    alpha_idx.at(alpha).push_back(i);
  }

  debug(alpha_idx);

  ll ans = 0;
  rep(alpha, 26){
    rep(i, alpha_idx.at(alpha).size()-1){

    }
  }
  */

  /*
  ll ans = 0;
  rep(alpha, 26){
    rep(i, alpha_idx.at(alpha).size()-1){
      // int l2 = min(l+i, n);
      // int r2 = min(r+i+1, n);
      auto it = lower_bound(alpha_idx.at(alpha).begin(), alpha_idx.at(alpha).end(), l+i);
      if(it == alpha_idx.at(alpha).end()) continue;
      // if(*it >= r+i) continue;

      // auto it2 = lower_bound(alpha_idx.at(alpha).begin(), alpha_idx.at(alpha).end(), r+i);
      auto it2 = lower_bound(alpha_idx.at(alpha).begin(), alpha_idx.at(alpha).end(), r+i+1);
      // if(it2 == alpha_idx.at(alpha).end()) it2--;
      ll num = (it2 - alpha_idx.at(alpha).begin()) - (it - alpha_idx.at(alpha).begin()) + 1;
      // if(*it > r+i+1) continue;
      // if(*it2 > r+i+1) continue;
      debug(l+i);
      debug(r+i);
      debug(*it);
      debug(*it2);
      debug(num);
      ans += num;
    }
  }
  cout << ans << endl;
  */

  /*
  map<char, vector<ll>> mp;
  vector<vector<ll>> cum_alpha(26, vector<ll>(n+1, 0));


  vector<ll> cum_a(n+1, 0);
  rep(i, n){
    int alpha = s.at(i) - 'a';

    rep(j, 26){
      if(j == alpha){
        cum_alpha.at(j).at(i+1) = cum_alpha.at(j).at(i) + 1;
      }else{
        cum_alpha.at(j).at(i+1) = cum_alpha.at(j).at(i);
      }
    }
  }

  cout << "cum alpha" << endl;
  out_vec2d(cum_alpha);

  ll ans = 0;
  // rep(alpha, 26){
  //   rep(i, n){
  //     if(s.at(i) - 'a' != alpha) continue;
  //     int l2 = min(l+i, n);
  //     int r2 = min(r+i+1, n);
  //     // ll diff = cum_alpha.at(alpha).at(r2) - cum_alpha.at(alpha).at(l2);
  //     // ans += (diff - cum_alpha.at(alpha).at(i));
  //     ans += cum_alpha.at(alpha).at(r2) - cum_alpha.at(alpha).at(l2);
  //   }
  // }
  // cout << ans << endl;


  rep(i, n-1){
    int alpha = s.at(i) - 'a';
    int l2 = min(l+i, n);
    int r2 = min(r+i+1, n);
    ans += cum_alpha.at(alpha).at(r2) - cum_alpha.at(alpha).at(l2);
  }
  cout << ans << endl;
  */

}

int main() {

  solve();

  return 0;  
}
