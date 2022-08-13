class Foo {
public:
    mutex m1, m2;
    
    Foo() {
        m1.lock();
        m2.lock();
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m1.unlock();
    }

    void second(function<void()> printSecond) {
        lock_guard<mutex> mlock(m1);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m2.unlock();
    }

    void third(function<void()> printThird) {
        // printThird() outputs "third". Do not change or remove this line.
        lock_guard<mutex> mlock(m2);
        printThird();
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