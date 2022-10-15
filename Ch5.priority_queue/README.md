## 의사코드 정리
- 우선순위 큐를 이용한 정렬
```C
Alg PQ-Sort(L)
	input list L
	output sorted list L

1. P <- empty priority queue
2. while (!L.isEmpty())
		e <- L.removeFirst()
		P.insertItem(e)
3. while (!P.isEmpty())
		e <- P.removeMin()
		L.addLast(e)
4. return
```
- 제자리 선택 정렬
```C
Alg inPlaceSelectionSort(A)
	input array A of n keys
	output sorted array A

1. for pass <- 0 to n – 2
		minLoc <- pass
		for j <- (pass + 1) to n – 1
			if (A[j] < A[minLoc])
				minLoc <- j
		A[pass] <-> A[minLoc]
2. return
```
- 제자리 삽입 정렬
```C
Alg inPlaceInsertionSort(A)
	input array A of n keys
	output sorted array A

1. for pass <- 1 to n – 1
		save <- A[pass]
		j <- pass – 1
		while ((j >= 0) & (A[j] > save))
			A[j + 1] <- A[j]
			j <- j – 1
		A[j + 1] <- save
2. return
```
### 우선순위 큐란?
~~~
임의의 데이터 항목이 삽입되며, 일정한 순서에 의해 삭제되는 데이터구조
~~~
### 정렬
~~~
데이터 원소들을 일정한 키 순서에 의해 다시 배치하는 것
~~~
### 메쏘드
#### 주요 메쏘드
- insertItem(k, e) : 키 k인 원소 e를 큐에 삽입
- removeMin() : 큐로부터 최소 키를 가진 원소를 삭제하여 반환
#### 일반 메쏘드
- size() : 큐의 항목 수 반환
- isempty() : 큐가 비어 있는지 여부 반환
#### 접근 메쏘드
- minElement() : 큐에서 최소 키를 가진 원소 반환
- minKey() : 큐에서 최소 키를 반환
### 선택 정렬 vs 삽입 정렬
|우선순위 큐|작업 수행시간|정렬 방식|
|:--:|:--:|:--:|
|무순리스트|insertItem : O(1)/removeMin, minKey, minElement : O(n)|선택 정렬|
|순서리스트|insertItem : O(n)/removeMin, minKey, minElement : O(1)|삽입 정렬|
