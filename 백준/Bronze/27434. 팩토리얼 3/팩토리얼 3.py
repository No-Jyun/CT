import sys
sys.set_int_max_str_digits(999999999)

n = int(input())
a = 1

for i in range(1, n + 1):
    a *= i
print(a)