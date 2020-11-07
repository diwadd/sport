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

type LeftRightPair struct {
	l, r int
}

func main() {
	defer writer.Flush()

	var T int = 0
	scanf("%d\n", &T)

	for t := 0; t < T; t++ {

		var a, b int
		scanf("%d %d\n", &a, &b);

		var s string
		scanf("%s\n", &s)

		pairs := make([]LeftRightPair, 0)
		for i := 0; i < len(s); i++ {

			if string(s[i]) == "0" {
				continue
			} 

			if string(s[i]) == "1" {
				var ones_start_index int = i
				var ones_stop_index int = len(s)
				for j := i + 1; j < len(s); j++ {
					if string(s[j]) == "0" {
						ones_stop_index = j
						break
					}
				}
				i = ones_stop_index
				pairs = append(pairs, LeftRightPair{ones_start_index, ones_stop_index})
			}

		}


		if len(pairs) == 0 {
			printf("0\n")
			continue
		}

		var res int = a
		for i := 1; i < len(pairs); i++ {
			res += min_int((pairs[i].l - pairs[i-1].r)*b, a)
		}

		printf("%d\n", res)


	}

}
