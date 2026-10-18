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
int ctoi(char c){return int(c-'0');} // e.g.) a -> 49, 1 -> 1
char itoc(int x){return x+'0';}

const ll INFL = 1LL<<60;

void solve(){
  ll n, k; cin >> n >> k;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  out_yn(true);

/*
  ll l_idx = 0;
  ll r_idx = n-1;
  rep(i, n-1){
    if(a.at(i) <= a.at(i+1)){
      l_idx = i+1;
    }else{
      break;
    }
  }

  for(int i = n-1; i >= 1; i--){
    if(a.at(i-1) <= a.at(i)){
      r_idx = i-1;
    }else{
      break;
    }
  }

  if(l_idx+k < r_idx){
    out_yn(false);
    return;
  }

  ll mi2 = INFL;
  ll ma2 = 0;
  rep(i, k){
    mi2 = min(mi2, a.at(i));
    ma2 = max(ma2, a.at(i));
  }


  rep(i, n-k){


  }
*/




/*
  bool is_asc1 = true;
  vector<ll> x1;
  x1.push_back(a.at(0));

  multiset<ll> x2;
  for(int i = 1; i < k+1; i++){
    x2.insert(a.at(i));
  }

  vector<ll> x3;
  for(int i = k+1; i < n; i++){
    x3.push_back(a.at(i));    
  }
  reverse(x3.begin(), x3.end());

  bool is_asc3 = true;
  for(int i = 0; i < (int)x3.size()-1; i++){
    if(x3.at(i) < x3.at(i+1)){
      is_asc3 = false;
    }
  }

  {
    ll mi1 = x1.front();
    ll ma1 = x1.back();
    ll mi2 = *x2.begin();
    ll ma2 = *x2.rbegin();
    ll mi3 = x3.size() > 0 ? x3.back() : INFL;
    ll ma3 = x3.size() > 0 ? x3.front() : INFL;

    if(ma1 <= mi2 && ma2 <= mi3 && (is_asc1 && is_asc3)){
      out_yn(true);
      return;
    }

  }

  for(int i = 1; i < n-k; i++){
    debug(i);
    x1.push_back(a.at(i));
    ll x3b = *x3.rbegin();
    x3.pop_back();

    x2.insert(a.at(i+k));
    x2.erase(a.at(i));

    // if(x1.at(i-1) > x1.at(i)) is_asc1 = false;
    if(x1.at(x1.size()-2) > x1.at(x1.size()-1)) is_asc1 = false;
    // if(x3b > x3.back()) is_asc3 = false;
    // if((int)x3.size() <= 1) is_asc3 = true;

    ll mi1 = x1.front();
    ll ma1 = x1.back();
    ll mi2 = *x2.begin();
    ll ma2 = *x2.rbegin();
    ll mi3 = x3.size() > 0 ? x3.back() : INFL;
    ll ma3 = x3.size() > 0 ? x3.front() : INFL;

    if(mi3 == 30 && ma3 == 30){
      debug(x3);
    }

    debug(mi1);
    debug(ma1);
    debug(mi2);
    debug(ma2);
    debug(mi3);
    debug(ma3);
    debug(is_asc1);
    debug(is_asc3);

    if(ma1 <= mi2 && ma2 <= mi3 && (is_asc1 && is_asc3)){
      out_yn(true);
      return;
    }
  }

  out_yn(false);
*/






/*
  // ll mi1 = a.at(0);
  // ll ma1 = a.at(0);

  multiset<ll> x1, x2, x3;

  x1.insert(a.at(0));

  // ll mi2 = INFL;
  // ll ma2 = 0;
  for(int i = 1; i < k+1; i++){
    // mi2 = min(mi2, a.at(i));
    // ma2 = max(ma2, a.at(i));
    x2.insert(a.at(i));
  }

  bool is_asc1 = true;
  bool is_asc3 = true;
  // ll mi3 = INFL;
  // ll ma3 = 0;
  for(int i = k+1; i < n; i++){
    // mi3 = min(mi3, a.at(i));
    // ma3 = max(ma3, a.at(i));

    x3.insert(a.at(i));

    if(i < n-1 && a.at(i) > a.at(i+1)){
      is_asc3 = false;
    }
  }

  {
    ll mi1 = *x1.begin();
    ll ma1 = *x1.rbegin();
    ll mi2 = *x2.begin();
    ll ma2 = *x2.rbegin();
    ll mi3 = *x3.begin();
    ll ma3 = *x3.rbegin();

    if(ma1 <= mi2 && ma2 <= mi3){
      out_yn(true);
      return;
    }
  }





  // for(auto p1 : x1){
  //   debug(p1);
  // }
  // for(auto p2 : x2){
  //   debug(p2);
  // }
  // for(auto p3 : x3){
  //   debug(p3);
  // }

  // if(ma1 <= mi2 && ma2 <= mi3){
  //   out_yn(true);
  //   return;
  // }

  for(int i = 2; i < n-k; i++){
    if(a.at(i-1) > a.at(i)){
      is_asc1 = false;
      break;
    }
    if(i+k < n-1 && a.at(i+k) > a.at(i+k+1)){
      is_asc3 = false;
      break;
    }
    x1.insert(a.at(i));
    x2.erase(a.at(i));
    x2.insert(a.at(i+k));
    x3.erase(a.at(i+k));


    ll mi1 = *x1.begin();
    ll ma1 = *x1.rbegin();
    ll mi2 = *x2.begin();
    ll ma2 = *x2.rbegin();
    ll mi3 = *x3.begin();
    ll ma3 = *x3.rbegin();

    debug(mi1);
    debug(ma1);
    debug(mi2);
    debug(ma2);
    debug(mi3);
    debug(ma3);

    if(ma1 <= mi2 && ma2 <= mi3){
      out_yn(true);
      return;
    }
  }

  out_yn(false);
*/

}

int main() {

  solve();

  return 0;
}
