"""
2021-02-08 예제 3-2 큰 수의 법칙 문제 python 계산 
이것이 취업을 위한 코딩 테스트다 with 파이썬 참고
"""

n, m, k = map(int, input().split())
# N개의 수를 공백으로 구분하여 입력을 받는다.
data = list(map(int, input().split()))

data.sort()
first = data[n-1] # 제일 큰 수
second = data[n-2] # 두 번째 큰 수

count = int(m/(k+1)) * k # 반복
count += m % (k+1) # 나머지 만큼 추가

result = 0
result += (count) * first # 가장 큰 수
result += (m-count) * second # 두 번쨰로 큰 수

print(result)