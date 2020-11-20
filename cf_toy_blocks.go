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

		var N int64
		scanf("%d\n", &N)

		var a_max int64 = 0
		var a_sum int64
		for n := int64(0); n < N; n++ {
			var a int64
			if(n != N-1) {
				scanf("%d ", &a)
			} else {
				scanf("%d\n", &a)
			}
			a_sum += a
			if(a > a_max) {
				a_max = a
			}
		}

		var k int64 = max_int64(a_max, (a_sum + N - 2)/(N - 1))
		var res int64 = k * (N-1) - a_sum
		printf("%d\n", res)

	}

}
