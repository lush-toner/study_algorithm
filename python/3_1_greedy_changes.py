"""
2021-02-08 greedy algorithm
1260원을 500원 100원 50원 10원으로 거스름돈으로 나눠 줄 때
거슬러줘야할 동전의 최소 개수를 구하라
"""

n = 1260
count = 0

array = [500, 100, 50, 10]


for coin in array: # 동전을 하나씩 불러와서
    count += n // coin # 금액으로 나눈 몫을 더하고
    n %= coin # 나머지를 다시 n으로 계산한다.

print(count)