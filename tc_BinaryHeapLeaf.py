import math
class BinaryHeapLeaf:
    def maxDiff(self, N):

        if N == 2:
            return (1, 1)
        if N == 3:
            return (2, 2)

        index = math.floor(math.log2(N+1) - 1)
        sum = math.pow(2,index+1) - 1

        a = N - sum
        pr = a // 2 + a % 2
        left = math.pow(2, index) - pr + a

        if sum*2 == N:
            right = N - index - 1
        else:
            right = N - index
        return (left, right)

if __name__ == "__main__":
    bhl = BinaryHeapLeaf()
    for i in range(2, 1000):
        print(" < --- --- >")
        a = bhl.maxDiff(i)
        print(f"i: {i} res : {a}")


