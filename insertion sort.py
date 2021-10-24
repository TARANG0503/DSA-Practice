def insertionSort(arr):

    for i in range(1, len(arr)):

        key = arr[i]


        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

if __name__ == '__main__':
    x = input("enter the array elements")
    ls = [int(x) for x in x.split(" ")]
    # x = x.split(" ")
    print(ls)
    insertionSort(ls)
    print(ls)

