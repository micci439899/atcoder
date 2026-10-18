# include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep_ll(i, n) for (ll i = 0; i < (ll)(n); i++)

template<class T> void print_vec(vector<T> &v){for(int i=0;i<(int)v.size();i++){cout<<v.at(i)<<" ";}cout<<endl;}
template<class T> void print_vec2d(vector<vector<T>> &v){for(int i=0;i<(int)v.size();i++){for(int j=0;j<(int)v.at(i).size();j++){cout<<v.at(i).at(j)<<" ";}cout<<endl;}}

int find(map<int, int> mp){
  for(auto p : mp){
    if(p.first == -1)continue;
    if(p.second == 0){
      return p.first;
    }
  }
  return -99;
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> p(n, 0);
  vector<int> unused;
  vector<int> used;
  map<int, int> mp;
  rep(i, n){
    int ai;
    cin >> ai;
    if(ai != -1){
      p.at(i) = ai;
      used.push_back(ai);
      mp[ai]++;
    }
  }

  for(int i = 1; i <= n; i++){
    bool exist = false;
    rep(j, used.size()){
      if (i == used.at(j)){
        exist = true;
      }
    }
    if(!exist){
      unused.push_back(i);
    }
  }

  //cout << "used" << endl;
  //print_vec(used);
  //cout << "" << endl;

  //for(auto p : mp){
  //  cout << p.first << ":" << p.second << endl;
  //}

  for(auto p : mp){
    if(p.second > 1){
      //cout << p.first << ":" << p.second << endl;
      cout << "No" << endl;
      return 0;
    }
  }

  int idx = 0;
  rep(i, n){
    if(p.at(i) == 0){
      p.at(i) = unused.at(idx);
      idx++;
    }
  }

  cout << "Yes" << endl;
  print_vec(p);


/*
  vector<int> a(n);
  vector<int> p(n, 0);
  vector<int> used;
  rep(i, n){
    int ai;
    cin >> ai;
    if(ai != -1){
      p.at(i) = ai;
      used.push_back(ai);
    }
  }

  cout << "used:" << endl;
  print_vec(used);
  cout << "" << endl;

  int b = 1;
  rep(i, n){
    if(p.at(i) == 0){
    }
  }

  cout << "used:" << endl;
  print_vec(used);
  cout << "" << endl;
  cout << "" << endl;

  print_vec(p);
*/

/*
  int n;
  cin >> n;



  vector<int> a(n);
  vector<int> p(n, 0);
  map<int, int> mp;
  rep(i, n){
    cin >> a.at(i);
    if(a.at(i) != -1){
      p.at(i) = a.at(i);
      mp[a.at(i)]++;
    }else{
      mp[a.at(i)] = 0;
    }
  }

  for(auto p : mp){
    cout << p.first << ":" << p.second << endl;
  }

  rep(i, n){
    if(p.at(i) == 0){
      int a = find(mp);
      p.at(i) = a;
      mp[a]++;
    }
  }

  for(auto p : mp){
    cout << p.first << ":" << p.second << endl;
  }

  for(auto p : mp){
    if(p.second > 1){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  print_vec(p);

*/






  return 0;
}


