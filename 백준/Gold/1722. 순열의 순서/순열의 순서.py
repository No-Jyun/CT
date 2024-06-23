def reverse_cal(index):
    sum = 1
    while index <= n - 1:
        c = 0
        for i in range(1, n + 1):
            if num[i] > index:
                c += 1
            elif num[i] == index:
                sum += c * fac[n - index]
                break
        index += 1
    return sum

def decide_order():
    index = 1
    now = k - 1
    while index <= n - 1:
        right_o = now // fac[n - index] + 1
        c = 0
        for i in range(1, n + 1):
            if not num[i]:
                c += 1
            if c == right_o:
                right_o = i
                break
        
        num[right_o] = 1
        result[index] = right_o
        now %= fac[n - index]
        index += 1
    
    for i in range(1, n + 1):
        if not num[i]:
            result[index] = i

n = int(input())
data = input().split()
mode = int(data[0])
    
fac = [1] * 21
for i in range(1, 21):
  fac[i] = fac[i - 1] * i

num = [0] * 21
result = [0] * 21
    
if mode == 1:
    k = int(data[1])
    decide_order()
    print(' '.join(map(str, result[1:n+1])))
    
else:
    for i in range(1, n + 1):
      num[int(data[i])] = i
    print(reverse_cal(1))
