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

const int MAX_A = 1e5;

void solve(){
  int n, m;
  cin >> n >> m;

  // kの候補
  vector<bool> k(MAX_A+1, true);
  rep(i, n){
    int a;
    cin >> a;
    // gcd(a_i, a_i)は1にはならない
    k.at(a) = false;
  }

  // sieve of Eratosthenes
  vector<bool> is_primes(MAX_A+1, true);
  vector<int> primes;
  for(int i = 2; i <= MAX_A; i++){
    // 素数でなければ飛ばす
    if(!is_primes.at(i)) continue;

    // iの倍数
    for(int j = 2*i; j <= MAX_A; j+=i){
      is_primes.at(j) = false;

      // 素数iがa_iの素因数のときfalseになる
      k.at(i) = k.at(i) && k.at(j);
    }

    // 条件を満たさない素数
    if(!k.at(i)) primes.push_back(i);
  }

  // 条件を満たさない素数の倍数は条件を満たさない
  for(int p : primes){
    for(int j = 2*p; j <= m; j+=p){
      k.at(j) = k.at(j) && k.at(p);
    }
  }

  vector<int> ans{1};
  for(int i = 2; i <= m; i++){
    if(k.at(i)) ans.push_back(i);
  }

  cout << ans.size() << endl;
  rep(i, ans.size()){
    cout << ans.at(i) << endl;
  }

}


int main() {

  solve();

  return 0;
}
