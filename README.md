# Insertion_Sort
Insertion_Sort's Algorithm and the way how to make it

## Insertion Sort란?
- 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교하여, 자신의 위치를 찾아 삽입함으로써 정렬하는 알고리즘

<img src="https://upload.wikimedia.org/wikipedia/commons/e/ea/Insertion_sort_001.PNG"></img>

[출처] https://ko.wikipedia.org/wiki/%EC%82%BD%EC%9E%85_%EC%A0%95%EB%A0%AC

## Insertion Sort pseudocode

INSERTION-SORT (A, n)   ⊳A[1 . . n]  

    for j ←2 to n
  
      do key ←A[j]

        i ←j –1

        whilei > 0 and A[i] > key

          doA[i+1] ←A[i]

            i ←i –1

        A[i+1] = key
      
      
## Analysis
1. Worst-case
  - Time(n) = θ(n^2)
  - input size n만큼의 시간을 소요
2. Average-case
  - Time(n) = θ(n^2)
  - 알고리즘의 for문과 if문을 Worst-case의 절반만큼 소요
3. Best-case
  - 정렬된 input값이 들어오는 경우

