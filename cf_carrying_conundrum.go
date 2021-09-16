package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
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

		var mixed_sum string
		scanf("%s\n", &mixed_sum)

		var odd_num_str string = ""
		var even_num_str string = ""
		for i, c := range mixed_sum {
			if i % 2 == 0 {
				even_num_str += string(c)
			} else {
				odd_num_str += string(c)
			}
		}

		var odd_num, _ = strconv.Atoi(odd_num_str)
		var even_num, _ = strconv.Atoi(even_num_str)


		printf("%d\n", (odd_num + 1) * (even_num + 1) - 2)
	}

}
