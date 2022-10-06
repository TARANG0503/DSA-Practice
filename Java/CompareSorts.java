/* [CompareBubbleSelection.java]
 * This program is a template for a comparing sorting algorithms
 * Random numbers are generated and tested with various sorting algorithms
 */

import java.util.Random;
import java.util.Arrays;

class CompareSorts {

    /**
     * Main method *******************************************
     * 
     * @param arguements
     */
    public static void main(String[] args) {

        int data[] = generateNumberArray(10);
        int[] tempArray; // a temp holder for data as it is passed to methods
        long startTime, endTime;
        double elapsedTime;

        System.out.println("Array generated: ");
        displayArray(data);

        // Testing Selection Sort -----------------
        System.out.println("\nSorting with Selection sort:");
        tempArray = Arrays.copyOf(data, data.length); // to keep original arrays safe from modification
        startTime = System.nanoTime(); // start time

        tempArray = selectionSort(tempArray);

        endTime = System.nanoTime(); // end time
        elapsedTime = (endTime - startTime) / 1000000.0;

        displayArray(tempArray);
        System.out.println("The sort took: " + elapsedTime + "ms");

        // Testing Bubble Sort -----------------
        System.out.println("\nSorting with Bubble sort:");
        tempArray = Arrays.copyOf(data, data.length); // to keep original arrays safe from modification
        startTime = System.nanoTime(); // start time

        tempArray = bubbleSort(tempArray);

        endTime = System.nanoTime(); // end time
        elapsedTime = (endTime - startTime) / 1000000.0;

        displayArray(tempArray);
        System.out.println("The sort took: " + elapsedTime + "ms");

        // Testing Insertion Sort -----------------
        System.out.println("\nSorting with Insertion sort:");
        tempArray = Arrays.copyOf(data, data.length); // to keep original arrays safe from modification
        startTime = System.nanoTime(); // start time

        tempArray = insertionSort(tempArray);

        endTime = System.nanoTime(); // end time
        elapsedTime = (endTime - startTime) / 1000000.0;

        displayArray(tempArray);
        System.out.println("The sort took: " + elapsedTime + "ms");

        // Testing Merge Sort -----------------
        System.out.println("\nSorting with Merge sort:");
        tempArray = Arrays.copyOf(data, data.length); // to keep original arrays safe from modification
        startTime = System.nanoTime(); // start time

        tempArray = mergeSort(tempArray);

        endTime = System.nanoTime(); // end time
        elapsedTime = (endTime - startTime) / 1000000.0;

        displayArray(tempArray);
        System.out.println("The sort took: " + elapsedTime + "ms");

        // Testing Quick Sort -----------------
        System.out.println("\nSorting with Quick sort:");
        tempArray = Arrays.copyOf(data, data.length); // to keep original arrays safe from modification
        startTime = System.nanoTime(); // start time

        tempArray = quickSort(tempArray);

        endTime = System.nanoTime(); // end time
        elapsedTime = (endTime - startTime) / 1000000.0;

        displayArray(tempArray);
        System.out.println("The sort took: " + elapsedTime + "ms");

        // Testing Arrays.sort -----------------
        System.out.println("\nSorting with Arrays.sort sort:");
        tempArray = Arrays.copyOf(data, data.length); // to keep original arrays safe from modification
        startTime = System.nanoTime(); // start time

        tempArray = javaBuiltInSort(tempArray);

        endTime = System.nanoTime(); // end time
        elapsedTime = (endTime - startTime) / 1000000.0;

        displayArray(tempArray);
        System.out.println("The sort took: " + elapsedTime + "ms");

    } // end of main method

    /**
     * generateNumberArray *******************************************
     * Creates a random array on integers
     * 
     * @param size of array
     * @return the generated integer array
     */
    public static int[] generateNumberArray(int numOfElements) {

        int[] generated = new int[numOfElements];

        // add unique numbers into array in order
        for (int i = 0; i < generated.length; i++)
            generated[i] = i;

        // shuffle the numbers randomly
        Random randomNumber = new Random();
        for (int i = 0; i < generated.length; i++) {
            // swap to random positions
            int temp;
            int first = randomNumber.nextInt(generated.length);
            int second = randomNumber.nextInt(generated.length);
            temp = generated[first];
            generated[first] = generated[second];
            generated[second] = temp;
        }

        return generated;
    } // end of generateNumberArray

    /**
     * displayArray *******************************************
     * Sorts a random array on integers using selection sort
     * 
     * @param the integer array
     */
    public static void displayArray(int[] numbers) {
        for (int i = 0; i < numbers.length; i++) {
            System.out.print(numbers[i] + " ");
        }
        System.out.println("");
    }

    /**
     * selectionSort *******************************************
     * Sorts a random array on integers using selection sort
     * 
     * @param the unsorted integer array
     * @return the sorted integer array
     */
    public static int[] selectionSort(int[] numbers) {
        for (int i = 0; i < numbers.length; ++i) {
            int smallestNumber = numbers[i];
            int indexToSwitch = i;
            for (int j = i; j < numbers.length; ++j) {
                if (smallestNumber > numbers[j]) {
                    indexToSwitch = j;
                    smallestNumber = numbers[j];
                }
            }
            int temp = numbers[i];
            numbers[i] = numbers[indexToSwitch];
            numbers[indexToSwitch] = temp;
        }
        return numbers;
    }

    /**
     * bubbleSort *******************************************
     * Sorts a random array on integers using bubble sort
     * 
     * @param the unsorted integer array
     * @return the sorted integer array
     */
    public static int[] bubbleSort(int[] numbers) {
        for (int i = 0; i < numbers.length; ++i) {
            for (int j = 0; j < numbers.length; ++j) {
                if (numbers[j] > numbers[i]) {
                    int largerNumber = numbers[j];
                    numbers[j] = numbers[i];
                    numbers[i] = largerNumber;
                }
            }
        }
        return numbers;
    }

    /**
     * insertionSort *******************************************
     * Sorts a random array on integers using insertion sort
     * 
     * @param the unsorted integer array
     * @return the sorted integer array
     */
    public static int[] insertionSort(int[] numbers) {
        for (int i = 1; i < numbers.length; ++i) {
            for (int j = i; j >= 1; --j) {
                if (numbers[j - 1] > numbers[j]) {
                    int temp = numbers[j - 1];
                    numbers[j - 1] = numbers[j];
                    numbers[j] = temp;
                }
            }
        }
        return numbers;
    }

    /**
     * mergeSort *******************************************
     * Sorts a random array on integers using merge sort
     * 
     * @param the unsorted integer array
     * @return the sorted integer array
     */
    public static int[] mergeSort(int[] numbers) {
        msRecursive(numbers, 0, numbers.length - 1);
        return numbers;
    }

    private static void msRecursive(int[] numbers, int start, int end) {
        if (end <= start) {
            return;
        }

        int mid = (start + end) / 2;
        msRecursive(numbers, start, mid);
        msRecursive(numbers, mid + 1, end);
        mergeArray(numbers, start, end);
    }

    private static void mergeArray(int[] numbers, int start, int end) {
        int mid = (start + end) / 2;
        int[] left = new int[mid - start + 1];
        int[] right = new int[end - mid];
        int leftI = 0;
        int rightI = 0;

        // Copying array halves to temp arrays
        System.arraycopy(numbers, start, left, 0, left.length);
        System.arraycopy(numbers, mid + 1, right, 0, right.length);

        // Merging and sorting
        for (int i = start; i < end + 1; ++i) {
            // If both the left and right indexes have not been copied yet
            if (leftI < left.length && rightI < right.length) {
                // Check for which value is smaller
                if (left[leftI] < right[rightI]) {
                    numbers[i] = left[leftI];
                    leftI++;
                } else {
                    numbers[i] = right[rightI];
                    rightI++;
                }
                // Copying the rest of the arrays to the main array (already sorted)
            } else if (leftI < left.length) {
                numbers[i] = left[leftI];
                leftI++;
            } else if (rightI < right.length) {
                numbers[i] = right[rightI];
                rightI++;
            }
        }
    }

    /**
     * quickSort *******************************************
     * Sorts a random array on integers using quick sort
     * 
     * @param the unsorted integer array
     * @return the sorted integer array
     */
    public static int[] quickSort(int[] numbers) {
        qsRecursive(numbers, 0, numbers.length - 1);
        return numbers;
    }

    private static void qsRecursive(int[] numbers, int start, int end) {
        if (end > start) {
            int p = partition(numbers, start, end);
            qsRecursive(numbers, start, p - 1);
            qsRecursive(numbers, p + 1, end);
        }
    }

    private static int partition(int[] numbers, int start, int end) {
        // Find pivots
        int pivotIndex = ((end + start) / 2);
        int pivotNum = numbers[pivotIndex];

        // Swap pivot with end
        numbers[pivotIndex] = numbers[end];
        numbers[end] = pivotNum;

        // Partitioning the array (i is pivot index)
        int i = 0;
        for (int j = 0; j < end; j++) {
            if (numbers[j] <= pivotNum) {
                if (i != j) {
                    int temp = numbers[j];
                    numbers[j] = numbers[i];
                    numbers[i] = temp;
                }
                i++;
            }
        }

        // Swap last index (pivot) with i (new pivot index)
        int temp = numbers[i];
        numbers[i] = pivotNum;
        numbers[end] = temp;
        return i;
    }

    /**
     * javaBuiltInSort *******************************************
     * Sorts a random array on integers using Arrays.sort
     * 
     * @param the unsorted integer array
     * @return the sorted integer array
     */
    public static int[] javaBuiltInSort(int[] numbers) {
        Arrays.sort(numbers); // sort
        return numbers;
    }
}