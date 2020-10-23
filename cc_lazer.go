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

type Event struct {
	y int;
	t int;
	i int;
}


type ByYThenT []Event

func (events ByYThenT) Len() int           { return len(events) }
func (events ByYThenT) Less(i, j int) bool { 

	if events[i].y < events[j].y { 
		return true;
	} else if events[i].y == events[j].y {
		if events[i].t <= events[j].t {
			return true;
		} else {
			return false;
		}
	}
	return false;
}

func (events ByYThenT) Swap(i, j int) { 
	events[i].y, events[j].y = events[j].y, events[i].y;
	events[i].t, events[j].t = events[j].t, events[i].t;
	events[i].i, events[j].i = events[j].i, events[i].i;
}


func fenwick_sum(index int, fenwick_bit *[]int) int {
	var res int = 0;
	for index > 0 {
		res = res + (*fenwick_bit)[index];
		index = index - (index & (-index));
	}
	return res;
}


func fenwick_update(index int, value int, fenwick_bit *[]int) {
	for index < len((*fenwick_bit)) {
		(*fenwick_bit)[index] = (*fenwick_bit)[index] + value;
		index = index + (index & (-index)); 
	}
}

func fenwick_print(fenwick_bit *[]int) {
	var N int = len(*fenwick_bit);
	for i := 0; i < N; i++ {
		if i != N - 1 {
			printf("%d ", (*fenwick_bit)[i]);
		} else if i == N - 1 {
			printf("%d\n", (*fenwick_bit)[i]);
		}
	}
}

func main() {
	defer writer.Flush()

	var T int = 0;
	scanf("%d\n", &T);
	for t := 0; t < T; t++ {

		var N, Q int;
		scanf("%d %d\n", &N, &Q);
		
		var a_vec = make([]int, N);
		for n := 0; n < N; n++ {
			var a int;
			if n != N - 1 { scanf("%d ", &a); }
			if n == N - 1 { scanf("%d\n", &a); }
			a_vec[n] = a;
		}

		var q_vec = make([][]int, Q);
		for q := 0; q < Q; q++ {
			
			var x1, x2, y int;
			scanf("%d %d %d\n", &x1, &x2, &y);
			// printf("q = %d x1 %d x2 %d y %d\n", q, x1, x2, y);
			q_vec[q] = []int{x1, x2, y};
		}


		var events []Event;
		for n := 0; n < N - 1; n++ {
			var e_low Event = Event{min_int(a_vec[n], a_vec[n+1]), 1, n};
			var e_high Event = Event{max_int(a_vec[n], a_vec[n+1]), 3, n};

			events = append(events, e_low);
			events = append(events, e_high);
		}

		for q := 0; q < Q; q++ {
			var e_lazer Event = Event{q_vec[q][2], 2, q};
			events = append(events, e_lazer);
		}

		sort.Sort(ByYThenT(events));
		// sort.Slice(events, func (i, j int) bool {
		// 	if events[i].y < events[j].y { 
		// 		return true;
		// 	} else if events[i].y == events[j].y {
		// 		if events[i].t <= events[j].t {
		// 			return true;
		// 		} else {
		// 			return false;
		// 		}
		// 	}
		// 	return false;
		// });

		// for i := range events {
		// 	printf("e: %d - %d - %d\n", events[i].y, events[i].t, events[i].i )
		// }

		var fenwick_bit = make([]int, N);
		var res = make([]int, Q);
		// fenwick_sum(1, &fenwick_bit);
		// fenwick_update(1, 1, &fenwick_bit);
		for e := range events {
			// fenwick_print(&fenwick_bit);
			if events[e].t == 1 {
				fenwick_update(events[e].i+1, 1, &fenwick_bit);
			} else if events[e].t == 2 {
				res[events[e].i] = fenwick_sum(q_vec[events[e].i][1]-1, &fenwick_bit) - fenwick_sum(q_vec[events[e].i][0]-1, &fenwick_bit);
			} else if events[e].t == 3 {
				fenwick_update(events[e].i+1, -1, &fenwick_bit);
			}
		}

		for r := range res {
			printf("%d\n", res[r]);
		}

	}


}