import math

t = int(input())  # Read the number of test cases

for _ in range(t):
    # Read the number of branches, base length, and height of branches
    n, d, h = map(int, input().split())
    # Read the heights of the bases of the branches
    heights = list(map(int, input().split()))

    max_area = 0.5*d*h  # Initialize the maximum area

    # Calculate the area for each branch
    for i in range(n):
        height_diff = heights[i] - max_area * (d / (2 * h))
        max_area = max(max_area, (heights[i] - height_diff) * (d / 2))

    print(max_area)  # Print the total area of the tree branches for each test case
