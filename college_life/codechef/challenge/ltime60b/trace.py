import numpy as np

n = 3
x = np.random.rand(n, n)
print(x)
slice_list = [slice(k, l) for k in range(0, n) for l in range(k, n)]

results = [x[sl,sl] for sl in slice_list]
