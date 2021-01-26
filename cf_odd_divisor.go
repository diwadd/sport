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

		var x uint64 = 0
		scanf("%d\n", &x)

		for x % 2 == 0 {
			x = x / 2
		}

		if x == 1 {
			printf("NO\n")
		} else if x % 2 != 0 {
			printf("YES\n")
		}
	}
}
