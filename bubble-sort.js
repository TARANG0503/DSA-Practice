function bubbleSort(arr) {
  for (const i = 0; i < arr.length; i++) {
    for (const j = 0; j < arr.length - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        const temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  console.log(arr);
}

const arr = [234, 43, 55, 63, 5, 6, 235, 547];
bubbleSort(arr);
