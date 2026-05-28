class Solution {
public:
    int fib(int n) {
           if (n == 0) return 0;
    if (n == 1) return 1;
    
    // Limit to prevent large numbers (optional)
    if (n > 30) return -1; // Return -1 to indicate invalid input

    // Recursive calls
    int last = fib(n - 1);
    int slast = fib(n - 2);
    return last + slast;
    }
};