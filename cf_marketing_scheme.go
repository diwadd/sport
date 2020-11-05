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

		var l, r int64
		scanf("%d %d\n", &l, &r)

		var a int64 = r + 1

		var l_left_side float64 = float64(l % a)
		var l_right_side float64 = float64(float64(a)/2.0)

		var r_left_side float64 = float64(r % a)
		var r_right_side = float64(float64(a)/2.0)

		if l_left_side >= l_right_side && r_left_side >= r_right_side {
			printf("YES\n")
		} else {
			printf("NO\n")
		}

	}

}
