/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// // 984ms 55.35% 401.2MB 8.86%
// // Trie
// struct TrieNode {
//   vector<int> wordIdxVec;
//   vector<TrieNode*> children;
//   TrieNode() {
//     children = vector<TrieNode*>(26, nullptr);
//   }
//   ~TrieNode() {
//     for (int i = 0; i < 26; ++i) {
//       if (children[i]) {
//         delete children[i];
//       }
//     }
//   }
//   void add(const string& word, size_t beg, int idx) {
//     wordIdxVec.push_back(idx);
//     if (beg < word.size()) {
//       int i = word[beg]-'a';
//       if (!children[i]) {
//         children[i] = new TrieNode();
//       }
//       children[i]->add(word, beg+1, idx);
//     }
//   }
//   vector<int> find(const string& prefix, size_t beg) {
//     if (beg == prefix.size()) {
//       return wordIdxVec;
//     }
//     int i = prefix[beg] - 'a';
//     if (!children[i]) {
//       return {};
//     }
//     return children[i]->find(prefix, beg+1);
//   }
// };

// class WordFilter {
//  private:
//     TrieNode* prefixTrie = new TrieNode();
//     TrieNode* suffixTrie = new TrieNode();  
//  public:
//   WordFilter(vector<string>& W) {
//     for (int i = 0; i < W.size(); ++i) {
//       string word = W[i];
//       prefixTrie->add(word, 0, i);
//       reverse(word.begin(), word.end());
//       suffixTrie->add(word, 0, i);
//     }
//   }
    
//   int f(string prefix, string suffix) {
//     auto prefixVec = prefixTrie->find(prefix, 0);
//     reverse(suffix.begin(), suffix.end());
//     auto suffixVec = suffixTrie->find(suffix, 0);
//     int i = prefixVec.size() - 1;
//     int j = suffixVec.size() - 1;
//     while (i >= 0 && j >= 0) {
//       int pidx = prefixVec[i];
//       int sidx = suffixVec[j];
//       if (pidx == sidx) {
//         return pidx;
//       } else if (pidx < sidx) {
//         j--;
//       } else {
//         i--;
//       }
//     }
//     return -1;
//   }
// };
 
// 472ms 100.00% 91.1MB 94.10%
struct TrieNode {
  TrieNode* children[26] = {NULL};
  vector<int> index;
};

class WordFilter {
 private:
  TrieNode* prefixTrie = new TrieNode();
  TrieNode* suffixTrie = new TrieNode();
    
public:
  WordFilter(vector<string>& words) {
    for (int i = 0; i < words.size(); ++i) {
      TrieNode* cur = prefixTrie;
      for(auto c : words[i]) {
        int idx = c - 'a';
        if (cur->children[idx] == NULL) cur->children[idx] = new TrieNode();
        cur = cur->children[idx];
        cur->index.push_back(i);;
      }
    }
        
    for (int i = 0; i < words.size(); ++i) {
      TrieNode* cur = suffixTrie;
      auto& word = words[i];
      for (int j = word.size()-1; j >= 0; --j) {
        int idx = word[j] - 'a';
        if (cur->children[idx] == NULL) cur->children[idx] = new TrieNode();
        cur = cur->children[idx];
        cur->index.push_back(i);
      }
    }
  }
    
  int f(string pre, string suf) {
    TrieNode* cur_pre = prefixTrie;
    for (auto c : pre) {
      int idx = c - 'a';
      cur_pre = cur_pre->children[idx];
            
      if (cur_pre == NULL) break;
    }
        
    TrieNode* cur_suf = suffixTrie;
    for (int i = suf.size()-1; i >= 0; --i) {
      int idx = suf[i] - 'a';
      cur_suf = cur_suf->children[idx];
            
      if (cur_suf == NULL) break;
    }
        
    if (cur_pre == NULL || cur_suf == NULL)
      return -1;
        
    int i = cur_pre->index.size() - 1;
    int j = cur_suf->index.size() - 1;
    while(i >= 0 && i >= 0) {
      if (cur_pre->index[i] == cur_suf->index[j]) 
        return cur_pre->index[i];
      else if (cur_pre->index[i] > cur_suf->index[j]) 
        --i;
      else
        --j;
    }
        
    return -1;
  }
};
