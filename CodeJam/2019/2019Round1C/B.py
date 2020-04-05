import sys


def query(pos):
    print(pos)
    sys.stdout.flush
    ch = input()
    return ord(ch) - 65


def inter(ret):
    print(ret)
    sys.stdout.flush
    return input()


def find(arr, tar, now):
    for i in range(5):
        if arr[i] < tar and chr(i + 65) not in now:
            return i


T = int(input().split(' ')[0])
for cas in range(T):
    ans = ''
    jc = 120
    now = 0
    las = [[] for i in range(5)]
    for i in range(119):
        las[0].append(i * 5)
    for sol in range(5):
        cnt = [0 for i in range(5)]
        tmp = [[] for i in range(5)]
        for pos in las[now]:
            r = query(pos + 1)
            cnt[r] += 1
            tmp[r].append(pos + 1)
        jc /= (5 - sol)
        now = find(cnt, jc, ans)
        ans += chr(now + 65)
        las = tmp
    if inter(ans) == 'N':
        exit(1)
