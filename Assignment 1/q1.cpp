#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

// recursion
long long fib_recursive(int n) {
    if (n <= 1)
        return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

void printFibonacciRecursive(int n) {
    for (int i = 0; i < n; i++) {
        cout << fib_recursive(i) << " ";
    }
    cout << endl;
}

// loop
long long fib_loop(int n) {
    long long a = 0, b = 1, c;
    if (n == 0)
        return a;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

void printFibonacciLoop(int n) {
    for (int i = 0; i < n; i++) {
        cout << fib_loop(i) << " ";
    }
    cout << endl;
}

// recursion with memo
vector<long long> memo;

long long fib_recursive_memo(int n) {
    if (memo[n] != -1)
        return memo[n];
    if (n <= 1)
        return n;
    memo[n] = fib_recursive_memo(n - 1) + fib_recursive_memo(n - 2);
    return memo[n];
}

void printFibonacciRecursiveMemo(int n) {
    memo.assign(n, -1);
    for (int i = 0; i < n; i++) {
        cout << fib_recursive_memo(i) << " ";
    }
    cout << endl;
}

// loop with memo
long long fib_loop_memo(int n) {
    vector<long long> fib(n + 1, 0);
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

void printFibonacciLoopMemo(int n) {
    for (int i = 0; i < n; i++) {
        cout << fib_loop_memo(i) << " ";
    }
    cout << endl;
}

// time measurement
long long measureTime(long long (*func)(int), int n) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    func(n);
    clock_gettime(CLOCK_MONOTONIC, &end);

    long long duration = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    return duration;
}

int main() {
    const int n = 40;

    // time for each
    long long timeRec = measureTime(fib_recursive, n);
    long long timeLoop = measureTime(fib_loop, n);
    long long timeRecMemo = measureTime(fib_recursive_memo, n);
    long long timeLoopMemo = measureTime(fib_loop_memo, n);

    // print times
    cout << "Time (recursion): " << timeRec << " ns" << endl;
    cout << "Time (loop): " << timeLoop << " ns" << endl;
    cout << "Time (recursion + memoization): " << timeRecMemo << " ns" << endl;
    cout << "Time (loop + memoization): " << timeLoopMemo << " ns" << endl;

    // Calculate speedups
    cout << "Speedup (loop vs recursion): " << (double)timeRec / timeLoop << endl;
    cout << "Speedup (recursion + memoization vs recursion): " << (double)timeRec / timeRecMemo << endl;
    cout << "Speedup (loop + memoization vs recursion): " << (double)timeRec / timeLoopMemo << endl;

    return 0;
}
