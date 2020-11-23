/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

// You need to start from these data structures
  // int userseq;
  // unodered_map<int, set<int>> chunk2user;
  // unodered_map<int, vector<int>> user2chunk;
  // set<int> recycleUserSet;

// 720ms 77.61% 136.MB 70.66%
// reverse index, hash map
class FileSharing {
 private:
  int userseq;
  unordered_map<int, set<int>> chunk2user;
  unordered_map<int, vector<int>> user2chunk;
  set<int> recycleUserSet;

 public:
  FileSharing(int m) {
    userseq = 1;
  }
    
  int join(vector<int> ownedChunks) {
    int userid = 0;
    if (recycleUserSet.empty()) {
      userid = userseq++;
    } else {
      userid = *(recycleUserSet.begin());
      recycleUserSet.erase(userid);
    }
    for (int chunkid : ownedChunks) {
      chunk2user[chunkid].insert(userid);
    }
    user2chunk[userid] = ownedChunks;
    return userid;
  }
    
  void leave(int userid) {
    if (userseq == userid) {
      userseq--;
    } else {
      recycleUserSet.insert(userid);
    }
    for (int chunkid : user2chunk[userid]) {
      chunk2user[chunkid].erase(userid);
    }
    user2chunk.erase(userid);
  }
    
  vector<int> request(int userid, int chunkid) {
    vector<int> ans(chunk2user[chunkid].begin(), chunk2user[chunkid].end());
    if (ans.empty())
      return {};
    chunk2user[chunkid].insert(userid);
    user2chunk[userid].push_back(chunkid);
    return ans;
  }
};

// seq: 1
// c2u: {{1:{1}}, {2:{1, 2}}, {3:{2}}}
// u2c: {{1:[1, 2], {2: [2, 3]}}
// 
