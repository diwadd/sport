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

func min_int64(a int64, b int64) int64 { if a < b { return a } else { return b } }

func main() {
	defer writer.Flush()

	var T int = 0
	scanf("%d\n", &T)

	for t := 0; t < T; t++ {

        var a int64 = 0
        var b int64 = 0

        scanf("%d %d\n", &a, &b)

        if(a == b) {
            printf("0 0\n")
        } else {
            if(a < b) {
                a, b = b, a
            }

            var res_one = a - b
            var res_two = min_int64(b % res_one, res_one - b % res_one)

            printf("%d %d\n", res_one, res_two)
        }


	}

}
