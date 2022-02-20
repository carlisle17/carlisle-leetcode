// 递归方法：时间复杂度较高，多次重复计算

class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        return fib(n - 1) + fib(n - 2);
    }
};


// 动态规划：由于前面计算的数值已确定，在后面不会被改变，所以可以采用该方法；其时间复杂度为O(n)，空间复杂度为O(1)。

class Solution {
public:
    int fib(int n) {
        if(n < 2) return n;
        int left = 0, right = 1;
        for(int i = 2; i <= n; ++i){
            int sum = left + right;
            left = right;
            right = sum;
        }
        return right;
    }
};
