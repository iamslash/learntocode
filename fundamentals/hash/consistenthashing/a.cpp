// Copyright (C) 2016 by iamslash

#include <map>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int32_t JumpConsistentHash(uint64_t key, int32_t num_buckets) {
	uint64_t b =-1, j = 0;
	while (j < num_buckets) {
		b = j;
		key = key * 2862933555777941757ULL + 1;
		j = (b + 1) * (double(1LL << 31) / double((key >> 33) + 1));
	}
	return b;
}
int main(int argc, char **argv) {
	// map<int, int> map1;
	// map<int, int>::iterator mi;
	// int32_t v;
	// for (uint64_t i = 0; i < 100000; i++) {
	// 	v = JumpConsistentHash(i, 8);
	// 	mi = map1.find(v);
	// 	if (mi == map1.end()) {
	// 		map1[v] = 1;
	// 	} else {
	// 		mi->second++;
	// 	}
	// }
	// for (mi=map1.begin(); mi !=map1.end(); ++mi) {
	// 	cout << mi->first << " : " << mi->second << endl;
	// }

  for (int key = 0; key < 5; ++key) {
    vector<int> v;
    for (int node = 1; node <= 100; ++node)
      v.push_back(JumpConsistentHash(key, node));
    for (int i = 0; i < v.size(); ++i)
      cout << setw(4) << v[i] << " ";
    cout << endl << endl;
  }
}
