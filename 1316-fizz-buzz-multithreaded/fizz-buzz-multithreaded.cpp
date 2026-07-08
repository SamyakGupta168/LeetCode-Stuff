using namespace std;

class FizzBuzz {
private:
    int n;
    mutex m;
    condition_variable cv;
    int value;

public:
    FizzBuzz(int n) {
        this->n = n;
        value = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
        unique_lock<mutex> lock(m);

        cv.wait(lock, [&] {
            return value > n ||
                   (value % 3 == 0 && value % 5 != 0);
        });

        if (value > n)
            return;

        printFizz();
        value++;

        cv.notify_all();
    }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
        unique_lock<mutex> lock(m);

        cv.wait(lock, [&] {
            return value > n ||
                   (value % 5 == 0 && value % 3 != 0);
        });

        if (value > n)
            return;

        printBuzz();
        value++;

        cv.notify_all();
    }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {

        while (true) {
        unique_lock<mutex> lock(m);

        cv.wait(lock, [&] {
            return value > n ||
                   (value % 15 == 0);
        });

        if (value > n)
            return;

        printFizzBuzz();
        value++;

        cv.notify_all();
    }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true) {
        unique_lock<mutex> lock(m);

        cv.wait(lock, [&] {
            return value > n ||
                   (value % 3 != 0 && value % 5 != 0);
        });

        if (value > n)
            return;

        printNumber(value);
        value++;

        cv.notify_all();
    }
    }
};