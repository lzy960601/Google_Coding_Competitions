import sys

T = int(input())


def put_token(v, p):
    print(str(v) + ' ' + str(p))
    sys.stdout.flush


def see_vase(v):
    print(str(v) + ' 0')
    sys.stdout.flush
    val = int(input().split(' ')[0])
    if val < 0:
        exit(1)
    return val


def compare(v1, v2):
    if v1[1] < v2[1] or (v1[1] == v2[1] and v1[0] > v2[0]):
        return -1
    return 1


for cas in range(T):
    vases = []
    last_vases = []
    for day_cnt in range(100):
        day = int(input())
        if day <= 60:
            vase_id = (day + 3) // 4
            id = 100
            if day % 4 > 1:
                id = day
            put_token(vase_id, id)
            continue
        if day <= 80:
            vase_id = day - 60
            tokens = see_vase(vase_id)
            vases.append([vase_id, tokens])
            continue
        if day <= 94:
            vases.sort(key=lambda x: (x[1], -x[0]))
            vases[2][1] += 1
            put_token(vases[2][0], day)
            continue
        if day <= 96:
            vases.sort(key=lambda x: (x[1], -x[0]))
            vase_id = vases[day - 95][0]
            last_vases.append([vase_id, see_vase(vase_id)])
            continue
        if day <= 99:
            last_vases.sort(key=lambda x: (x[1], -x[0]))
            last_vases[1][1] += 1
            put_token(last_vases[1][0], day)
            continue
        if day <= 100:
            last_vases.sort(key=lambda x: (x[1], -x[0]))
            put_token(last_vases[0][0], day)
