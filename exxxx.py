import numpy as np
def convolution(k, data):
    n,m = data.shape
    img_new = []
    for i in range(n-2):
        line = []
        for j in range(m-2):
            a = data[i:i+3,j:j+3]
            line.append(np.sum(np.multiply(k, a)))
        img_new.append(line)
        print(line)
    return np.array(img_new)
k=np.array([[5,1,8],[4,3,1],[9,6,2]])
data=np.array([[3,8,2,9],[1,5,4,8],[2,7,4,6],[6,4,2,1]])
res=convolution(k,data)
print(res)

