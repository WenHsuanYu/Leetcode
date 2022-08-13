class Foo {
private:
    // 24 bytes
    promise<void> p1;
    promise<void> p2;
    
public:
    Foo() {
        cout << sizeof(p1) << endl;
    }

    void first(function<void()> printFirst) {    
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        p1.set_value();
    }

    void second(function<void()> printSecond) {
        p1.get_future().wait();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        p2.set_value();
    }

    void third(function<void()> printThird) {
        p2.get_future().wait();
        // printThird() outputs "third". Do not change or remove this line.
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