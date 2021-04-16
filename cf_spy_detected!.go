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

func main() {
	defer writer.Flush()

	var T int = 0
	scanf("%d\n", &T)

	for t := 0; t < T; t++ {

		var n int = 0
		scanf("%d\n", &n)
		a_vec := make([]int, n)

		for i := 0; i < n; i++ {
			if i != n - 1 {
				scanf("%d ", &a_vec[i])
			} else {
				scanf("%d\n", &a_vec[i])
			}			
		}

		numbers := make(map[int]int)
		for i := 0; i < n; i++ {
			if _, key := numbers[a_vec[i]]; key {
				numbers[a_vec[i]] += 1
			} else {
				numbers[a_vec[i]] = 1
			}
		}

		var spy int = 0
		for key, element := range numbers {
			if element == 1 {
				spy = key
			}
		}

		var index int = 0
		for i := 0; i < n; i++ {
			if a_vec[i] == spy {
				index = i + 1
			}
		}

		printf("%d\n", index)
	}
}
