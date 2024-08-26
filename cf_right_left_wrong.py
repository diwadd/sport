
t = int(input())

def get_sum(prefix_sum, left, right):
    if left == 0:
        return prefix_sum[right]
    
    return prefix_sum[right] - prefix_sum[left-1]

for _ in range(t):

    n = int(input())
    numbers = input().split()
    labels = input()

    numbers = [int(num) for num in numbers]
    labels = [*labels]

    # print(numbers)
    # print(labels)

    prefix_sum = [0 for _ in range(n)]

    prefix_sum[0] = numbers[0]
    for i in range(1, n):
        prefix_sum[i] = prefix_sum[i-1] + numbers[i]
    
    # print(prefix_sum)

    left = 0
    right = n-1

    res = 0
    while left < right:
        if labels[left] == "L" and labels[right] == "R":
           res += get_sum(prefix_sum, left, right)
           left += 1
           right -= 1
        if labels[left] != "L":
            left += 1
            continue
        if labels[right] != "R":
            right -= 1
            continue

    print(res)
