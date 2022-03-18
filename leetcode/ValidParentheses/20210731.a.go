package main

import "fmt"

// 0ms 100.00% 2MB 60.00%
// O(N) O(1)
func isValid(s string) bool {
	// empty string
	if s == "" {
		return true
	}
	var pairs = map[byte]byte{
		')': '(',
		'}': '{',
		']': '[',
	}
	var stck []byte

	for i := 0; i < len(s); i++ {
		c := s[i]
		if p, ok := pairs[c]; !ok {
			stck = append(stck, c)
		} else if len(stck) > 0 && stck[len(stck)-1] == p {
			stck = stck[:len(stck)-1]
		} else {
			return false
		}
	}
	return len(stck) == 0
}

func main() {

	fmt.Println(isValid("()"))
	fmt.Println(isValid("((])"))
	fmt.Println(isValid("((})"))
}
