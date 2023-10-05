t = int(input())

for _ in range(t):
	nmk = input().split(" ")
	n = int(nmk[0])
	m = int(nmk[1])
	k = int(nmk[2])

	a_apples = input().split(" ")
	b_apples = input().split(" ")
	a_apples = [int(a) for a in a_apples]
	b_apples = [int(b) for b in b_apples]

	min_a = min(a_apples)
	min_b = min(b_apples)
	max_a = max(a_apples)
	max_b = max(b_apples)
	res = 0
	if k % 2 == 1:
		if min_a < max_b:
			res = sum(a_apples) - min_a + max_b
		else:
			res = sum(a_apples)
	else:
		if min_a < max_b:
			res = sum(a_apples) - min_a + max_b
			if max_b > max_a:
				max_a = max_b
			if min_a < min_b:
				min_b = min_a
			res -= max_a
			res += min_b
		else:
			if min_b < max_a:
				res = sum(a_apples) - max_a + min_b
			else:
				res = sum(a_apples)
	print(res)
