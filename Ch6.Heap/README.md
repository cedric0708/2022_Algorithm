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
### 힙 정렬
```C
Alg heapSort(L)
	input list L
	output sorted list L

1. H <- empty heap
2. while (!L.isEmpty())	
		k <- L.removeFirst()
		H.insertItem(k)
3. while (!H.isEmpty())	
		k <- H.removeMin()
		L.addLast(k)
4. return
```
- 제자리 힙 정렬
```C
Alg inPlaceHeapSort(A)
	input array A of n keys
	output sorted array A

1. buildHeap(A)			
2. for i <- n downto 2	
		A[1] <-> A[i]
		downHeap(1, i – 1)
3. return
```
```C
Alg buildHeap(A)
	input array A of n keys
	output heap A of size n

1. for i <- 1 to n
		insertItem(A[i])
2. return
```
```C
Alg downHeap(i, last)
	input index i of array A representing a maxheap of size last
	output none

1. left <- 2i
2. right <- 2i + 1
3. if (left > last)			
		return
4. greater <- left
5. if (right <= last)
		if (key(A[right]) > key(A[greater]))
			greater <- right
6. if (key(A[i]) >= key(A[greater]))
		return
7. A[i] <-> A[greater]
8. downHeap(greater, last)
```
### 상향식 힙 생성
- 재귀적 상향식 힙 생성
```C
Alg buildHeap(L)
	input list L storing n keys
	output heap T storing the keys in L

1. T <- convertToCompleteBinaryTree(L)
2. rBuildHeap(T.root())
3. return T
```
```C
Alg rBuildHeap(v)			
	input node v
	output a heap with root v

1. if (isInternal(v))
		rBuildHeap(leftChild(v))
		rBuildHeap(rightChild(v))
		downHeap(v)
2. return
```
- 비재귀적 상향식 힙 생성
```C
Alg buildHeap(A)
	input array A of n keys
	output heap A of size n

1. for i <- n/2 downto 1
		downHeap(i, n)
2. return
```
## 실습문제 기준
- 힙 삽입
```C
Alg insertItem(key) {힙 삽입}
	input integer key {key: 삽입 키}, array H {H: 전역 배열, heap}
	output array H {H: 전역 배열, heap}
1. n ← n + 1 {n 갱신}
2. H[n] ← key {힙에 초기 삽입 위치는 n}
3. upHeap(n) {힙 조정}
4. return
```
- 힙 삭제
```C
Alg removeMax() {힙 삭제}
	input array H {H: 전역 배열, heap}
	output array H {H: 전역 배열, heap}
1. key ← H[1] {루트 키 보관}
2. H[1] ← H[n] {힙의 마지막 키를 루트로 이동}
3. n ← n – 1 {n 갱신}
4. downHeap(1) {힙 조정}
5. return key {삭제 키 반환}
```
- 재귀적 상향식 힙 생성
```C
Alg rBuildHeap(i) {힙 생성 - 재귀 버전}
	input integer i {i: 현재 부트리의 루트 인덱스}, array H {H: 전역 배열, non-heap}
	output array H {H: 전역 배열, heap}
1. if (i > n) {n: 전역 변수}
	return
2. rBuildHeap(2i) {현재 부트리의 좌 부트리를 힙 생성}
3. rBuildHeap(2i + 1) {현재 부트리의 우 부트리를 힙 생성}
4. downHeap(i) {현재 부트리의 루트와 좌우 부트리를 합친 힙 생성}
5. return
```
- 비재귀적 상향식 힙 생성
```C
Alg buildHeap() {힙 생성 - 비재귀 버전}
	input array H {H: 전역 배열, non-heap}
	output array H {H: 전역 배열, heap}
1. for i ← n/2 downto 1 {n: 전역 변수, 마지막 내부노드부터 역방향으로 루트까지}
downHeap(i)
2. return
```
