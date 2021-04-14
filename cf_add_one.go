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

	const MAX_M int = 200007	
	var dp [MAX_M]int

	for i := 0; i <= 8; i++ {
		dp[i] = 2
	}

	dp[9] = 3

	var MOD_FACTOR = 1000000000 + 7

	for i := 10; i < MAX_M; i++ {
		dp[i] = (dp[i-9] + dp[i-10]) % MOD_FACTOR
	}

	for t := 0; t < T; t++ {

		var n string
		var m int
		scanf("%s %d\n", &n, &m);

		var res int = 0
		for _, r := range n {
			var d int = int(r - '0')
			if (m + d < 10) {
				res = (res % MOD_FACTOR + 1) % MOD_FACTOR
			} else {
				res = ((res % MOD_FACTOR) + (dp[m + d - 10] % MOD_FACTOR)) % MOD_FACTOR
			}
		}

		printf("%d\n", res)

	}

}
