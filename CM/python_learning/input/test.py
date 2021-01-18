## in py3
'''
input() read a line and return a string
using map function in py3 returns a iterator and use function next() to handle it. Also you can handle it with for loop.
# in py2 map returns a list consists of the result of each element performed by the function.
'''
c = map(int, input().split())
a = []
for i in c:
    a.append(i)
    print(a)
print(a[0])
for i in a:
    print(i)
