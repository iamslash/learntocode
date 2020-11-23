/* Copyright (C) 2020 by iamslash */

package main

// 552ms 100.00% 60.6MB 100.00%
// DFS
type ThroneInheritance struct {
	data map[string][]string
	dead map[string]bool
	root string
}

func Constructor(kingName string) ThroneInheritance {
	return ThroneInheritance{
		data: make(map[string][]string),
		dead: make(map[string]bool),
		root: kingName,
	}
}

func (this *ThroneInheritance) Birth(p string, c string) {
	this.data[p] = append(this.data[p], c)
}

func (this *ThroneInheritance) Death(u string) {
	this.dead[u] = true
}

func (this *ThroneInheritance) dfs(u string, tree *[]string) {
	if _, ok := this.dead[u]; ok == false {
		*tree = append(*tree, u)
	}
	for _, c := range this.data[u] {
		this.dfs(c, tree)
	}
}

func (this *ThroneInheritance) GetInheritanceOrder() []string {
	tree := []string{}
	this.dfs(this.root, &tree)
	return tree
}
