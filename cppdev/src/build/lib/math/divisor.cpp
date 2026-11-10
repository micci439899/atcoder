#include <bits/stdc++.h>
using namespace std;

// あまり競技プログラミング的な観点ではないが
// 割り切れるか判定するプログラム
// 2 ~ 13まで

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

  for(int i = 0; i < (int)v.size(); i++) {
    if(i) cout << " ";
    cout << v.at(i);
  }
  cout << endl;

  cout << "divide by 2" << endl;
  confirm_my_dividable(v, 2);

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

int main() {
  confirm_my_dividable_all();
  return 0;
}