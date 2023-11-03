def min_moves_to_all_ones(binary_string, k):
    moves = 0
    n = len(binary_string)

    for i in range(n):
        if binary_string[i] == '0':
            moves += 1
            for j in range(i, n, k):
                if binary_string[j] == '1':
                    break
                binary_string = binary_string[:j] + '1' + binary_string[j + 1:]

    return moves


# Example usage:
binary_string = "1010"
k = 2
min_moves = min_moves_to_all_ones(binary_string, k)
print("Minimum moves to make all bits 1:", min_moves)
