#include <iostream>
#include <string>
#include <vector>

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
    std::vector<int> next;

    // この文字が終端となる文字列（のword_id）
    std::vector<int> accept;

    Node(int n_) : char_idx(n_), s_num(0) {
      next.assign(char_size, -1);
    }

    // debug用
    void out() {
      std::cout << "{char_idx: " << char_idx << ", s_num:" << s_num << ", next: [";
      for(int i = 0; i < (int)next.size(); i++){
        if(i) std::cout << " ";
        std::cout << next.at(i);
      }
      std::cout << "]";
      std::cout << ", accept: [";
      for(int i = 0; i < (int)accept.size(); i++){
        if(i) std::cout << " ";
        std::cout << accept.at(i);
      }
      std::cout << "]}";
    }
  };

  // Trie木本体
  std::vector<Node> nodes;

  int root;
  Trie() : root(0) {
    nodes.push_back(Node(root));
  }

  // 単語挿入
  // word_idは各単語を識別するための番号付け（0-indexed）
  void insert(const std::string &s, int word_id) {
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
  void insert(const std::string &s) {
    insert(s, nodes.at(0).s_num);
  }

  // 検索
  int search(const std::string &s, bool prefix) {
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
  int search_all(const std::string &s) {
    return search(s, false);
  }
  // sがprefixとなる単語があるか検索
  // あるとき、該当する単語の数を返す
  int search_prefix(const std::string &s) {
    return search(s, true);
  }
  int search_unique_min_prefix(const std::string &s) {
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
    std::cout << "Nodes: [";
    for(int i = 0; i < (int)nodes.size(); i++){
      if(i) std::cout << " ";
      nodes.at(i).out();
      if(i<(int)nodes.size()-1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
  }
};

