# MatrixMultiplication 
This code clearly shows how the processor cache works
Let's look at two different ways to organize loops for matrix multiplication and why one of them might be faster.

**Loop order: first loop through i, then through k, then through j (as in the first code):**
```cpp
for (int i = 1; i < n; i++)
    for (int k = 0; k < n; k++)
        for (int j = 0; j < n; j++)
            result[i][j] += matrix1[i][k] * matrix2[k][j];
```
In this case, I iterate through the elements of matrix1 sequentially in rows and columns, 
then through the elements of matrix2. This order can promote data locality, which means that the data 
I access in the near future is stored in the processor's cache. This can speed up the execution of my code since the data 
I'm working with is usually already in the cache.

**Loop order: first loop through j, then through k, then through i (as in the second code):**
```cpp
for (int j = 1; j < n; j++)
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            result[i][j] += matrix1[i][k] * matrix2[k][j];
```
In this case, I iterate through the elements of matrix1 in a different order. This can result in less efficient use of caches since the data I'm accessing may be further apart in memory. This can cause cache misses when the processor must load data from slower RAM.

So, it is important to choose the optimal order of loop execution depending on the specific task and the hardware platform on which the code will be executed. In most cases, the first option will be more efficient due to better data locality and more efficient use of processor caches.
