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

func min_int(a int, b int) int { if a < b { return a } else { return b } }
func min_int64(a int64, b int64) int64 { if a < b { return a } else { return b } }

func max_int(a int, b int) int { if a > b { return a } else { return b } }
func max_int64(a int64, b int64) int64 { if a > b { return a } else { return b } }

func main() {
	defer writer.Flush()

	var T int = 0
	scanf("%d\n", &T)

	for t := 0; t < T; t++ {

		var n int = 0
		var k int = 0
		scanf("%d %d\n", &n, &k)
		var s string
		scanf("%s\n", &s)

		res := make([]int, n)
		var index int = 0
		for i := 0; i < n; i++ {
			if s[i] == '*' {
				res[i] = 1
				index = i
				// printf("index: %d\n", index)
				break
			}
		}

		for i := index; i < n; i++ {
			// printf("I: %d\n", i)
			for j := min_int(n - 1, i + k); j >= i; j-- {
				if s[j] == '*' {
					// printf("-> j: %d\n", j)
					res[j] = 1
					i = i + k - 1
					break
				}
			}
		}

		for i := n-1; i >= 0; i-- {
			if s[i] == '*' && res[i] == 1 {
				break
			}

			if s[i] == '*' {
				res[i] = 1
				index = i
				break
			}
		}


		var ans int = 0
		for i := 0; i < n; i++ {
			if res[i] == 1 {
				ans = ans + 1
			}
			// printf("%d ", res[i])
		}
		// printf("\n")
		printf("%d\n", ans)

	}

}
