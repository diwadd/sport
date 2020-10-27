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


func binary_search(a *[]int, pos int) (bool, int, int) {
	var left int = 0
	var right int = len(*a)
	var n_low int = 0
	var n_high int = 0
	for left < right {
		var middle int = (left + right) / 2
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


func main() {
	defer writer.Flush()



	var n, x, pos int;
	scanf("%d %d %d\n", &n, &x, &pos);
	
	var n_less int = x - 1
	var n_bigger int = n - x

	numbers := make([]int, n)
	for i := range numbers { 
		numbers[i] = i
	}

	var n_low, n_high int
	_, n_low, n_high = binary_search(&numbers, pos)

	printf("%d %d\n", n_low, n_high)


}