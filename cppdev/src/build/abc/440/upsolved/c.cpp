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
  int t;
  cin >> t;

  while(t--){
    ll n, w;
    cin >> n >> w;

    vector<ll> c(n);
    rep(i, n) cin >> c.at(i);


    // n = 8, w = 2
    // c = 1 10 10 1 1 10 10 1

    // x = 1
    // i+x: 2 ~ 9
    // (1 + 1) % 4 = 2 x
    // (2 + 1) % 4 = 3 x
    // (3 + 1) % 4 = 0 o
    // (4 + 1) % 4 = 1 o
    // (5 + 1) % 4 = 2 x
    // (6 + 1) % 4 = 3 x
    // (7 + 1) % 4 = 0 o
    // (8 + 1) % 4 = 1 o
    // 10 + 1 + 10 + 1
    // = 22

    // x = 2
    // i+x: 3 ~ 10
    // (1 + 2) % 4 = 3 x
    // (2 + 2) % 4 = 0 o
    // (3 + 2) % 4 = 1 o
    // (4 + 2) % 4 = 2 x
    // (5 + 2) % 4 = 3 x
    // (6 + 2) % 4 = 0 o
    // (7 + 2) % 4 = 1 o
    // (8 + 2) % 4 = 2 x
    // 10 + 10 + 10 + 10
    // = 40
    // ...



    vector<ll> rem_cost(2*w, 0);

    for(int i = 1; i <= n; i++){
      ll rem = i % (2*w);
      rem_cost.at(rem) += c.at(i-1);
    }

    ll ans = 0;
    for(int i = 0; i < w; i++){
      ans += rem_cost.at(i);
    }

    ll cur = ans;
    for(int x = 1; x < 2*w; x++){
      ll l_idx = x-1;
      ll r_idx = (x + w - 1) % (2*w);
      cur -= rem_cost.at(l_idx);
      cur += rem_cost.at(r_idx);

      chmin(ans, cur);
    }


    cout << ans << endl;


  }




}

int main() {

  solve();

  return 0;  
}
