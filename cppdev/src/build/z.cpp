#include <bits/stdc++.h>
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
template<class T>ostream&operator<<(ostream&os, const multiset<T>&st){os<<"{";int idx=0;for(auto &e : st){cout << e;if(idx != st.size()-1){cout << ",";}idx++;}os<<"}";return os;}
template<class T, class U>ostream&operator<<(ostream&os, map<T,U>mp){os<<"{";int idx=0;for(auto p : mp){cout << p;if(idx != mp.size()-1){cout << ",";}idx++;}os<<"}";return os;}

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}
int ctoi(char c){return int(c-'0');} // e.g.) a -> 49, 1 -> 1
char itoc(int x){return x+'0';}


const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;

const long double PI = 3.141592653589793;

const ll MD = 1e9 + 7;
const ll mod = 1e9 + 7;

vector<int> dx = {1, 0, -1, 0, 1, -1, -1, 1};
vector<int> dy = {0, 1, 0, -1, 1, 1, -1, -1};

void print_dbl(double d, int p){
  cout << fixed << setprecision(p) << d << endl;
}

void do_vector_operation(){
  vector<int> x1 = { 3, 1, 4, 1, 5 };

  cout << "origin" << endl;
  out_vec(x1);
  cout << endl;

  // O(1)
  cout << "access by index" << endl;
  cout << x1.at(0) << endl;
  cout << endl;

  // O(1)
  // attention
  // error when empty list
  cout << "last" << endl;
  cout << x1.back() << endl;
  cout << endl;

  cout << "push back" << endl;
  x1.push_back(9);
  out_vec(x1);
  cout << endl;

  cout << "max" << endl;
  int ma = *max_element(x1.begin(), x1.end());
  cout << ma << endl;
  cout << endl;

  cout << "min" << endl;
  int mi = *min_element(x1.begin(), x1.end());
  cout << mi << endl;
  cout << endl;

  // end（右端）は含まない
  // 下記の場合3,1,4の中でのmaxとなる
  cout << "max(part)" << endl;
  int ma2 = *max_element(x1.begin(), x1.begin() + 3);
  cout << ma2 << endl;
  cout << endl;

  // O(n)
  // findの返り値はiteratorであることに注意
  cout << "find" << endl;
  auto found = find(x1.begin(), x1.end(), 1);
  if(found != x1.end()){
    size_t pos = distance(x1.begin(), found);
    cout << *found << " (" << pos << ")" << endl;

    cout << "next to found" << endl;
    cout << *(found+1) << endl;
    cout << endl;
  }

  cout << "find(not exist)" << endl;
  auto found2 = find(x1.begin(), x1.end(), -99);
  if(found2 != x1.end()){
    cout << *found2 << endl;
    cout << endl;
  }else{
    cout << "not found" << endl;
    cout << endl;
  }


  vector<int> x2 = x1;
  cout << "copy vector" << endl;
  out_vec(x2);
  cout << endl;

  sort(x2.begin(), x2.end());
  cout << "after sort(origin)" << endl;
  out_vec(x1);
  cout << endl;
  cout << "after sort(copied)" << endl;
  out_vec(x2);
  cout << endl;

  auto it = lower_bound(x2.begin(), x2.end(), 7);
  if(it != x2.end()){
    cout << "lower bound 7" << endl;
    cout << *it << endl;
    cout << endl;
  }


  vector<int> x3 = x1;
  sort(x3.rbegin(), x3.rend());
  cout << "after sort(desc)" << endl;
  out_vec(x3);
  cout << endl;



  vector<int>x4 = x1;
  reverse(x4.begin(), x4.end());
  cout << "after reverse" << endl;
  out_vec(x4);
  cout << endl;

  vector<int> x5 = x1;
  x5.push_back(2);
  sort(x5.begin()+1, x5.end()-1);
  cout << "sort except first and last" << endl;
  out_vec(x5);
  cout << endl;



  // Pythonのrange相当
  vector<int> v1(100);
  iota(v1.begin(), v1.end(), 1);

  cout << "iota 1 ~ 100" << endl;
  out_vec(v1);
  cout << endl;

  // Pythonのrange相当
  vector<int> v2(100);
  iota(v2.begin(), v2.end(), -50);

  cout << "iota -50 ~ 49" << endl;
  out_vec(v2);
  cout << endl;

  //vector<vector<int>> g(11, vector<int>(11));
  vector<vector<int>> g;
  //rep(i, g.size()){
  rep(i, 11){
    vector<int> row(11);
    iota(row.begin(), row.end(), -5);
    g.push_back(row);
  }
  cout << "2d" << endl;
  cout << "iota -5 ~ 5" << endl;
  out_vec2d(g);
  cout << endl;


  vector<vector<int>> v_2d(3, vector<int>(3));
  cout << "2d initialize" << endl;
  out_vec2d(v_2d);
  cout << endl;



}


void do_set_operation(){

}


void do_string_operation(){
  string s = "abcde";

  cout << "origin" << endl;
  cout << s << endl;
  cout << endl;

  cout << "length" << endl;
  cout << s.size() << endl;
  cout << endl;

  string sub_s = s.substr(1, 2);

  cout << "substr 1 ~ 2(0-indexed)" << endl;
  cout << sub_s << endl;
  cout << endl;

  cout << "each character" << endl;
  for(auto c : s) {
    cout << c << endl;
  }
  cout << endl;


  string s2 = "jihgf";
  string s_cat = s + s2;

  cout << "concat" << endl;
  cout << s_cat << endl;
  cout << endl;


  sort(s_cat.begin(), s_cat.end());
  cout << "sorted" << endl;
  cout << s_cat << endl;
  cout << endl;

  string s_rev = s + s2;
  reverse(s_rev.begin(), s_rev.end());
  cout << "reversed" << endl;
  cout << s_rev << endl;
  cout << endl;

}


void do_bit_operation(){
  int bit_num = 3;
  for(int bit = 0; bit < 1<<bit_num; bit++){
    // bitsetは動的に出来ない（bit_numと同じ値）
    bitset<3> bs(bit);
    string s = "";
    for(int i = 0; i < bit_num; i++){
      int z = bit>>i;
      int y = z & 1;
      cout << bit << ">>" << i << ": " << z << endl;
      cout << bit << ">>" << i << " & 1: " << y << endl;
      if(bit>>i & 1){
        s.push_back('o');
      }else{
        s.push_back('x');
      }
    }
    reverse(s.begin(), s.end());
    cout << bit << endl;
    cout << bs << endl;
    cout << s << endl;
    cout << endl;
  }
}

bool cmp(pair<int, int> p1, pair<int ,int> p2){
  assert(p1.second != 0);
  assert(p2.second != 0);

  if(p1.second < 0){
    p1.first *= -1;
    p1.second *= -1;
  }
  if(p2.second < 0){
    p2.first *= -1;
    p2.second *= -1;
  }

  return p1.first * p2.second < p2.first * p1.second;
}


vector<ll> find_divisor(ll n){
  vector<ll> ans;
  for(ll i = 1; i*i <= n; i++){
    if(n%i == 0){
      ans.push_back(i);
      if(i*i != n){
        ll q = n/i;
        ans.push_back(n/i);
      }
    }
  }
  sort(ans.begin(), ans.end());
  return ans;
}

ll gcd(ll a, ll b){
  return b == 0 ? a : gcd(b, a%b);
}

ll lcm(ll a, ll b){
  // attention: overflow
  return a*b/gcd(a, b);
}

// 傾き（slope, gradient）
pll grad(pll p1, pll p2){
  ll dx = p1.first - p2.first;
  ll dy = p1.second - p2.second;

  if(dx == 0){
    dx = 0;
    dy = 1;
  }else if(dy == 0){
    dx = 1;
    dy = 0;
  }else{
    if(dx < 0){
      dx *= -1;
      dy *= -1;
    }
    ll g = gcd(abs(dx), abs(dy));
    dx /= g;
    dy /= g;
  }
  return {dx, dy};
}



int find_digit_sum_diff(string s){
  // 3桁区切りの個数
  // e.g.)
  // 1のとき1
  // 12のとき1
  // 123のとき1
  // 1234のとき2
  // 123456789のとき3
  int cnt = (s.size()-1)/3 + 1;

  // 区切ったうち、1番最上位の桁数
  // e.g.)
  // 1234のとき1
  // 12345のとき2
  // 123456のとき0
  int md = s.size()%3;

  int idx = 1;
  int odd_sum = 0;
  int even_sum = 0;
  while(idx <= cnt){
    bool is_even = idx%2 == 0;
    int current_num = 0;
    if(idx == cnt){
      if(md == 0){
        current_num = stoi(s.substr(0, 3));
      } else if(md == 1){
        current_num = stoi(s.substr(0, 1));
      } else if(md == 2){
        current_num = stoi(s.substr(0, 2));
      } else {
        assert(false);
      }
    } else {
      current_num = stoi(s.substr(s.size()-3 - 3*(idx-1), 3));
    }
    if(is_even){
      even_sum += current_num;
    } else {
      odd_sum += current_num;
    }
    idx++;
  }

  return odd_sum - even_sum;
}

bool is_dividable_by2(string s){
  char c = s.at(s.size()-1);  
  return int(c - '0') % 2 == 0;
}

bool is_dividable_by3(string s){
  int sm = 0;
  for(auto c : s){
    sm += int(c - '0');
  }
  return sm%3 == 0;
}

bool is_dividable_by4(string s){
  if(s.size() < 3){
    return stoi(s)%4 == 0;
  } else {
    return stoi(s.substr(s.size()-2)) % 4 == 0;
  }
}

bool is_dividable_by5(string s){
  char c = s.at(s.size()-1);  
  return c == '0' || c == '5';
}

bool is_dividable_by6(string s){
  return is_dividable_by2(s) && is_dividable_by3(s);
}

bool is_dividable_by7(string s){
  int sum_diff = find_digit_sum_diff(s);
  return sum_diff % 7 == 0;
}

bool is_dividable_by8(string s){
  if(s.size() < 4){
    return stoi(s)%8 == 0;
  } else {
    return stoi(s.substr(s.size()-3)) % 8 == 0;
  }
}

bool is_dividable_by9(string s){
  int sm = 0;
  for(auto c : s){
    sm += int(c - '0');
  }
  return sm%9 == 0;
}

bool is_dividable_by10(string s){
  char c = s.at(s.size()-1);  
  return c == '0';
}

bool is_dividable_by11(string s){
  int sum_diff = find_digit_sum_diff(s);
  return sum_diff % 11 == 0;
}

bool is_dividable_by12(string s){
  return is_dividable_by3(s) && is_dividable_by4(s);
}

bool is_dividable_by13(string s){
  int sum_diff = find_digit_sum_diff(s);
  return sum_diff % 13 == 0;
}

void confirm_my_dividable(vector<string> vs, int n){
  for(int i = 0; i < vs.size(); i++){
    string s = vs.at(i);
    if(n == 2 && is_dividable_by2(s)){
      cout << s << endl;
    } else if(n == 3 && is_dividable_by3(s)){
      cout << s << endl;
    } else if(n == 4 && is_dividable_by4(s)){
      cout << s << endl;
    } else if(n == 5 && is_dividable_by5(s)){
      cout << s << endl;
    } else if(n == 6 && is_dividable_by6(s)){
      cout << s << endl;
    } else if(n == 7 && is_dividable_by7(s)){
      cout << s << endl;
    } else if(n == 8 && is_dividable_by8(s)){
      cout << s << endl;
    } else if(n == 9 && is_dividable_by9(s)){
      cout << s << endl;
    } else if(n == 10 && is_dividable_by10(s)){
      cout << s << endl;
    } else if(n == 11 && is_dividable_by11(s)){
      cout << s << endl;
    } else if(n == 12 && is_dividable_by12(s)){
      cout << s << endl;
    } else if(n == 13 && is_dividable_by13(s)){
      cout << s << endl;
    }
  }
  cout << endl;
  cout << endl;

}

void confirm_my_dividable_all(){
  // int n;
  // cin >> n;
  // vector<int> v(100);
  // iota(v.begin(), v.end(), n);
  random_device seed_gen;
  mt19937 engine(seed_gen());

  vector<string> v(100);
  for(int i = 0; i < 100; i++){
    string s = "";
    for(int j = 0; j < 3; j++){
      uint32_t num = engine();
      s += to_string(num);
    }
    v.at(i) = s;
  }

  out_vec(v);

  cout << "divide by 2" << endl;
  confirm_my_dividable(v, 2);
/*
  for(int i = 0; i < v.size(); i++){
    string s = to_string(v.at(i));
    if(is_dividable_by2(s)){
      cout << s << " ";
    }
  }
  cout << endl;
  cout << endl;
*/

  cout << "divide by 3" << endl;
  confirm_my_dividable(v, 3);

  cout << "divide by 4" << endl;
  confirm_my_dividable(v, 4);

  cout << "divide by 5" << endl;
  confirm_my_dividable(v, 5);

  cout << "divide by 6" << endl;
  confirm_my_dividable(v, 6);

  cout << "divide by 7" << endl;
  confirm_my_dividable(v, 7);

  cout << "divide by 8" << endl;
  confirm_my_dividable(v, 8);

  cout << "divide by 9" << endl;
  confirm_my_dividable(v, 9);

  cout << "divide by 10" << endl;
  confirm_my_dividable(v, 10);

  cout << "divide by 11" << endl;
  confirm_my_dividable(v, 11);

  cout << "divide by 12" << endl;
  confirm_my_dividable(v, 12);

  cout << "divide by 13" << endl;
  confirm_my_dividable(v, 13);

}


// attention
// n < 10
ll base_n_to_10(string s, int base){
  reverse(s.begin(), s.end());

  ll res = 0;
  ll n = 1;
  for(auto c : s){
    res += (ll)(c - '0') * n;
    n *= (ll)base;
  }
  return res;
}

// attention
// n < 10
string base_10_to_n(ll value, int base){
  if(value == 0){
    return "0";
  }

  string s = "";
  while(value > 0){
    ll r = value % (ll)base;
    value /= (ll)base;
    s += to_string(r);
  }

  reverse(s.begin(), s.end());
  return s;
}

ll mypow(int x, int y){
  ll res = 1;
  rep(i, y){
    res *= x;
  }
  return res;
}


ll powmod(ll x, ll y){
  if(y == 0LL) return 1LL;

  if(y%2LL == 0LL){
    ll z = powmod(x, y/2LL)%mod;
    return (z * z)%mod;
  }else{
    ll z = powmod(x, y/2LL)%mod;
    return (((x*z)%mod)*z)%mod;
  }
}



// graph
bool is_within(int x, int y, int w, int h){
  if(x < 0 || w-1 < x) return false;
  if(y < 0 || h-1 < y) return false;
  return true;
}


bool is_prime(ll x){
  if(x == 1LL) return false;
  for(ll i = 2LL; i*i <= x; i++){
    if(x%i == 0LL) return false;
  }
  return true;
}

void do_prime_operation(){
  for(int i = 1; i < 100; i++){
    if(is_prime(i)){
      cout << i << " ";
    }
  }
  cout << endl;
}

// vector<pair<ll, ll>> factorize(ll x){
//   vector<pair<ll, ll>> res;
//   //if(is_prime(x)){
//   //  res.emplace_back(x, 1);
//   //  return res;
//   //}

//   vector<ll> primes;
//   //for(int i = 2LL; i*i <= x; i++){
//   for(int i = 2LL; i <= x; i++){
//     if(is_prime(i)) primes.push_back(i);
//   }

//   rep(i, primes.size()){
//     ll p = primes.at(i);
//     ll cnt = 0;
//     while(x%p==0){
//       cnt++;
//       x = x/p;
//     }

//     if(cnt > 0){
//       res.emplace_back(p, cnt);
//     }
//   }
//   return res;
// }


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

void do_factorize(){
  for(ll i = 2; i <= 10000; i++){
    vector<pair<ll, ll>> a = factorize(i);

    cout << i << " = ";
    rep(i, a.size()){
      auto [f, s] = a.at(i);
      cout << f << "^" << s;
      if(i < a.size()-1){
         cout << " * ";
      }
    }
    cout << endl;
  }
}

// 素集合データ構造（Union-Find）
struct DisjointSetUnion {
  vector<int> parents;
  vector<int> sizes;

  // 初期化子リスト
  DisjointSetUnion(int n) : parents(n, -1), sizes(n, 1) {}

  // xが属しているグループの代表（根）を取得
  int find(int x) {
    if(parents.at(x) == -1) return x;

    // 経路圧縮
    parents.at(x) = find(parents.at(x));
    return parents.at(x);
  }

  // xとyが同じグループに属しているかどうか
  bool is_same(int x, int y) {
    return find(x) == find(y);
  }

  // xが属しているグループとyが属しているグループを併合する
  // xとyが既に同じグループに属しているときfalse、そうでないときtrueを返す
  bool unite(int x, int y) {
    int x_r = find(x);
    int y_r = find(y);

    if(x_r == y_r) return false;

    // union by size（木の深さをなるべく小さくする）
    if(sizes.at(x_r) < sizes.at(y_r)) swap(x_r, y_r);

    parents.at(y_r) = x_r;
    sizes.at(x_r) += sizes.at(y_r);
    return true;
  }

  // xが属しているグループの要素数を返す
  int size(int x) {
    return sizes.at(find(x));
  }
};

void do_union_find(){

  DisjointSetUnion dsu(7);

  auto out_group = [&](){
    cout << "group" << endl;
    rep(i, dsu.parents.size()){
      cout << dsu.find(i) << " ";
    }
    cout << endl << endl;
    return;
  };

  cout << "initialize" << endl;
  out_group();

  dsu.unite(1, 2);
  cout << "1 and 2 are united" << endl;
  out_group();

  dsu.unite(2, 3);
  cout << "2 and 3 are united" << endl;
  out_group();

  dsu.unite(5, 6);
  cout << "5 and 6 are united" << endl;
  out_group();

  cout << "1 and 3 are same group?" << endl;
  out_yn(dsu.is_same(1, 3));
  cout << "2 and 5 are same group?" << endl;
  out_yn(dsu.is_same(2, 5));

}


void my_time(){
  int n = 10000;

  //vector<int> v(n);
  set<int> st;

  rep(i, n){
    //v.at(i) = i;
    st.insert(i);
  }

  time_t start1 = time(nullptr);
  cout << ctime(&start1) << endl;

  rep(i, n){
    auto x = find(st.begin(), st.end(), i);
  }
  time_t end1 = time(nullptr);
  cout << ctime(&end1) << endl;


  time_t start2 = time(nullptr);
  cout << ctime(&start2) << endl;

  rep(i, n){
    auto x = st.find(i);
  }
  time_t end2 = time(nullptr);
  cout << ctime(&end2) << endl;
}


template <typename T>
struct SegmentTree {
  // 1-indexedのSegment Tree
  // ただし、外からは0-indexedとみなすことができる

  // 演算、単位元
  function<T(T,T)> op;
  T e;

  // 元のデータサイズ
  int n;

  // SegmentTreeで管理するデータ
  vector<T> x;

  // SegmentTreeで確保したデータから実データにアクセスするためのoffset
  int offset;

  SegmentTree(int N, function<T(T,T)> op, T e) : op(op), e(e) {
    initialize(N);
  }
  SegmentTree(const vector<T> &v, const function<T(T,T)> op, T e) : op(op), e(e) {
    initialize((int)v.size());
    build(v);
  }

  void initialize(int N) {
    n = N;
    offset = 1;
    while(offset < N) offset *= 2;
    x.assign(2*offset, e);
  }

  void build(const vector<T> &v) {
    for(int i = 0; i < (int)v.size(); i++) x.at(i + offset) = v.at(i);
    for(int i = offset-1; i > 0; i--) x.at(i) = op(x.at(i*2), x.at(i*2+1));
  }

  // 1点更新(O(log N))
  // i: 0-indexed
  void set(int i, T val) {
    // 実データは[offset, 2*offset)
    i += offset;
    x.at(i) = val;

    // 親をたどる
    while(i > 1) {
      i /= 2;
      x.at(i) = op(x.at(2*i), x.at(2*i+1));
    }
  }

  // 指定区間に対する演算結果を取得(O(log N))
  // [l, r)
  T prod(int l, int r) {
    // 実データは[offset, 2*offset)
    l += offset;
    r += offset;
    T l_val = e;
    T r_val = e;

    while(l < r) {
      // lが親から見て右の子のときlの値を計算
      if(l % 2 == 1) {
        l_val = op(l_val, x.at(l));
        l++;
      }

      // r-1が親から見て左の子のときr-1の値を計算
      if(r % 2 == 1) {
        r--;
        r_val = op(x.at(r), r_val);
      }
      // 親（1段上）に
      l /= 2;
      r /= 2;
    }
    return op(l_val, r_val);
  }

  // 
  int max_right(const function<bool(T)> f, int l = 0) {
    if(l == n) return n;
    l += offset;
    T sm = e;
    do {
      while(l%2 == 0) l >>= 1;
      if(!f(op(sm, x.at(l)))) {
        while(l < offset) {
          l = l * 2;
          if(f(op(sm, x.at(l)))) {
            sm = op(sm, x.at(l));
            l++;
          }
        }
        return l - offset;
      }
      sm = op(sm, x.at(l));
      l++;
    } while((l & -l) != l);
    return n;
  }

  int min_left(const function<bool(T)> f, int r = -1) {
    if(r == 0) return 0;
    if(r == -1) r = n;
    r += offset;
    T sm = e;
    do {
      r--;
      while(r > 1 && (r%2)) r >>= 1;
      if(!f(op(x.at(r), sm))){
        while(r < offset) {
          r = r * 2 + 1;
          if(f(op(x.at(r), sm))) {
            sm = op(x.at(r), sm);
            r--;
          }
        }
        return r + 1 - offset;
      }
      sm = op(x.at(r), sm);
    } while((r & -r) != r);
    return 0;
  }

  // debug用
  void out() {
    // 改行する要素番号（0-indexed）
    int br_num = 1;
    for(int i = 0; i < (int)x.size(); i++) {
      if(i == 0) continue;
      cout << x.at(i) << " ";
      if(br_num == i){
        cout << endl;
        // 2^(n-1) - 1から2^n - 1
        br_num = (br_num+1)*2-1;
      }
    }
  }
};


void do_segment_tree(){
  auto f = [](int a, int b) -> int {return min(a, b);};
  int e = INT_MAX/2;
  SegmentTree<int> seg = SegmentTree<int>(10, f, e);

  vector<int> v = {1, 4, 3, 9, 4, 6, 2, 2, 3};

  //                1
  //        1               3
  //    1       2       3       e
  //  1   3   4   2   3   e   e   e
  // 1 4 3 9 4 6 2 2 3 e e e e e e e

  rep(i, v.size()){
    seg.set(i, v.at(i));
  }


  int mi_1 = seg.prod(1, 3);  
  int mi_2 = seg.prod(0, 9);
  int mi_3 = seg.prod(5, 8);
  int mi_4 = seg.prod(5, 5);


  cout << mi_1 << endl;
  cout << mi_2 << endl;
  cout << mi_3 << endl;
  cout << mi_4 << endl;


  cout << "seg out" << endl;
  seg.out();
}

/*
// n=1のときの考慮がない
// 返り値がない
void do_rle(string s){
  int n = s.size();
  vector<pair<char, ll>> rle;
  char c = s.at(0);
  ll cnt = 1;
  for(int i = 1; i < n; i++){
    if(s.at(i) != c){
      rle.emplace_back(c, cnt);
      cnt = 1;
      c = s.at(i);
    }else{
      cnt++;

    }
    if(i == n-1) rle.emplace_back(c, cnt);
  }
}
*/

template<typename T>
vector<pair<T, long long>> rle(vector<T> v){
  int n = v.size();
  vector<pair<T, long long>> res;
  if(n == 1){
    res.emplace_back(v.at(0), n);
    return res;
  }
  T t = v.at(0);
  long long cnt = 1;
  for(int i = 1; i < n; i++){
    if(v.at(i) != t){
      res.emplace_back(t, cnt);
      cnt = 1;
      t = v.at(i);
    }else{
      cnt++;
    }
    if(i == n-1) res.emplace_back(t, cnt);
  }
  return res;
}

void do_rle(){
  vector<int> v1 = {1, 2, 2, 3, 3, 3};
  vector<pair<int, ll>> r1 = rle(v1);
  debug(r1);

  vector<int> v2 = {1};
  vector<pair<int, ll>> r2 = rle(v2);
  debug(r2);

  vector<char> v3 = {'a', 'b', 'b', 'a', 'c', 'c', 'c'};
  vector<pair<char, ll>> r3 = rle(v3);
  debug(r3);

  string s = "xxyxyxyxxxyyyyyz";
  vector<char> v4;
  for(auto c : s) v4.push_back(c);
  vector<pair<char, ll>> r4 = rle(v4);
  debug(r4);

  // vector<pair<char, ll>> r5 = rle(s);
  // debug(r5);
}

// 有限体F_p上の演算
// https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
template<int MOD> struct Fp {
  long long val;

  constexpr Fp(long long v = 0) noexcept : val(v % MOD){
    if(val < 0) val += MOD;
  }

  constexpr Fp operator - () const noexcept {
    return val ? MOD - val : 0;
  }

  constexpr Fp operator + (const Fp &r) const noexcept { return Fp(*this) += r; }
  constexpr Fp operator - (const Fp &r) const noexcept { return Fp(*this) -= r; }
  constexpr Fp operator * (const Fp &r) const noexcept { return Fp(*this) *= r; }
  constexpr Fp operator / (const Fp &r) const noexcept { return Fp(*this) /= r; }

  constexpr Fp& operator += (const Fp& r) noexcept {
    val += r.val;
    if(val >= MOD) val -= MOD;
    return *this;
  }
  constexpr Fp& operator -= (const Fp& r) noexcept {
    val -= r.val;
    if(val < 0) val += MOD;
    return *this;
  }
  constexpr Fp& operator *= (const Fp& r) noexcept {
    val = val * r.val % MOD;
    return *this;
  }
  constexpr Fp& operator /= (const Fp& r) noexcept {
    long long a = r.val;
    long long b = MOD;
    long long u = 1, v = 0;
    while(b){
      long long t = a / b;
      a -= t * b; swap(a, b);
      u -= t * v; swap(u, v);
    }

    val = val * u % MOD;
    if(val < 0) val += MOD;
    return *this;
  }

  constexpr Fp& operator == (const Fp& r) noexcept {
    return this->val == r.val;
  }
  constexpr Fp& operator != (const Fp& r) noexcept {
    return this->val != r.val;
  }
  friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
    return os << x.val;
  }
  friend constexpr Fp<MOD> modpow (const Fp<MOD> &a, long long n) noexcept {
    if (n == 0) return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1) t = t * a;
    return t;
  }
};

const int MOD = 998244353;

void do_fp_calc(){
  vector<Fp<MOD>> v1 = {1, 2, 3 ,4};
  vector<Fp<MOD>> v2 = {5, 6, 7 ,8};

  rep(i, v1.size()){
    rep(j, v2.size()){
      cout << v1.at(i) << " + " << v2.at(j) << " = " << v1.at(i)+v2.at(j) << endl;
      cout << v1.at(i) << " - " << v2.at(j) << " = " << v1.at(i)-v2.at(j) << endl;
      cout << v1.at(i) << " * " << v2.at(j) << " = " << v1.at(i)*v2.at(j) << endl;
      cout << v1.at(i) << " / " << v2.at(j) << " = " << v1.at(i)/v2.at(j) << endl;
    }
  }

  cout << endl;

  rep(i, 10){
    Fp<20> a = i;

    rep(j, 10){
      cout << i << "^" << j << " = " << modpow(a, j) << endl;
    }
  }


  rep(i, 10){
    Fp<MOD> ii = -i;
    cout << ii << endl;
  }

  rep(i, v1.size()){
    for(int j = 1; j < 11; j++){
      Fp<MOD> base = 10;
      auto a_i = - v1.at(i) * modpow(base, j);
      cout << "- "<< v1.at(i) << " * 10 ^" << j << " = " << a_i << endl;
    }
  }
}


// a, bが負のとき考慮できてない
/*
// https://qiita.com/sounansya/items/51b39e0d7bf5cc194081
// f(n, m, a, b) := \sum_{i=0}^{n-1} \floor{\frac{ai+b}{m}}
// 0 le n lt 2^32
// 1 le m lt 2^32
ll floor_sum(ll n, ll m, ll a, ll b){
  ll a1 = a / m;
  ll a2 = a % m;
  ll s = n * (n-1) / 2 * a1;
  ll b1 = b / m;
  ll b2 = b % m;
  if(a2 == 0) return s + b1 * n;

  ll k = (a2 * (n-1) + b2) / m;
  return s + n * (k + b1) - floor_sum(k, a2, m, m + a2 - b2 - 1);
}

void do_floor_sum(){
  rep(n, 5)rep(m, 5)if(m > 0)rep(a, 5)rep(b, 5){
    cout << "n:" << n << " m:" << m << " a:" << a << " b:" << b << " floor sum: " << floor_sum(n, m, a, b) << endl;
  }
}
*/

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


// Z algorithm
// https://snuke.hatenablog.com/entry/2014/12/03/214243
// 文字列sが与えられたとき、s全体とs[i:s.size()-1]（sのi番目から末尾まで）の最長共通接頭辞の長さを返す
// O(s.size())
// e.g.)
// aaabaaaab
// 921034210
vector<ll> z_algorithm(string &s){
  vector<ll> res(s.size(), 0);
  res.at(0) = s.size();
  int i = 1, j = 0;

  while(i < s.size()){
    // sの先頭からとi番目からを比較
    while(i+j < s.size() && s.at(j) == s.at(i+j)) j++;
    res.at(i) = j;

    // 先頭が異なる文字
    if(j == 0){ i++; continue; }

    // 計算済みの箇所（読み切れてない...）
    int k = 1;
    while(i+k < s.size() && k + res.at(k) < j) { res.at(i+k) = res.at(k); k++; }
    i += k; j-= k;
  }

  return res;
}


// FenwickTree(Binary Indexed Tree)
// 下記参考
// https://qiita.com/DaikiSuyama/items/7295f5160a51684554a7
// https://algo-logic.info/binary-indexed-tree/
template<typename T>
struct FenwickTree {
  int n;
  vector<T> bit;

  FenwickTree(int n_) : n(n_+1), bit(n_+1, 0){}

  // 1点更新
  // 0-indexed
  void add(int i, T x){
    // 内部的には1-indexed
    i++;
    for(int idx = i; idx < n; idx += (idx & -idx)){
      bit.at(idx) += x;
    }
  }

  // a_0 + ... + a_i
  // 0-indexed
  T sum(int i){
    // 内部的には1-indexed
    i++;
    T sm(0);
    for(int idx = i; idx > 0; idx -= (idx & -idx)){
      sm += bit.at(idx);
    }
    return sm;
  }
};

void do_fenwick(){
  ll n, q; cin >> n >> q;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  FenwickTree<ll> tree(n);
  rep(i, n){
    tree.add(i, a.at(i));
  }

  while(q--){
    int type; cin >> type;
    if(type == 0){
      ll p, x; cin >> p >> x;
      tree.add(p, x);
    }else{
      ll l, r; cin >> l >> r;
      ll sm_l = tree.sum(l-1);
      ll sm_r = tree.sum(r-1);
      cout << sm_r - sm_l << endl;
    }
  }
}



// 2026/10/03
// Tの範囲に収まらないときがあるので注意する
// 自前ライブラリ
// 分数のまま計算することが可能
// 負の値のとき分子が負になる
// 計算する度に既約分数の形になる
template<class T> struct Fraction {
  // 分子
  T nume;
  // 分母
  T deno;

  constexpr Fraction(T n, T d) noexcept : nume(n), deno(d){
    assert(deno != 0);
    if(deno < 0){
      nume *= -1;
      deno *= -1;
    }
    T g = _in_gcd(nume, deno);
    nume /= g;
    deno /= g;
  }

  constexpr Fraction operator - () const noexcept {
    return nume *= -1;
  }

  constexpr Fraction operator + (const Fraction &r) const noexcept { return Fraction(*this) += r; }
  constexpr Fraction operator - (const Fraction &r) const noexcept { return Fraction(*this) -= r; }
  constexpr Fraction operator * (const Fraction &r) const noexcept { return Fraction(*this) *= r; }
  constexpr Fraction operator / (const Fraction &r) const noexcept { return Fraction(*this) /= r; }

  constexpr Fraction& operator += (const Fraction& r) noexcept {
    // b/a + d/c
    // = (bc + ad) / ac
    T n_nume = nume * r.deno + deno * r.nume;
    T n_deno = deno * r.deno;
    nume = n_nume;
    deno = n_deno;
    T g = _in_gcd(nume, deno);
    nume /= g;
    deno /= g;
    return *this;
  }
  constexpr Fraction& operator -= (const Fraction& r) noexcept {
    // b/a - d/c
    // = (bc - ad) / ac
    T n_nume = nume * r.deno - deno * r.nume;
    T n_deno = deno * r.deno;
    nume = n_nume;
    deno = n_deno;
    T g = _in_gcd(nume, deno);
    nume /= g;
    deno /= g;
    return *this;
  }
  constexpr Fraction& operator *= (const Fraction& r) noexcept {
    // b/a * d/c
    // = bd / ac
    T n_nume = nume * r.nume;
    T n_deno = deno * r.deno;
    nume = n_nume;
    deno = n_deno;
    T g = _in_gcd(nume, deno);
    nume /= g;
    deno /= g;
    return *this;
  }
  constexpr Fraction& operator /= (const Fraction& r) noexcept {
    // b/a / d/c
    // = bc / ad
    // 0 divided exception
    assert(r.nume != 0);
    T n_nume = nume * r.deno;
    T n_deno = deno * r.nume;
    nume = n_nume;
    deno = n_deno;
    T g = _in_gcd(nume, deno);
    nume /= g;
    deno /= g;
    return *this;
  }

  constexpr Fraction& operator == (const Fraction& r) noexcept {
    return this->nume == r.nume && this->deno == r.deno;
  }
  constexpr Fraction& operator != (const Fraction& r) noexcept {
    return this->nume != r.nume || this->deno != r.deno;
  }
  friend constexpr ostream& operator << (ostream &os, const Fraction& x) noexcept {
    return os << x.nume << "/" << x.deno;
  }

  public:
  // sort用
  static bool frac_cmp(Fraction<T> f1, Fraction<T>f2){
    // b/a < d/c
    // = bc < ad
    return f1.nume * f2.deno < f1.deno * f2.nume;
  }

  private:
  // greatest common divisor
  T _in_gcd(T a, T b){
    return b == 0 ? a : _in_gcd(b, a%b);
  }

};


void do_my_fraction(){
  Fraction<int> frac1(1, 2);
  Fraction<int> frac2(1, 3);

  Fraction<int> frac3 = frac1 + frac2;
  Fraction<int> frac4 = frac1 - frac2;
  Fraction<int> frac5 = frac1 * frac2;
  Fraction<int> frac6 = frac1 / frac2;

  cout << frac1 << endl;
  cout << frac2 << endl;
  cout << frac3 << endl;
  cout << frac4 << endl;
  cout << frac5 << endl;
  cout << frac6 << endl;

  cout << "frac7" << endl;
  Fraction<int> frac7(1, 12);
  frac7 += {7, 12};
  cout << frac7 << endl;
  frac7 -= {5, 12};
  cout << frac7 << endl;
  frac7 *= {5, 7};
  cout << frac7 << endl;
  frac7 /= {1, 9};
  cout << frac7 << endl;

  // error
  // cout << "frac8" << endl;
  // Fraction<int> frac8(1, 0);

  // error
  // cout << "frac9" << endl;
  // Fraction<int> frac9(0, 1);
  // frac9 /= {0, 1};

  cout << "frac10" << endl;
  Fraction<int> frac10(-123, 456);
  frac10 += {0, 1};
  cout << frac10 << endl;

  vector<Fraction<int>> v;
  for(int i = 0; i < 10; i++){
    int nume = i%2 == 0 ? i * (-1) : i;
    int deno = 2 * i + 1;
    v.push_back({nume, deno});
  }
  debug(v);
  sort(v.begin(), v.end(), Fraction<int>::frac_cmp);
  debug(v);

  rep(i, v.size()-1){
    cout << v.at(i+1) - v.at(i) << endl;
  }


}


// Trie木
// 文字種、基準値を与える
template <int char_size, int base>
struct Trie {
  struct Node {
    // baseを基準とした値（0-indexed）
    // e.g.) baseがAのとき、Cは2
    int char_idx;

    // この頂点を通る文字列の数（prefixが一致する数）
    int s_num;

    // 次のNode（のnode_id）
    // 要素数は文字種の数になる
    // 各文字なければ-1となる
    vector<int> next;

    // この文字が終端となる文字列（のword_id）
    vector<int> accept;

    Node(int n_) : char_idx(n_), s_num(0) {
      next.assign(char_size, -1);
    }

    // debug用
    void out() {
      cout << "{ char_idx:" << char_idx << ", s_num:" << s_num << ", next: [";
      for(int i = 0; i < (int)next.size(); i++){
        if(i) cout << " ";
        cout << next.at(i);
      }
      cout << "]";
      cout << ", accept: [";
      for(int i = 0; i < (int)accept.size(); i++){
        if(i) cout << " ";
        cout << accept.at(i);
      }
      cout << "]}";
    }
  };

  // Trie木本体
  vector<Node> nodes;

  int root;
  Trie() : root(0) {
    nodes.push_back(Node(root));
  }

  // 単語挿入
  // word_idは各単語を識別するための番号付け（0-indexed）
  void insert(const string &s, int word_id) {
    // node_idは各Nodeを識別するための番号付け（0-indexed）
    int node_id = 0;
    for(int i = 0; i < (int)s.size(); i++) {
      int c = (int)(s.at(i) - base);

      int &next_id = nodes.at(node_id).next.at(c);

      if(next_id == -1) {
        next_id = nodes.size();
        nodes.push_back(Node(c));
      }
      nodes.at(node_id).s_num++;
      node_id = next_id;
    }
    nodes.at(node_id).s_num++;
    nodes.at(node_id).accept.push_back(word_id);
  }
  void insert(const string &s) {
    insert(s, nodes.at(0).s_num);
  }

  // 検索
  int search(const string &s, bool prefix) {
    int node_id = 0;
    for(int i = 0; i < (int)s.size(); i++) {
      int c = s.at(i) - base;
      int &next_id = nodes.at(node_id).next.at(c);
      if(next_id == -1) {
        return 0;
      }
      node_id = next_id;
    }
    return prefix ? nodes.at(node_id).s_num : nodes.at(node_id).accept.size();
  }

  // 単語そのものを検索
  // あるとき、挿入した個数を返す
  int search_all(const string &s) {
    return search(s, false);
  }
  // sがprefixとなる単語があるか検索
  // あるとき、該当する単語の数を返す
  int search_prefix(const string &s) {
    return search(s, true);
  }
  int search_unique_min_prefix(const string &s) {
    int node_id = 0;
    for(int i = 0; i < (int)s.size(); i++) {
      int c = s.at(i) - base;
      int &next_id = nodes.at(node_id).next.at(c);
      if(next_id == -1) { return -1; }
      if(nodes.at(next_id).s_num == 1) { return i; };
      node_id = next_id;
    }
    return nodes.at(node_id).s_num > 1 ? -1 : s.size();
  }
  int count() {
    return nodes.at(0).s_num;
  }
  int size() {
    return nodes.size();
  }
  // debug用
  void out(){
    cout << "Nodes: [";
    for(int i = 0; i < (int)nodes.size(); i++){
      if(i) cout << " ";
      nodes.at(i).out();
      if(i<(int)nodes.size()-1) cout << ", ";
    }
    cout << "]" << endl;
  }
};


void do_trie(){
  Trie<26, 'A'> trie;

  trie.insert("FIRE");
  cout << trie.search_all("FIRE") << endl;
  cout << trie.search_all("FI") << endl;
  // trie.out();

  Trie<3, 'a'> trie2;
  trie2.insert("aaba");
  trie2.insert("abab");
  trie2.insert("aac");
  cout << trie2.search_all("aaba") << endl;
  cout << trie2.search_prefix("a") << endl;
  cout << trie2.count() << endl;
  cout << trie2.size() << endl;
  // trie2.out();


  Trie<2, 'a'> trie3;
  trie3.insert("a");
  trie3.insert("a");
  trie3.insert("a");
  trie3.insert("aa");
  trie3.insert("aaa");
  cout << trie3.search_prefix("a") << endl;
  cout << trie3.search_all("a") << endl;
  cout << trie3.search_prefix("b") << endl;
  cout << trie3.search_unique_min_prefix("a") << endl;
  cout << trie3.search_unique_min_prefix("aaa") << endl;
  cout << trie3.search_unique_min_prefix("b") << endl;
  // trie3.out();
}



ll cross_product(const pair<long long, long long> &a, const pair<long long, long long> &b){
  return a.first * b.second - a.second * b.first;
}
ll cross_product(const pair<long long, long long> &o, const pair<long long, long long> &a, const pair<long long, long long> &b){
  return (o.first - a.first) * (o.second - b.second) - (o.second - a.second) * (o.first - b.first);
}


// 凸包アルゴリズム
// monotone chain
// 下記参考
// https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain
vector<pair<long long, long long>> convex_hull(vector<pair<long long, long long>> p){
  int n = p.size();

  vector<pair<long long, long long>> res(2*n);

  sort(p.begin(), p.end());

  // lower hull
  int k = 0;
  for(int i = 0; i < n; i++){
    while(
      k >= 2
      && cross_product(res.at(k-2), res.at(k-1), p.at(i)) <= 0
    ){
      res.pop_back();
      k--;
    }
    res.at(k) = p.at(i);
    k++;
  }

  // upper hull
  int t = k + 1;
  for(int i = n-2; i >= 0; i--){
    while(
      k >= t
      && cross_product(res.at(k-2), res.at(k-1), p.at(i)) <= 0
    ){
      res.pop_back();
      k--;
    }
    res.at(k) = p.at(i);
    k++;
  }

  res.pop_back();
  k--;
  res.resize(k);
  return res;
}

// 区間をsetで管理するテク
template<typename T>
struct IntervalSet {
  set<pair<T, T>> intervals;

  void add(T l, T r) {
    auto it = intervals.lower_bound({l, -1});

    if(it != intervals.begin()) {
      auto prev = it;
      prev--;

      // prevが[l, r)と重なっているならprevから調べ始める
      if(l <= prev->second) {
        it = prev;
      }
    }

    while(it != intervals.end()) {
      T left = it->first;
      T right = it->second;

      // [left, right)が[l, r)と重ならない
      // つまり、右側に完全に離れている
      if(r < left) {
        break;
      }

      // 
      if(right < l) {
        it++;
        continue;
      }

      l = min(l, left);
      r = max(r, right);

      it = intervals.erase(it);
    }

    intervals.insert({l, r});
  }

  void out() {
    int i = 0;
    for(auto p : intervals) {
      if(i) cout << ",";
      cout << "[" << p.first << "," << p.second << ")";
      // cout << "[" << p >> ")";
      i++;
    }
    cout << endl;
  }

  T count(){
    T val = 0;
    for(auto p : intervals) {
      val += p.second - p.first;
    }
    return val;
  }

  set<pair<T, T>> getIntervals(){
    return intervals;
  }
};

void do_intervalsets(){
  IntervalSet<int> iSt;
  iSt.add(1, 3);
  iSt.add(4, 7);

  iSt.out();
  cout << iSt.count() << endl;

  iSt.add(2, 5);

  iSt.out();
  cout << iSt.count() << endl;

  set<pair<int, int>> intervals = iSt.getIntervals();
  cout << intervals << endl;
}

// unordered_mapのkeyにpairを使うときに必要
//https://qiita.com/tqk/items/7c4df1eeb5ebaedcf714
struct PairHash {
  inline size_t operator()(const pair<long long, long long> &p) const{
    const auto h1 = hash<long long>()(p.first);
    const auto h2 = hash<long long>()(p.second);
    return h1 ^ (h2 << 1);
  }
};

vector<Fp<MOD>> fac;
vector<Fp<MOD>> ifac;

void fact_initialize(int n){
  fac.resize(n+1);
  ifac.resize(n+1);
  fac.at(0) = 1;
  ifac.at(0) = 1;

  for(int i = 1; i <=n ;i++){
    fac.at(i) = fac.at(i-1) * i;
    ifac.at(i) = ifac.at(i-1) / i;
  }
}

Fp<MOD> comb(ll n, ll k){
  if(n < k) return 0;
  return fac.at(n) * ifac.at(n-k) * ifac.at(k);
}

// 下記を参考
// https://drken1215.hatenablog.com/entry/2023/05/06/133900
struct StronglyConnectedComponent {

  vector<vector<int>> g, rg;

  vector<vector<int>> scc;
  vector<int> cmp;
  vector<vector<int>> dag;

  StronglyConnectedComponent(int n) : g(n), rg(n) {}

  void add_edge(int u, int v) {
    g.at(u).push_back(v);
    rg.at(v).push_back(u);
  }

  vector<bool> visited;
  vector<int> vs, rvs;
  void dfs(int v) {
    visited.at(v) = true;
    for(int u : g.at(v)) {
      if(!visited.at(u)) dfs(u);
    }
    vs.push_back(v);
  }
  void rdfs(int v, int k) {
    visited.at(v) = true;
    cmp.at(v) = k;
    for(int u : rg.at(v)) {
      if(!visited.at(u)) rdfs(u, k);
    }
    rvs.push_back(v);
  }

  set<pair<int, int>> new_edges;
  void reconstruct() {
    int n = (int)g.size();
    int dv = (int)scc.size();
    dag.assign(dv, vector<int>());
    new_edges.clear();
    for(int i = 0; i < n; i++) {
      int u = cmp.at(i);
      for(int e : g.at(i)) {
        int v = cmp.at(e);
        if(u == v) continue;
        if(!new_edges.count({u, v})) {
          dag.at(u).push_back(v);
          new_edges.insert({u, v});
        }
      }
    }
  }


  void solve() {
    int n = (int)g.size();
    visited.assign(n, false);
    vs.clear();
    for(int v = 0; v < n; v++) if(!visited.at(v)) dfs(v);

    int k = 0;
    cmp.assign(n, -1);
    visited.assign(n, false);
    for(int i = n-1; i >= 0; i--) {
      if(!visited.at(vs.at(i))) {
        rvs.clear();
        rdfs(vs.at(i), k++);
        scc.push_back(rvs);
      }
    }
    reconstruct();
  }

};

template<class T, class F> struct LazySegmentTree {
  // 1-indexedのLazy Segment Tree
  // ただし、外からは0-indexedとみなすことができる
  
  // 演算、単位元
  function<T(T,T)> op;
  T e;

  // 作用素、恒等写像
  function<T(F,T)> mapping;
  F id;

  // 作用素の合成
  function<F(F,F)> composition;

  // 元のデータサイズ
  int n;

  // SegmentTreeで管理するデータ
  vector<T> x;

  vector<F> lazy;

  // SegmentTreeで確保したデータから実データにアクセスするためのoffset
  int offset;

  // SegmentTreeの高さ
  int height;

  LazySegmentTree(int N, const function<T(T,T)> op, const function<T(F,T)> mapping, const function<F(F,F)> composition, const T e, const F id) : op(op), mapping(mapping), composition(composition), e(e), id(id) {
    initialize(N);
  }
  LazySegmentTree(const vector<T> &v, const function<T(T,T)> op, const function<T(F,T)> mapping, const function<F(F,F)> composition, const T e, const F id) : op(op), mapping(mapping), composition(composition), e(e), id(id) {
    initialize((int)v.size());
    build(v);
  }

  void initialize(int N) {
    n = N;
    offset = 1;
    height = 0;
    while(offset < N) offset *= 2, height++;
    x.assign(2*offset, e);
    lazy.assign(2*offset, id);
  }

  void build(const vector<T> &v) {
    for(int i = 0; i < (int)v.size(); i++) x.at(i + offset) = v.at(i);
    for(int i = offset-1; i > 0; i--) pull(i);
  }

  void pull(int i) {
    x.at(i) = op(x.at(i*2), x.at(i*2+1));
  }

  // i番目のデータを正しい値に直し、遅延分を溜める
  void apply(int i, const F &f) {
    x.at(i) = mapping(f, x.at(i));
    if(i < offset) lazy.at(i) = composition(f, lazy.at(i));
  }

  // 遅延させていた分を子に渡す
  void push(int i) {
    apply(i*2, lazy.at(i));
    apply(i*2+1, lazy.at(i));
    lazy.at(i) = id;
  }

  // 子のデータを自身に反映
  void deep_pull(int i){
    for(int h = 1; h <= height; h++) pull(i>>h);
  }

  void deep_push(int i) {
    for(int h = height; h >= 1; h--) push(i>>h);
  }

  void set(int i, const T &val) {
    int k = i + offset;
    deep_push(k);
    x.at(k) = val;
    deep_pull(k);
  }

  T get(int i) {
    int k = i + offset;
    deep_push(k);
    return x.at(k);
  }

  void apply(int l, int r, const F &f) {
    if(l == r) return;
    l += offset, r += offset;

    for(int h = height; h >= 1; h--) {
      int l_k = l>>h;
      int r_k = r>>h;
      if((l_k << h) != l) push(l_k);
      if((r_k << h) != r) push((r-1)>>h);
    }

    int original_l = l, original_r = r;
    for(; l < r; l>>=1, r>>=1) {
      if(l & 1) {
        apply(l, f);
        l++;
      }
      if(r & 1) {
        r--;
        apply(r, f);
      }
    }

    l = original_l, r = original_r;
    for(int h = 1; h <= height; h++) {
      int l_k = l>>h;
      int r_k = r>>h;
      if((l_k << h) != l) pull(l_k);
      if((r_k << h) != r) pull((r-1)>>h);
    }
  }

  T prod(int l, int r) {
    if(l == r) return e;
    l += offset, r += offset;

    for(int h = height; h >= 1; h--) {
      int l_k = l>>h;
      int r_k = r>>h;
      if((l_k << h) != l) push(l_k);
      if((r_k << h) != r) push(r_k);
    }

    T l_val = e, r_val = e;
    for(; l < r; l>>=1, r>>=1) {
      if(l & 1) {
        l_val = op(l_val, x.at(l));
        l++;
      }
      if(r & 1) {
        r--;
        r_val = op(x.at(r), r_val);
      }
    }
    return op(l_val, r_val);
  }

  int max_right(const function<bool(T)> func, int l = 0) {
    if(l == n) return n;
    l += offset;
    deep_push(l);
    T sm = e;
    do {
      while(l%2 == 0) l >>= 1;
      if(!func(op(sm, x.at(l)))) {
        while(l < offset) {
          deep_push(l);
          l = l * 2;
          if(func(op(sm, x.at(l)))) {
            sm = op(sm, x.at(l));
            l++;
          }
        }
        return l - offset;
      }
      sm = op(sm, x.at(l));
      l++;
    } while((l & -l) != l);

    return n;
  }

  int min_left(const function<bool(T)> func, int r = -1) {
    if(r == 0) return 0;
    if(r == -1) r = n;
    r += offset;
    deep_push(r-1);
    T sm = e;
    do {
      r--;
      while(r > 1 && (r%2)) r >>= 1;
      if(!func(op(x.at(r), sm))) {
        while(r < offset) {
          deep_push(r);
          r = r * 2 + 1;
          if(func(op(x.at(r), sm))) {
            sm = op(x.at(r), sm);
            r--;
          }
        }
        return r + 1 - offset;
      }
      sm = op(x.at(r), sm);
    } while((r & -r) != r);

    return 0;
  }

  void out() {
    // 改行する要素番号（0-indexed）
    int br_num = 1;
    for(int i = 0; i < (int)x.size(); i++) {
      if(i == 0) continue;
      cout << x.at(i) << ", (" << lazy.at(i) << ") ";
      if(br_num == i){
        cout << endl;
        // 2^(n-1) - 1から2^n - 1
        br_num = (br_num+1)*2-1;
      }
    }
  }
};



void awc_0171_d(){
  int h, w; cin >> h >> w;

  vector<vector<int>> a(h, vector<int>(w));
  rep(i, h)rep(j, w) cin >> a.at(i).at(j);

  vector<vector<ll>> dist(2, vector<ll>(h*w, INFL));
  dist.at(0).at(0) = 0;
  dist.at(1).at(0) = 0;

  queue<tuple<ll, bool, ll>> que;
  que.push({0, true, 0});
  que.push({0, false, 0});

  auto to_1d = [&](int i, int j){
    return i*w + j;
  };
  auto to_2d = [&](int x) -> pii {
    int i = x/w;
    int j = x%w;
    return {i, j};
  };
  auto is_within = [&](int i, int j){
    if(i < 0 || h-1 < i) return false;
    if(j < 0 || w-1 < j) return false;
    return true;
  };

  while(!que.empty()){
    auto [idx, is_h, d] = que.front(); que.pop();

    rep(k, 4){
      if(is_h && k%2==0) continue;
      if(!is_h && k%2!=0) continue;
      auto [i, j] = to_2d(idx);
      int ni = i + dy.at(k);
      int nj = j + dx.at(k);
      ll n_idx = to_1d(ni, nj);

      if(!is_within(ni, nj)) continue;
      if(a.at(ni).at(nj)) continue;
      if(chmin(dist.at(is_h).at(n_idx), d+1)){
        que.push({n_idx, !is_h, d+1});
      }
    }
  }

  ll ans = min(dist.at(0).at(h*w-1), dist.at(1).at(h*w-1));
  if(ans == INFL){
    cout<< "NONE" << endl;
  }else{
    cout << ans << endl;
  }
}


int main() {

  // do_vector_operation();
  // do_string_operation();
  // do_bit_operation();
  // do_prime_operation();
  // do_factorize();
  // do_segment_tree();
  // do_fp_calc();
  // do_floor_sum();
  // do_my_fraction();
  // do_rle();
  // do_trie();
  do_intervalsets();




  return 0;
}
