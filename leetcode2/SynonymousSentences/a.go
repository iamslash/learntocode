/* Copyright (C) 2020 by iamslash */

package main

import (
	"fmt"
	"sort"
	"strings"
)

// 0ms 100.00% 2.2MB 100.00%
// BFS
// O(T^N) O(T)
func generateSentences(S [][]string, text string) []string {
	G := make(map[string][]string)
	for _, pair := range S {
		G[pair[0]] = append(G[pair[0]], pair[1])
		G[pair[1]] = append(G[pair[1]], pair[0])
	}
	ansSet := make(map[string]bool)
	bfsq := []string{text}
	for len(bfsq) > 0 {
		uText := bfsq[0]
		bfsq = bfsq[1:]
		ansSet[uText] = true
		words := strings.Split(uText, " ")
		for i, word := range words {
			if _, ok := G[word]; ok == false {
				continue
			}
			for _, u := range G[word] {
				words[i] = u
				vText := strings.Join(words, " ")
				if _, ok := ansSet[vText]; ok {
					continue
				}
				ansSet[vText] = true
				bfsq = append(bfsq, vText)
			}
		}
	}
	ans := []string{}
	for k := range ansSet {
		ans = append(ans, k)
	}
	sort.Strings(ans)
	return ans
}

func main() {
	fmt.Println("hello world")
}
