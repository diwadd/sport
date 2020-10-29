package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

func min_int(a int, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func min_int64(a int64, b int64) int64 {
	if a < b {
		return a
	} else {
		return b
	}
}

func max_int(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
func max_int64(a int64, b int64) int64 {
	if a > b {
		return a
	} else {
		return b
	}
}

func binary_search(a *[]int64, pos int64) (bool, int64, int64) {
	var left int64 = 0
	var right int64 = int64(len(*a))
	var n_low int64 = 0
	var n_high int64 = 0
	for left < right {
		var middle int64 = (left + right) / 2
		if (*a)[middle] <= pos {
			left = middle + 1

			if pos != middle {
				n_low++
			}
		} else {
			right = middle
			n_high++
		}
	}

	if left > 0 && (*a)[left-1] == pos {
		return true, n_low, n_high
	} else {
		return false, n_low, n_high
	}
}

func modular_inverse(a int64, m int64) int64 {

	var m_init int64 = m
	var y int64 = 0
	var x int64 = 1

	if m == 1 {
		return 0
	}

	for a > 1 {
		var q int64 = a / m
		var t int64 = m

		m = a % m
		a = t
		t = y

		y = x - q*y
		x = t
	}

	if x < 0 {
		x += m_init
	}

	return x
}

func combination(n int64, k int64, factorial *[]int64, mod_inv *[]int64, mod_by int64) int64 {

	if k > n {
		return 0
	} else {
		var r int64 = ((*mod_inv)[n-k] * (*mod_inv)[k]) % mod_by
		r = (r * (*factorial)[n]) % mod_by
		return r
	}

}

func main() {
	defer writer.Flush()

	var n, x, pos int64
	scanf("%d %d %d\n", &n, &x, &pos)

	var n_smaller_numbers int64 = x - 1
	var n_bigger_numbers int64 = n - x

	var mod_by int64 = 1000000000 + 7

	factorial := make([]int64, n+1)
	mod_inv := make([]int64, n+1)

	factorial[0] = 1
	mod_inv[0] = 1

	for i := int64(1); i <= n; i++ {
		// Formaly it should be ( (factorial[i-1] % mod_by) * (i % mod_by) ) % mod_by
		// but since n does not exceed 1000 in the problem constraints then the below suffices.
		factorial[i] = (factorial[i-1] * i) % mod_by
		mod_inv[i] = modular_inverse(factorial[i], mod_by) % mod_by
	}

	numbers := make([]int64, n)
	for i := int64(0); i < int64(len(numbers)); i++ {
		numbers[i] = i
	}

	var n_less, n_greater int64
	_, n_less, n_greater = binary_search(&numbers, pos)

	var c1 int64 = (combination(n_smaller_numbers, n_less, &factorial, &mod_inv, mod_by) * factorial[n_less]) % mod_by
	var c2 int64 = (combination(n_bigger_numbers, n_greater, &factorial, &mod_inv, mod_by) * factorial[n_greater]) % mod_by

	var res int64 = (c1 * c2) % mod_by
	res = (res * factorial[n-n_less-n_greater-1]) % mod_by

	printf("%d\n", res)

}
