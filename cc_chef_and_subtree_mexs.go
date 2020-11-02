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

func min_int(a int, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}
func min_int64(a int64, b int64) int64 {
	if a < b {
		return a
	} else {
		return b
	}
}

func max_int(a int, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}
func max_int64(a int64, b int64) int64 {
	if a > b {
		return a
	} else {
		return b
	}
}

func count_leafs(node int64, parent int64, graph *[][]int64, leaf_count *[]int64) int64 {

	(*leaf_count)[node] = 1
	for i := int64(0); i < int64(len((*graph)[node])); i++ {
		var child int64 = (*graph)[node][i]
		if child == parent {
			continue
		}
		(*leaf_count)[node] += count_leafs(child, node, graph, leaf_count)
	}
	return (*leaf_count)[node]
}

func get_mex(node int64, parent int64, n_sub_nodes int64, res *int64, graph *[][]int64, leaf_count *[]int64) {

	var d int64 = n_sub_nodes + (*leaf_count)[node]
	var n_children int64 = 0
	for i := int64(0); i < int64(len((*graph)[node])); i++ {
		var child int64 = (*graph)[node][i]
		if child == parent {
			continue
		}
		n_children++
		get_mex(child, node, d, res, graph, leaf_count)
	}

	if n_children == 0 {
		*res = max_int64((*res), d)
	}

}

func main() {
	defer writer.Flush()

	var T int64 = 0
	scanf("%d\n", &T)

	res_array := make([]int64, T)
	for t := int64(0); t < T; t++ {

		var N int64
		scanf("%d\n", &N)

		graph := make([][]int64, N+1)
		for i := int64(0); i < N+1; i++ {
			graph[i] = make([]int64, 0)
		}

		for i := int64(1); i <= N-1; i++ {
			var p_i int64
			if i < N {
				scanf("%d ", &p_i)
			} else {
				scanf("%d\n", &p_i)
			}

			graph[p_i] = append(graph[p_i], i+1)
			graph[i+1] = append(graph[i+1], p_i)
		}

		// for i := range graph {
		// 	printf("node %d: ", i)
		// 	for j := range graph[i] {
		// 		printf("%d ", graph[i][j])
		// 	}
		// 	printf("\n")
		// }

		leaf_count := make([]int64, N+1)

		var root int64 = 1
		var root_parent int64 = 0
		count_leafs(root, root_parent, &graph, &leaf_count)

		// printf("leaf count: ")
		// for i := range leaf_count {
		// 	printf("%d ", leaf_count[i])
		// }

		var res int64 = 0
		get_mex(root, root_parent, 0, &res, &graph, &leaf_count)

		res_array[t] = res

	}

	for i := range res_array {
		printf("%d\n", res_array[i])
	}

}
