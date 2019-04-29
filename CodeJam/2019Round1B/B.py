import sys


def query(v):
    print(v)
    sys.stdout.flush
    return int(input())


def prians(a1, a2, a3, a4, a5, a6):
    print(str(a1) + ' ' + str(a2) + ' ' + str(a3) +
          ' ' + str(a4) + ' ' + str(a5) + ' ' + str(a6))
    sys.stdout.flush
    return int(input())


T = int(input().split()[0])
for cas in range(T):
    val1 = query(54)
    r1 = val1 >> 54
    r2 = (val1 - (r1 << 54)) >> 27
    val2 = query(164)
    r3 = val2 >> 54
    r4 = (val2 - (r3 << 54)) >> 41
    s1 = val1 - r1 * (1 << 54) - r2 * (1 << 27) - \
        r3 * (1 << 18) - r4 * (1 << 13)
    s2 = val2 - r3 * (1 << 54) - r4 * (1 << 41)
    s1 >>= 9
    s2 >>= 27
    r5 = (s2 - s1) // 30
    r6 = s1 - (r5 << 1)
    if prians(r1, r2, r3, r4, r5, r6) < 0:
        sys.stderr.write(str(val1) + ' -- ' + str(val2) + '\n')
        sys.stderr.write(str(r1) + ' ' + str(r2) + ' ' + str(r3) +
                         ' ' + str(r4) + ' ' + str(r5) + ' ' + str(r6) + '\n')
        exit(1)
