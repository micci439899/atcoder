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

// \sqrt( n^2 + n + X) = m
// \iff n^2 + n + X = m^2
// \iff (n+1/2)^2 - 1/4 + X = m^2
// \iff (2n+1)^2 - 1 + 4X = 4m^2
// \iff (2n+1)^2 - (2m)^2 = -4X + 1
// \iff (2n + 1 + 2m)(2n + 1 - 2m) = -4X + 1
// \iff (2n + 2m + 1)(2n - 2m + 1) = -4X + 1
// -4X+1 = d_k_1 * d_k_2のとき
// (2n+2m-1, 2n-2m+1) = (\pm d_k_1, \pm d_k_2), (\pm d_k_2, \pm d_k_1)
// の4通り
void solve(){
  ll x;
  cin >> x;

  ll c = - 4 * x + 1;

  //ll d = -1;

  vector<ll> ans;

  // (2n+2m+1)+(2n-2m+1) = d + (-4x+1)/d
  // 4n + 2 = d + (-4X+1)/d
  // n = (d + (-4X+1)/d - 2) / 4
  // 2n+2m+1 = (-4X+1)/dのときも同じ式
  auto f = [&](ll d){
    return (d + c/d - 2) / 4;
  };

  for(ll d = 1; d*d <= abs(c); d+=2){
    // 2n + 2m + 1は奇数
    //d += 2;

    if(c%d != 0) continue;

    // (2n+2m+1, 2n-2m+1) = (d, (-4X+1)/d)
    ans.push_back(f(d));

    // (2n+2m+1, 2n-2m+1) = (-d, -(-4X+1)/d)
    ans.push_back(f(-d));

    // (2n+2m+1, 2n-2m+1) = ((-4X+1)/d, d)
    //ans.push_back(f(c/d));

    // (2n+2m+1, 2n-2m+1) = (-(-4X+1)/d, -d)
    //ans.push_back(f(-c/d));
  }

  set st(ans.begin(), ans.end());
  vector<ll> v(st.begin(), st.end());
  sort(v.begin(), v.end());

  cout<< v.size() << endl;
  out_vec(v);
}

int main() {

  solve();

  return 0;  
}
