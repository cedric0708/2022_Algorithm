# 의사코드 정리
## 교재 기준
### 이진 탐색 트리
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
	input binary search tree T, key k, element e
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
## 실습문제 기준
```C
Alg isExternal(w)
	input node w
	ouput boolean
1. if (w.left = NULL & w.right = NULL)
	return True
   else 
        return False
```
```C
Alg isInternal(w)
	input node w
	output boolean
1. if (w.left != NULL or w.right != NULL)
	return True
   else 
   	return False
```
```C
Alg sibling(w)
	input node w
	output sibling of w
1. if (isRoot(w))
	invalidNodeException()
2. if(leftChild(parent(w)) = w)
	return rightChild(parent(w))
   else
        return leftChild(parent(w))
```
```C
Alg inOrderSucc(w)
	input internal node w
	output inorder successor of w
1. w <- rightChild(w)
2. if(isExternal(w))
	invalidNodeException()
3. while (isInternal(leftChild(w)))
	w <- leftChild(w)
4. return w
```
```C
Alg reduceExternal(z)
	input external node z
	output the node replacing the parent node of the removed node z

1. w <- z.parent
2. zs <- sibling(z)
3. if(isRoot(w))
	root <- zs
	zs.parent <- NULL
   else
   	g <- w.parent
	zs.parent <- g
	if (w = g.left)
		g.left <- zs
	else
		g.right <- zs
4. putnode(z)
5. putnode(w)
6. return zs
```
