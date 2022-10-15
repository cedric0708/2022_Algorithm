## 의사코드 정리
### 교재 기준
- 힙 삽입
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
