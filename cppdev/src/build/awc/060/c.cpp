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

vector<bool> is_prime(1e5+1, true);
void init(){
  for(ll i = 2; i <= is_prime.size(); i++){
    if(!is_prime.at(i)) continue;
    for(ll j = 2*i; j <= is_prime.size(); j+=i){
      is_prime.at(j) = false;
    }
  }
}

vector<pair<ll, ll>> factorize(ll x){
  vector<pair<ll, ll>> res;
  for(ll i = 2LL; i*i<= x; i++){
    ll cnt = 0;
    while(x%i == 0){
      cnt++;
      x /= i;
    }
    if(cnt > 0){
      res.emplace_back(i, cnt);
    }
  }
  if(x > 1){
    res.emplace_back(x, 1);
  }
  return res;
}

ll gcd(ll a, ll b){
  return b == 0 ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b){
  // attention: overflow
  return a / gcd(a, b) * b;
}

void solve(){
  ll n; cin >> n;

  // vector<vector<pll>> ps;
  // vector<vector<pll>> qs;
  // rep(i, n){
  //   ll p, q; cin >> p >> q;
  //   vector<pll> p_p = factorize(p);
  //   vector<pll> q_p = factorize(q);
  //   ps.push_back(p_p);
  //   qs.push_back(q_p);
  // }
  vector<ll> p(n);
  vector<ll> q(n);
  rep(i, n) cin >> p.at(i) >> q.at(i);

  ll lcm_num = 1;
  rep(i, n){
    lcm_num = lcm(lcm_num, q.at(i));
  }

  vector<ll> p2(n);
  ll max_p2 = 0;
  rep(i, n){
    p2.at(i) = p.at(i) * (lcm_num/q.at(i));
    max_p2 = max(max_p2, p2.at(i));
  }

  // ll gcd_num = max_p2;
  // rep(i, n){
  //   gcd_num = gcd(gcd_num, p2.at(i));
  // }
  ll lcm_num2 = 1;
  rep(i, n){
    lcm_num2 = lcm(lcm_num2, p2.at(i));
  }

  ll gcd_num2 = gcd(lcm_num, lcm_num2);

  cout << lcm_num2/gcd_num2 << " " << lcm_num/gcd_num2 << endl;


}

int main() {

  solve();

  return 0;  
}
