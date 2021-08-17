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
 
	var S, T int = 0, 0
	scanf("%d %d\n", &S, &T)
 
	var res int = 0
	for a := 0; a <= S; a++ {
		for b := 0; b <= S; b++ {
			for c := 0; c <= S; c++ {
				if a+b+c <= S && a*b*c <= T {
					res++
				}
			}
		}
	}
 
	printf("%d\n", res)
 
}