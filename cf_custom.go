package main

import (
	"bufio"
	"os"
	"fmt"
	"sort"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{}) { fmt.Fscanf(reader, f, a...) }

func min_int(a int, b int) int { if a < b { return a; } else { return b; } }
func min_int64(a int64, b int64) int64 { if a < b { return a; } else { return b; } }

func max_int(a int, b int) int { if a > b { return a; } else { return b; } }
func max_int64(a int64, b int64) int64 { if a > b { return a; } else { return b; } }


func main() {
	defer writer.Flush()



	var n, x, pos int;
	scanf("%d %d\n", &N, &Q);
		


}