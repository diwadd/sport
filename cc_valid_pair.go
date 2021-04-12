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

	var A int = 0
	var B int = 0
	var C int = 0
	scanf("%d %d %d\n", &A, &B, &C)

	if A == B || B == C || A == C {
		printf("YES")
	} else {
		printf("NO")
	}

}