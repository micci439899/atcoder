# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void print_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void print_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}

struct Iab {
  ll idx;
  ll a;
  ll b;
};


//bool cmp(pair<ll, ll>p1, pair<ll, ll> p2){
//bool cmp(tuple<ll, ll, ll>p1, tuple<ll, ll, ll> p2){
bool cmp(Iab iab1, Iab iab2){
  ll pmin1 = min(iab1.a, iab1.b);
  ll pmin2 = min(iab2.a, iab2.b);

  return pmin1 < pmin2;


  //ll pmin1 = min(get<1>p1, get<2>p1);
  //ll pmin2 = min(get<1>p2, get<2>p2);

  //return pmin1 < pmin2;
  //ll pmin1 = min(p1.first, p1.second);
  //ll pmin2 = min(p2.first, p2.second);

  //return pmin1 < pmin2;
}

int main() {
  ll n;
  cin >> n;

  set<ll> s;
  //vector<tuple<ll, ll, ll>> ab(n);
  vector<Iab> ab(n);
  rep_ll(i, n){
    ll a, b;
    cin >> a >> b;
    //tuple<ll, ll, ll> p = make_tuple(i, a, b);
    Iab p = {i, a, b};
    ab.at(i) = p;
    if(a == 0LL && b == 0LL){
      s.insert(i+1);
    }
  }

  sort(ab.begin(), ab.end(), cmp);

  // rep(i, n){
  //   cout << ab.at(i).idx << " " << ab.at(i).a << " " << ab.at(i).b << endl;
  // }

  rep_ll(i, n){
    ll idx = ab.at(i).idx;
    ll a = ab.at(i).a;
    ll b = ab.at(i).b;
    if(a == 0LL && b == 0LL){
      continue;
    }
    if(s.count(a) || s.count(b)){
      s.insert(idx+1);
    }
  }

  cout << s.size() << endl;

  return 0;
  
}
