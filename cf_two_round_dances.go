package main

import (
	"bufio"
	"os"
	"fmt"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{}) { fmt.Fscanf(reader, f, a...) }

func factorial(n int64) int64 {
	if n == 1 {
		return 1;
	} else {
		return n*factorial(n-1);
	}
}

func main() {
	defer writer.Flush()

	var n int64
	scanf("%d\n", &n)

	var res int64 = (factorial(n)/((n/2)*(n/2))) / 2;

	printf("%d\n", res)
}