'''
py3
list.sort( key=None, reverse=False )
False --> rising order
key --> a function to get the key by element, a rule of mapping.

python has no operator ++
but has operator +=

python no list 不需要元素类型一致

range(start, stop[, step])
'''
n, k = map(int, input().strip().split())
a = []
for i in range(0, n):
    a.append(int(input()))
a.sort()
mx = []
rm = []
r = 0
for i in range(0, n):
    while r < n - 1 and a[r+1] - a[i] <= k:
        r += 1
    mx.append((r - i + 1, r))
    rm.append(0)
rm[n-1] = 0
for i in range(n-2, -1, -1):
    rm[i] = max(rm[i+1], mx[i][0])
ans = 0
for i in range(0, n):
    if(mx[i][1]+1 < n):
        ans = max(ans, mx[i][0] + rm[mx[i][1]+1])
    else:
        ans = max(ans, mx[i][0])
print(ans)
