# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void out_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void out_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}
void out_yn(bool b){if(b){cout << "Yes" << endl;}else{cout << "No" << endl;}}

int main() {
  int n;
  cin >> n;

  vector<ll> a(n);
  rep(i, n) cin >> a.at(i);

  deque<ll> deq;

  int idx = 0;

  ll cnt = 0;
  while(idx < n){
    int d_sz = deq.size();
    if(d_sz >= 4){
      bool b1 = deq.at(d_sz-1) == deq.at(d_sz-2);
      bool b2 = deq.at(d_sz-1) == deq.at(d_sz-3);
      bool b3 = deq.at(d_sz-1) == deq.at(d_sz-4);
      if(b1 && b2 && b3){
        deq.pop_back();
        deq.pop_back();
        deq.pop_back();
        deq.pop_back();
        cnt++;
      }
    }
    deq.push_back(a.at(idx));

    idx++;
  }

  int d_sz = deq.size();
  if(d_sz >= 4){
    bool b1 = deq.at(d_sz-1) == deq.at(d_sz-2);
    bool b2 = deq.at(d_sz-1) == deq.at(d_sz-3);
    bool b3 = deq.at(d_sz-1) == deq.at(d_sz-4);
    if(b1 && b2 && b3){
      deq.pop_back();
      deq.pop_back();
      deq.pop_back();
      deq.pop_back();
      cnt++;
    }
  }


  cout << n - cnt*4 << endl;






  return 0;  
}
