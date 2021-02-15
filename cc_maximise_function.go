package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func value(ax int, ay int, az int) int {
	return abs(ax-ay) + abs(ax-az) + abs(ay-az)
}

func main() {
	defer writer.Flush()

	var T int = 0
	scanf("%d\n", &T)

	for t := 0; t < T; t++ {

		var N int = 0
		scanf("%d\n", &N)

		a_vec := make([]int, N)
		for i := 0; i < N; i++ {
			if i != N-1 {
				scanf("%d ", &a_vec[i])
			} else {
				scanf("%d\n", &a_vec[i])
			}
		}

		sort.Ints(a_vec)

		var ax int = a_vec[0]
		var az int = a_vec[N-1]

		var res int = 0
		for i := 1; i <= N-2; i++ {
			var v int = value(ax, a_vec[i], az)
			if v > res {
				res = v
			}
		}

		printf("%d\n", res)

	}

}
