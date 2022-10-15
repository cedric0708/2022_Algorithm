# 의사코드 정리
## 교재 기준
### 힙 삽입
```C
Alg insertItem(k)
	input key k, node last
	output none

1. advanceLast() //last node 갱신
2. z <- last
3. Set node z to k //노드 z에 키 k 삽입
4. expandExternal(z) //z를 내부노드로 확장
5. upHeap(z) //힙 순서 복구
6. return
```
- 힙 순서 복구
```C
Alg upHeap(v)
	input node v
	output none

1. if (isRoot(v))
		return
2. if (key(v) >= key(parent(v)))
		return
3. swapElements(v, parent(v))
4. upHeap(parent(v))
```
- z 내부노드 확장
```C
Alg expandExternal(z)	
	input external node z
	output none

1. l <- getnode()
2. r <- getnode()
3. l.left <- NULL
4. l.right <- NULL
5. l.parent <- z
6. r.left <- NULL
7. r.right <- NULL
8. r.parent <- z
9. z.left <- l
10. z.right <- r
11. return
```
### 힙 삭제
```C
Alg removeMin()
	input node last
	output key

1. k <- key(root())
2. w <- last
3. Set root to key(w)
4. retreatLast() //last node 갱신
5. z <- rightChild(w)
6. reduceExternal(z) //z를 외부노드로 축소
7. downHeap(root()) //힙 순서 복구
8. return k
```
- 힙 순서 복구
```C
Alg downHeap(v)
	input node v whose left and right subtrees are heaps
	output a heap with root v
1. if(isExternal(leftChild(v)) & isExternal(rightChild(v))
	return
2. smaller <- leftChild(v)
3. if(isInternal(rightChild(v))
	if(key(rightChild(v)) < key(smaller))
		smaller <- rightChild(v)
4. if(key(v) <= key(smaller))
	return
5. swapElements(v, smaller)
6. downHeap(smaller)
```
- 외부노드 축소
```C
Alg reduceExternal(z) 	
	input external node z
	output the node replacing the parent node of the removed node z

1. w <- z.parent
2. zs <- sibling(z)
3. if (isRoot(w))
		root <- zs		
		zs.parent <- NULL
	else
		g <- w.parent
		zs.parent <- g
		if (w = g.left)
			g.left <- zs
		else {w = g.right}
			g.right <- zs
4. putnode(z)			
5. putnode(w)			
6. return zs
```
