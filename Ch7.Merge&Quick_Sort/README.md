# 의사코드 정리
## 합병 정렬
```C
Alg mergeSort(L)
	input list L with n elements
	output sorted list L

1. if (L.size() > 1)
		L1, L2 <- partition(L, n/2)
		mergeSort(L1)
		mergeSort(L2)
		L <- merge(L1, L2)
2. return
```
- 합병
```C
Alg merge(L1, L2)
	input sorted list L1 and L2 with n/2 elements each
	output sorted list of L1∪L2

1. L <- empty list
2. while (!L1.isEmpty() & !L2.isEmpty())
		if (L1.get(1) ≤ L2.get(1))
			L.addLast(L1.removeFirst())
		else
			L.addLast(L2.removeFirst())
3. while (!L1.isEmpty())
		L.addLast(L1.removeFirst())
4. while (!L2.isEmpty())
		L.addLast(L2.removeFirst())
5. return L
```
- 배열에 대한 합병 정렬
```C
Alg mergeSort(A)
	input array A of n keys
	output sorted array A

1. rMergeSort(A, 0, n – 1)
2. return
```
```C
Alg rMergeSort(A, l, r)
	input array A[l..r]
	output sorted array A[l..r]

1. if (l < r)
		m <- (l + r)/2
		rMergeSort(A, l, m)
		rMergeSort(A, m + 1, r)
		merge(A, l, m, r)
2. return
```
```C
Alg merge(A, l, m, r)
	input sorted array A[l..m], A[m+1..r]
	output sorted array A[l..r] merged from A[l..m] and A[m+1..r]

1. i, k <- l
2. j <- m + 1
3. while (i ≤ m & j ≤ r)
		if (A[i] ≤ A[j])
			B[k++] <- A[i++]
		else
			B[k++] <- A[j++]
4. while (i ≤ m)
		B[k++] <- A[i++]
5. while (j ≤ r)
		B[k++] <- A[j++]
6. for k <- l to r
		A[k] <- B[k]
7. return
```
## 퀵 정렬
```C
Alg quickSort(L)
	input list L with n elements
	output sorted list L

1. if (L.size() > 1)
		k <- a position in L
		LT, EQ, GT <- partition(L, k)
		quickSort(LT)
		quickSort(GT)
		L <- merge(LT, EQ, GT)
2. return
```
- 분할
```C
Alg partition(L, k)
	input list L with n elements, position k of pivot
	output sublists LT, EQ, GT of the elements of L, less than, equal to, or greater than pivot, resp.

1. p <- L.get(k)		
2. LT, EQ, GT <- empty list
3. while (!L.isEmpty())
		e <- L.removeFirst()
		if (e < p)
			LT.addLast(e)
		elseif (e = p)
			EQ.addLast(e)
		else {e > p}
			GT.addLast(e)
4. return LT, EQ, GT
```
- 제자리 퀵 정렬
```C
Alg inPlaceQuickSort(L, l, r)
	input list L, position l, r
	output list L with elements of position from l to r rearranged in increasing order

1. if (l >= r)
		return
2. k <- a position between l and r
3. a, b <- inPlacePartition(L, l, r, k)
4. inPlaceQuickSort(L, l, a – 1)
5. inPlaceQuickSort(L, b + 1, r)
```
```C
Alg inPlacePartition(A, l, r, k)
	input array A[l..r] of distinct elements, index l, r, k
	output final index of the pivot resulting from partitioning A[l..r] into LT, pivot, GT

1. p <- A[k]			{pivot}
2. A[k] <-> A[r]		{hide pivot}
3. i <- l
4. j <- r – 1
5. while (i ≤ j)
		while (i ≤ j & A[i] ≤ p)
			i <- i + 1
		while (j >= i & A[j] >= p)
			j <- j – 1
		if (i < j)
			A[i] <-> A[j]
6. A[i] <-> A[r]
7. return i		 {index of pivot}
```
