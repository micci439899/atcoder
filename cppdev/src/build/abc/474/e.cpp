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

void testcase(){
  ll n; cin >> n;

  ll mi_a = 1LL<<60;
  vector<pll> ab(n);
  rep(i, n){
    cin >> ab.at(i).first >> ab.at(i).second;
    mi_a = min(mi_a, ab.at(i).first);
  }
  sort(ab.begin(), ab.end(), [](pll x, pll y){
    ll diff1 = x.first - x.second;
    ll diff2 = y.first - y.second;
    return diff1 == diff2 ? x.first - y.first : diff1 < diff2;
  });

  // ll c_num = 0;

  ll ans = 0;
  rep(i, n){
    bool is_coupon = n%2 == 0 && i >= n/2 || n%2 != 0 && i > n/2;
    if(is_coupon){
      ans += ab.at(i).second;
      continue;
    }

    ll diff = ab.at(i).first - ab.at(i).second;

    if(mi_a + ab.at(i).second < ab.at(i).first){
      ans += mi_a;
      ans += ab.at(i).second;
    }else{
      ans += ab.at(i).first;
      // c_num++;
    }
  }
  cout << ans << endl;

  // debug(mi_a);
  // debug(ab);
}

void solve(){
  ll t; cin >> t;
  while(t--){
    testcase();
  }
}

int main() {

  solve();

  return 0;
}