from collections import deque
 
class OperateString:
    def operate(self, s, moves):
        
        n = len(moves)
        m = len(s)
        sum = 0
        for i in range(n):
            sum = (sum + moves[i]) % m
            
        d = deque(list(s))
        d.rotate(-sum)
        
         # print("sum: " + str(sum))
        return "".join(d)