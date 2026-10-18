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

// f(n, m, a, b) := \sum_{i=0}^{n-1} \lfloor{\frac{ai+b}{m}} \rfloor
// 元ネタは下記
// https://qiita.com/sounansya/items/51b39e0d7bf5cc194081
// C++だと負の数のときの場合分けが必要（本当はAC Libraryを使うのが良い）
// a = q_1 m + r_1, b = q_2 m + r_2とおく
// q_1 = floor(a/m)
// r_1 = a - qm
// q_2 = floor(b/m)
// r_2 = b - qm
// より
// f(n, m, a, b)
// = \sum_0^{n-1} \lfloor ( \frac{(q_1 m + r_1)i + q_2 m + r_2)}{m} \rfloor 
// = \sum_0^{n-1} (q_1 i + q_2) + \lfloor \frac{r_1 i + r_2}{m} /rfloor
// = q_1 \frac{(n-1)n}{2} + q_2 n + f(n, m, r_1, r_2)
long long floor_sum(long long n, long long m, long long a, long long b){
  long long ans = 0;

  if(a < 0){
    long long q = (a - m + 1) / m;
    long long r = a - q * m;

    ans += q * n * (n - 1) / 2;
    a = r;
  }

  if(a >= m){
    long long q = a / m;
    ans += q * n * (n - 1) / 2;
    a %= m;
  }

  if(b < 0){
    // b = qm + rとおく（aと同じ）
    long long q = (b - m + 1) / m;
    long long r = b - q * m;

    ans += q * n;
    b = r;
  }

  if(b >= m){
    long long q = b / m;
    ans += q * n;
    b %= m;
  }

  if(a == 0){
    return ans;
  }

  long long k = (a * (n-1) + b) / m;
  return ans + n * k - floor_sum(k, a, m, m + a - b - 1);
}

void solve(){
  int t; cin >> t;

  while(t--){
    ll n, m, a, b; cin >> n >> m >> a >> b;

    ll sm1 = floor_sum(n, m, a, b);
    ll sm2 = floor_sum(n, m, a-1, b-1);

    ll ans = n - (sm1 - sm2);

    cout << ans << endl;
  }
}

int main() {

  solve();

  return 0;
}
