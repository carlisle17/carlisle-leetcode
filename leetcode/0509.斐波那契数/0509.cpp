// 递归方法：最终情况时退出递归，正常情况下进入递归
// 时间复杂度为，多次计算了不必要计算的数值

class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        return fib(n - 1) + fib(n - 2);
    }
};


// 动态规划：由于前面计算的数值已确定，在后面不会被改变，所以可以采用该方法
// 时间复杂度为O(n)，空间复杂度为O(1)，由于每个数仅和前面两个数有关，所以可以采用两个数值替代动态数组

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
