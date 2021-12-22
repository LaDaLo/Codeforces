# Fast IO Region
import os, sys
from io import BytesIO, IOBase

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

# Input
input = lambda: sys.stdin.readline().rstrip("\r\n")
in1 = lambda: int(input())
in2 = lambda: list(map(int, input().split()))

# Solve
import math
from collections import Counter
mod = 998244353
INF = 10 ** 10


def main():
    for _ in range(in1()):
        N, M = in2()
        A = in2()
        B = in2()

        cB = Counter(B)
        a = sorted(enumerate(A), key=lambda x : x[1], reverse=True)
        b = sorted(list(set(B)), reverse=True)
        res = []
        arr = []
        i = 0
        j = 0
        prev = -1
        nxt = -1
        while i < N:
            cur = a[i][1]
            cnt = 0
            it = i
            while it < N and a[it][1] == cur:
                if a[it][0] > prev:
                    cnt += 1
                nxt = max(nxt, a[it][0])
                it += 1
            if cnt > 0:
                arr.append([cur, cnt])
            prev = nxt
            i = it

        i = 0
        j = 0
        while True:
            if arr[i][0] > b[j]:
                print("NO")
                break
            elif arr[i][0] < b[j]:
                print("YES")
                res.append(b[j])
                for it in reversed(range(j + 1, len(b))):
                    for _ in range(cB[b[it]]):
                        print(b[it], end=' ')
                for _ in range(cB[b[j]] - 1):
                    print(b[j], end=' ')
                print(*res)
                break

            else:
                if arr[i][1] > cB[b[j]]:
                    print("NO")
                    break
                elif arr[i][1] < cB[b[j]]:
                    print("YES")
                    for _ in range(arr[i][1] + 1):
                        res.append(b[j])
                    for it in reversed(range(j + 1, len(b))):
                        for _ in range(cB[b[it]]):
                            print(b[it], end=' ')
                    for _ in range(cB[b[j]] - 1 - a[i][1]):
                        print(b[j], end=' ')
                    print(*res)
                    break
                else:
                    if i + 1 == len(arr) and j + 1 == len(b):
                        print("NO")
                        break
                    elif i + 1 == len(arr):
                        print("YES")
                        for _ in range(cB[b[j]]):
                            res.append(b[j])
                        res.append(b[j + 1])

                        for it in reversed(range(j + 2, len(b))):
                            for _ in range(cB[b[it]]):
                                print(b[it], end=' ')

                        for _ in range(cB[b[j + 1]] - 1):
                            print(b[j + 1], end=' ')
                        print(*res)
                        break
                    elif j + 1 == len(b):
                        print("NO")
                        break
                    for _ in range(cB[b[j]]):
                        res.append(b[j])
                    i += 1
                    j += 1


if __name__ == "__main__":
    main()
