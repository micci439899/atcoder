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

const int MOD = 998244353;

const int M = 1e6 + 2;

void solve(){
  ll n, k; cin >> n >> k;

  vector<bool> is_prime(M, true);
  is_prime.at(0) = false;
  is_prime.at(1) = false;
  for(ll p = 2; p < is_prime.size(); p++){
    if(is_prime.at(p)){
      for(ll i = p*2; i < is_prime.size(); i+=p) is_prime.at(i) = false;
    }
  }

  // 0 ~ k
  vector<ll> deno(k+1);
  rep(i, k+1)deno.at(i) = i;

  // n - k + 1 ~ n
  vector<ll> nume(k);
  ll offset = n - k + 1;
  rep(i, k)nume.at(i) = offset + i;

  // debug(deno);
  // debug(nume);

  // vector<ll> deno_f(M, 0);
  // vector<ll> nume_f(M, 0);

  ll ans = 1;
  rep(p, is_prime.size())if(is_prime.at(p)){
    // debug(p);
    int power = 0;

    for(ll i = p; i <= k; i+=p){
      while(deno.at(i)%p == 0){
        power--;
        deno.at(i) /= p;
      }
    }

    // p * (k-1) < N-K+1 <= p * kを満たすk
    // k >= floor((N-K+1)/p))
    // このkが0番目
    ll idx_offset = offset%p == 0 ? offset / p : offset / p + 1;
    ll s_idx = idx_offset * p - offset;
    // debug(idx_offset);
    // debug(s_idx);
    for(ll i = s_idx; i < k; i+=p){
      // debug(i);
      while(nume.at(i)%p == 0){
        power++;
        nume.at(i) /= p;
      }
    }

    ans = ans * (power+1) % MOD;
  }

  // debug(deno);
  // debug(nume);

  for(ll i = offset; i <= n; i++)if(nume.at(i-offset) != 1){
    ans = ans * (1+1) % MOD;
  }
  cout << ans << endl;
}

int main() {

  solve();

  return 0;
}
