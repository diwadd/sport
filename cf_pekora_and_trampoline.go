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

func read_vector(n int64) []int64 {

	vec := make([]int64, n)

	for i := int64(0); i < n; i++ {
		if i != n-1 {
			scanf("%d ", &vec[i])
		} else {
			scanf("%d\n", &vec[i])
		}
	}
	return vec
}

func main() {
	defer writer.Flush()

	var T int = 0
	scanf("%d\n", &T)

	for t := 0; t < T; t++ {

		var N int64 = 0
		scanf("%d\n", &N)
		vec := read_vector(N)
		del := make([]int64, N)

		for i := int64(0); i < N; i++ {
			del[i] = 0
		}

		var res int64 = 0
		for i := int64(0); i < N; i++ {
			var jumps int64 = del[i]

			if jumps < vec[i]-1 {
				var free_jumps int64 = vec[i] - 1 - jumps
				res += free_jumps
				jumps += free_jumps
			}

			if i+1 < N {
				del[i+1] += jumps - vec[i] + 1
			}

			if i+2 < N {
				for j := i + 2; j < min_int64(N, i+vec[i]+1); j++ {
					del[j] += 1
				}

			}

		}
		printf("%d\n", res)
	}

}
