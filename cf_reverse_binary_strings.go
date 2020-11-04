package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
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

func main() {
	defer writer.Flush()

	var T int = 0
	scanf("%d\n", &T)

	for t := 0; t < T; t++ {

		var n int = 0
		scanf("%d\n", &n)

		var s string
		scanf("%s\n", &s)

		s = strings.TrimRight(s, "\n")

		var n_one_blocks int = 0
		var n_zero_blocks int = 0

		for i := 1; i < len(s); i++ {

			if s[i-1] == s[i] {
				if string(s[i]) == "0" {
					n_zero_blocks++
				} else {
					n_one_blocks++
				}
			}

		}

		// printf("%d %d\n", n_one_blocks, n_zero_blocks)
		var res int = max_int(n_one_blocks, n_zero_blocks)
		printf("%d\n", res)

	}

}
