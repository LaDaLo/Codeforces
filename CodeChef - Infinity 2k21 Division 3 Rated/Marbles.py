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

mod = 998244353
INF = 10 ** 10


def main():
    vowel = ['a', 'e', 'i', 'o', 'u']
    for _ in range(in1()):
        N = in1()
        S = input()
        P = input()
        res = 0
        tmp = []
        for i in range(N):
            if S[i] == P[i]:
                continue
            if S[i] == '?':
                tmp.append(P[i])
            elif P[i] == '?':
                tmp.append(S[i])
            else:
                if (S[i] in vowel) ^ (P[i] in vowel):
                    res += 1
                else:
                    res += 2
        mn = INF
        for i in range(26):
            cur = chr(ord('a') + i)
            cost = 0
            for c in tmp:
                if c == cur:
                    continue
                if (cur in vowel) ^ (c in vowel):
                    cost += 1
                else:
                    cost += 2
            mn = min(mn, cost)
        print(res) if mn == INF else print(res + mn)

if __name__ == "__main__":
    main()
