#http://codeforces.com/contest/6/problem/C
'''
Comment
'''

if __name__ == "__main__":
    n = int(input())
    bars = list(map(int, input().split()))

    ali = bob = 0;
    j = n
    i = -1

    while j - i > 1:
        if ali <= bob:
            i += 1
            ali += bars[i]
        else:
            j -= 1
            bob += bars[j]

    print(i + 1, n - j)