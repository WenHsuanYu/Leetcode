// Using atomic variable, condition variable and mutex
// TC: O(1)
// SC: O(1)
class Foo {
private:
    atomic<int> turn = 1;
    mutex m;
    condition_variable cv;
    
public:
    
    Foo() {

    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> um(m);
        // printFirst() outputs "first". Do not change or remove this line.
        cv.wait(um, [&](){
            return turn == 1;
        });
        printFirst();
        turn = 2;
        cv.notify_all();
        
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> um(m);
        // printSecond() outputs "second". Do not change or remove this line.
        cv.wait(um, [&](){
            return turn == 2;
        });
        printSecond();
        turn = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> um(m);
        // printThird() outputs "third". Do not change or remove this line.
        cv.wait(um, [&](){
            return turn == 3;
        });
        printThird();
        turn = 1;
        cv.notify_all();
    }
    
    void printFirst(){
        cout << "First";
    }
    void printSecond(){
        cout << "Second";   
    }
    void printThird(){
        cout << "Third"; 
    }
};