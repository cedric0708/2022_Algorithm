# 의사코드 정리
## 이진 탐색 트리
- 탐색
```C
Alg findElement(k)
	input binary search tree T, key k
	output element with key k

1. w <- treeSearch(root(), k)
2. if (isExternal(w))
		return NoSuchKey
	else
		return element(w)
```
```C
Alg treeSearch(v, k)			
	input node v of a binary search tree, key k
	output node w, s.t. either w is an internal node storing key k or w is the external node where key k would belong if it existed

1. if (isExternal(v))
		return v
2. if (k = key(v))
		return v
	elseif (k < key(v))
		return treeSearch(leftChild(v), k)
	else {k > key(v)}
		return treeSearch(rightChild(v), k)
```
- 삽입
```C
Alg insertItem(k, e)
	input binary search tree T,	key k, element e
	output none

1. w <- treeSearch(root(), k)
2. if (isInternal(w))
		return
	else
		Set node w to (k, e)
		expandExternal(w)
		return
```
- 삭제
```C
Alg removeElement(k)
	input binary search tree T, key k
	output element with key k

1. w <- treeSearch(root(), k)
2. if (isExternal(w))
		return NoSuchKey
3. e <- element(w)
4. z <- leftChild(w)
5. if (!isExternal(z))
		z <- rightChild(w)
6. if (isExternal(z))		
		reduceExternal(z)
	else						
		y <- inOrderSucc(w)
		z <- leftChild(y)
		Set node w to (key(y), element(y))
		reduceExternal(z)
7. return e
```
