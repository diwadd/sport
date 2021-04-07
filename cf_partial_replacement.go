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
				break
			}
		}

		for i := index+1; i < n; i++ {

			var max_index = -1

			for j := i; j <= min_int(n-1, i+k-1); j++ {
				if s[j] == '*' {
					max_index = j
				}
			}

			
			if max_index != -1 {
				res[max_index] = 1
				i = max_index
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
		}
		printf("%d\n", ans)

	}

}
