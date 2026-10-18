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
  ll n;
  cin >> n;

  vector<ll> a(n);
  map<ll, vector<ll>> mp;
  rep(i, n){
    cin >> a.at(i);
    mp[a.at(i)].push_back(i);
  }

  // for(auto p : mp){
  //   debug(p.first);
  //   debug(p.second);
  // }

  ll ans = 1;
  for(int i = n-1; i >= 0; i--){
    ll target = a.at(i)-1;
    ll idx = i;
    ll len = 1;
    // debug(i);
    // debug(target);
    while(true){
      if(mp.count(target)){
        vector<ll> v = mp[target];
        // debug(v);
        // debug(idx);
        auto it = lower_bound(v.begin(), v.end(), idx);
        if(it != v.end()){
          if(*it > i){
            // cout << "1" << endl;
            // debug(*it);
            break;
          }else{
            // cout << "2" << endl;
            idx = *it;
            target--;
            len++;
          }
          // debug(*it);
        }else{
          it--;
          if(*it > i){
            // cout << "6" << endl;
            // debug(*it);
            break;
          }else{
            // cout << "5" << endl;
            idx = *it;
            target--;
            len++;
          }
        // debug(len);

            // cout << "3" << endl;
          // break;
        }
      }else{
        // cout << "4" << endl;
        break;
      }
    }
    ans = max(ans, len);
  }

  cout << ans << endl;


}


int main() {

  solve();

  return 0;
}
