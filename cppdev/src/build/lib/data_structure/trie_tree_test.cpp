#include <bits/stdc++.h>
#include "trie_tree.hpp"
using namespace std;

void do_trie(){
  Trie<26, 'A'> trie;
  trie.insert("FIRE");
  trie.insert("WIND");
  trie.insert("WATER");
  cout << trie.search_all("FIRE") << endl;
  cout << trie.search_all("FI") << endl;
  trie.out();

  Trie<3, 'a'> trie2;
  trie2.insert("aaba");
  trie2.insert("abab");
  trie2.insert("aac");
  cout << trie2.search_all("aaba") << endl;
  cout << trie2.search_prefix("a") << endl;
  cout << trie2.count() << endl;
  cout << trie2.size() << endl;
  trie2.out();

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
  trie3.out();

  Trie<10, '0'> trie4;
  trie4.out();
}

int main() {
  do_trie();
  return 0;
}