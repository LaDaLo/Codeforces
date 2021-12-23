mod = 1000000007
def cal(n):
    if n == 0:
        return 1
    elif n == 1:
        return 10

    tmp1 = cal(n // 2)
    tmp2 = cal(n // 2 - 1)
    if n % 2 == 0:
        return tmp1 * tmp1 - tmp2 * tmp2
    else:
        tmp3 = cal(n // 2 + 1)
        return tmp1 * (tmp3 - tmp2)

print(cal(10) % mod)
