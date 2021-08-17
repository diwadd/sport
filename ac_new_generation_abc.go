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
 
	var N int = 0
	scanf("%d\n", &N)
 
	if N >= 1 && N <= 125 {
		printf("4\n")
	} else if N >= 126 && N <= 211 {
		printf("6\n")
	} else if N >= 212 {
		printf("8\n")
	}
 
}