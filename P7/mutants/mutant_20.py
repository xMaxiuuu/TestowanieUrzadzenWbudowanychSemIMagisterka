def bubble_sort(arr):
    data = list(arr)
    n = len(data)
    for i in range(n):
        for j in range(1, n - i - 1):
            if data[j] > data[j + 1]:
                data[j], data[j + 1] = data[j + 1], data[j]
    return data