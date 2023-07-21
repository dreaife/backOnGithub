package testFunc

func Max(n1, n2 int) int {
	var res int
	if n1 > n2 {
		res = n1
	} else {
		res = n2
	}
	return res
}
