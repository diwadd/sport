package main

import (
	"bufio"
	"os"
	"fmt"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{}) { fmt.Fscanf(reader, f, a...) }

func min_int(a int, b int) int { if a < b { return a; } else { return b; } }
func min_int64(a int64, b int64) int64 { if a < b { return a; } else { return b; } }

func max_int(a int, b int) int { if a > b { return a; } else { return b; } }
func max_int64(a int64, b int64) int64 { if a > b { return a; } else { return b; } }


func binary_search(a *[]int64, pos int64) (bool, int64, int64) {
	var left int64 = 0
	var right int64 = len(*a)
	var n_low int64 = 0
	var n_high int64 = 0
	for left < right {
		var middle int64 = (left + right) / 2
		if (*a)[middle] <= pos {
			left = middle + 1
			n_low++
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




// func combination(n int64, k int64) {

// 	if k > n {
// 		return 0
// 	} else {

// 	}

// }


func main() {
	defer writer.Flush()

	var n, x, pos int64;
	scanf("%d %d %d\n", &n, &x, &pos);	

	var n_less int64 = x - 1
	var n_bigger int64 = n - x
	var mod_by int64 = 1000000000 + 7

	factorial := make([]int64, n+1);
	factorial[0] = 1
	for i := int64(1); i <= n; i++ {
		// Formaly it should be ( (factorial[i-1] % mod_by) * (i % mod_by) ) % mod_by
		// but since n does not exceed 1000 in the problem constraints then the below suffices.
		factorial[i] = ( factorial[i-1] * i ) % mod_by
	}  


	numbers := make([]int64, n)
	for i := range numbers { 
		numbers[i] = i
	}

	var n_low, n_high int64
	_, n_low, n_high = binary_search(&numbers, pos)

	printf("%d %d\n", n_low, n_high)


}