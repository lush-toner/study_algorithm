"""
2021-01-20 시간복잡도 python 계산 
O(N)
10개의 데이터를 받아 차례로 10회 더하는 과정
이것이 취업을 위한 코딩 테스트다 with 파이썬 참고
"""
array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
sum = 0

for i in array:
    sum += i

print(sum)