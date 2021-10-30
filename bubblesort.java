import java.util.Arrays;
import java.util.Stack;

public class Test {
    // Method for bubble sort using Stack
    static void bubbleSortStack(int arr[], int n) {
        Stack<Integer> s1 = new Stack<>();

        // Push all elements of array in 1st stack
        for (int num : arr)
            s1.push(num);

        Stack<Integer> s2 = new Stack<>();

        for (int i = 0; i < n; i++) {
            // alternatively
            if (i % 2 == 0) {
                while (!s1.isEmpty()) {
                    int t = s1.pop();

                    if (s2.isEmpty())
                        s2.push(t);
                    else {
                        if (s2.peek() > t) {
                            // swapping
                            int temp = s2.pop();
                            s2.push(t);
                            s2.push(temp);
                        } else {
                            s2.push(t);
                        }
                    }
                }

                // tricky step
                arr[n - 1 - i] = s2.pop();
            } else {
                while (!s2.isEmpty()) {
                    int t = s2.pop();

                    if (s1.isEmpty())
                        s1.push(t);

                    else {
                        if (s1.peek() > t) {
                            // swapping
                            int temp = s1.pop();

                            s1.push(t);
                            s1.push(temp);
                        } else
                            s1.push(t);
                    }
                }

                // tricky step
                arr[n - 1 - i] = s1.pop();
            }
        }
        System.out.println(Arrays.toString(arr));
    }

    // Driver Method
    public static void main(String[] args) {
        int arr[] = { 15, 12, 44, 2, 5, 10 };
        bubbleSortStack(arr, arr.length);
    }
}