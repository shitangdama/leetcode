# 注意深拷贝问题
a = []
b = [1]
a.append(b)
b.pop()
print(a)
