import heapq

n, m = map(int, input().split())
nums = list(map(int, input().split()))
heapq.heapify(nums)

for _ in range(m):
    num1 = heapq.heappop(nums)
    num2 = heapq.heappop(nums)
    heapq.heappush(nums, num1 + num2)
    heapq.heappush(nums, num1 + num2)

print(sum(nums))