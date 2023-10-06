def find_testable_laptops(n, battery):
    time = 0

    for i in range(n):
        if battery[i] - time <= 0:
            return i + 1  # Return the laptop number that can be tested
        else:
            time += 1

    return -1  # Return -1 if no laptop can be tested

# Example usage:
n = 5
battery = [2, 1, 2, 3, 4]
result = find_testable_laptops(n, battery)
print(result) # Output: 1