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
  map<ll, ll> mp;
  ll sm = 0;
  set<ll> st;
  rep(i, n){
    cin >> a.at(i);
    mp[a.at(i)]++;
    sm += a.at(i);
    st.insert(a.at(i));
  } 

  vector<ll> v{st.begin(), st.end()};

  vector<ll> ans;
  for(int k = n/2; k <= n; k++){
    if(sm % k != 0) continue;

    // 元の長さ（L）
    ll l = sm/k;

    // debug(l);

    bool is_valid = true;
    for(int i = 0; i <= v.size()/2; i++){
      ll rem = l - v.at(i);
      // debug(i);
      // debug(rem);
      // debug(mp[v.at(i)]);
      // debug(mp[rem]);
      if(mp[v.at(i)] != mp[rem]){
        is_valid = false;
        break;
      }
    }

    if(is_valid) ans.push_back(l);
  }

  sort(ans.begin(), ans.end());
  out_vec(ans);


}

int main() {

  solve();

  return 0;  
}
