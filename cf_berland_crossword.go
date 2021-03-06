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

		var n, u, d, r, l int
		scanf("%d %d %d %d %d\n", &n, &u, &r, &d, &l)

		var is_ok bool = false
		for i := 0; i <= 15; i++ {
			var nu int = u
			var nr int = r
			var nd int = d
			var nl int = l

			if i&1 == 1 {
				nu = nu - 1
				nl = nl - 1
			}

			if i&2 == 2 {
				nu = nu - 1
				nr = nr - 1
			}

			if i&4 == 4 {
				nd = nd - 1
				nr = nr - 1
			}

			if i&8 == 8 {
				nd = nd - 1
				nl = nl - 1
			}

			if (nu >= 0 && nd >= 0 && nr >= 0 && nl >= 0) && (nu <= n-2 && nd <= n-2 && nr <= n-2 && nl <= n-2) {
				is_ok = true
				break
			}
		}

		if is_ok == true {
			printf("YES\n")
		} else {
			printf("NO\n")
		}
	}
}
