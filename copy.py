import copy

a = [1, 2, 3]
b = [4, 5, 6]
c = [a, b]
d = c
e = list(c)
f = c[:]
g = copy.copy(c)
h = copy.deepcopy(c)
print("id(c):{} ".format(id(c)))
print("id(d):{} ".format(id(d)))
print("id(e):{} ".format(id(e)))
print("id(f):{} ".format(id(f)))
print("id(g):{} ".format(id(g)))
print("id(h):{} ".format(id(h)))

print("-"*20)

a.append(99)
print("c: ", c)
print("d: ", d)
print("e: ", e)
print("f: ", f)
print("g: ", g)
print("h: ", h)

print("-"*20)

print("id(a):{} ".format(id(a)))
print("id(c[0]):{} ".format(id(c[0])))
print("id(d[0]):{} ".format(id(d[0])))
print("id(e[0]):{} ".format(id(e[0])))
print("id(f[0]):{} ".format(id(f[0])))
print("id(g[0]):{} ".format(id(g[0])))
print("id(h[0]):{} ".format(id(h[0])))
