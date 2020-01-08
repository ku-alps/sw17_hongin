import copy

R, C = map(int, input().split())
arr = [['#' for c in range(C)] for r in range(R)]
for r in range(R):
    line = input()
    for c in range(C):
        arr[r][c] = line[c]
        if arr[r][c] == 'F':
            fc = c 
            fr = r
        elif arr[r][c] == 'J':
            jc = c
            jr = r

def show(arr):
    for r in range(R):
        for c in range(C):
            print(arr[r][c], end='')
        print()

def target(arr, r, c):
    coord = []
    if arr[r][c-1] == '.':
       coord.append((r, c-1))
    if arr[r][c+1] == '.':
       coord.append((r, c+1))
    if arr[r-1][c] == '.':
       coord.append((r-1, c))
    if arr[r+1][c] == '.':
       coord.append((r+1, c))
    return coord

q = []
nextfire = target(arr, fr, fc)
q.append((jr, jc, arr, nextfire))
while q:
    (jr, jc, arr, fire) = q.pop()
    run = target(arr, jr, jc)
    arr[jr][jc] = '.'
    
    for (r, c) in fire:
        arr[r][c] = 'F'
    nextfire = []
    for (r, c) in fire:
        nextfire.append(target(arr, r, c))
    for (r, c) in run:
        q.append((r, c, arr, nextfire))
    show(arr)
