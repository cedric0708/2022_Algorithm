# 의사코드 정리
## 무순 사전
- 선형탐색
```C
Alg findElement(k)	
	input list L, key k
	output element with key k

1. L.initialize(i)
2. while (L.isValid(i))
		if (L.key(i) = k)
			return L.element(i)
		else
			L.advance(i)
3. return NoSuchKey
```
## 순서 사전
```C
Alg findElement(k)		
	input list L, key k
	output element with key k

1. L.initialize(i)
2. while (L.isValid(i))
		if (L.key(i) = k)
			return L.element(i)
		elseif (L.key(i) > k)
			return NoSuchKey
		else
			L.advance(i)
3. return NoSuchKey
```
- 이진탐색
```C
Alg findElement(k)	
	input sorted array A[0..n–1], key k
	output element with key k

1. return rFindElement(k, 0, n – 1)
```
```C
Alg rFindElement(k, l, r)		
1. if (l > r)
		return NoSuchKey
2. mid <- (l + r)/2
3. if (k = key(A[mid]))
		return element(A[mid])
	elseif (k < key(A[mid]))
		return rFindElement(k, l, mid – 1)
	else {k > key(A[mid])}
		return rFindElement(k, mid + 1, r)
```
