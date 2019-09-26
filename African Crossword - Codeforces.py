#https://codeforces.com/problemset/problem/90/B
'''
Comment
'''
maze = []
m = 0
n = 0

def check(x, y):
    for i in range(m):
        if maze[i][y] == maze[x][y] and i != x:
            return False
    
    for j in range(n):
        if maze[x][j] == maze[x][y] and j != y:
            return False

    return True

if __name__ == "__main__":
    m, n = map(int, input().split())
    res = ""

    for i in range(m):
        line = list(input())
        maze.append(line)

    for i in range(m):
        for j in range(n):
            if check(i, j):
                res += maze[i][j]

    print(res)
