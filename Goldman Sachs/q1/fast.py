from math import lcm

class Solution:
    def minimizeSet(self, d1: int, d2: int, ct1: int, ct2: int) -> int:
        
        f = lambda x: (x+abs(x))//2                             

        n, prev, d = ct1 + ct2, 0, lcm(d1,d2)

        while n > prev:                    # keep going until we do not 
                                           # have to add more
            prev = n       

            l1, l2  = n//d2 - n//d, n//d1 - n//d   # l1, l2 : length of group1, group2

            n+= f(f(ct1 - l1) + f(ct2 - l2)- n + n//d + l2 + l1) # determine the incease in n

        return n
    
# Input values
divisor1, divisor2, uniqueCnt1, uniqueCnt2 = 2, 7, 1, 3

# Create an instance of the Solution class
solution = Solution()

# Call the minimizeSet function with the provided input
result = solution.minimizeSet(divisor1, divisor2, uniqueCnt1, uniqueCnt2)

# Output the result
print("Output:", result)