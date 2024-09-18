#include <iostream>
using namespace std;

template <typename C>
class Cal {
private:
    C num1;
public:
    // Constructors
    Cal() {}
    Cal(C num1) {
        setnum1(num1);
    }

    // Getters and Setters
    C getnum1() {
        return num1;
    }
    void setnum1(C num1) {
        this->num1 = num1;
    }

    // Friend functions for input/output overloading
    friend ostream &operator<<(ostream &out, const Cal<C> &obj) {
        out << obj.num1;
        return out;
    }

    friend istream &operator>>(istream &in, Cal<C> &obj) {
        in >> obj.num1;
        return in;
    }
};

// Operator overloads for basic arithmetic operations
template <typename C>
Cal<C> operator+( Cal<C> &obj1,  Cal<C> &obj2) {
    Cal<C> newobj;
    newobj.setnum1(obj1.getnum1() + obj2.getnum1());
    return newobj;
}

template <typename C>
Cal<C> operator-( Cal<C> &obj1,  Cal<C> &obj2) {
    Cal<C> newobj;
    newobj.setnum1(obj1.getnum1() - obj2.getnum1());
    return newobj;
}

template <typename C>
Cal<C> operator*(Cal<C> &obj1,  Cal<C> &obj2) {
    Cal<C> newobj;
    newobj.setnum1(obj1.getnum1() * obj2.getnum1());
    return newobj;
}

template <typename C>
Cal<C> operator/(Cal<C> &obj1,  Cal<C> &obj2) {
    Cal<C> newobj;
    newobj.setnum1(obj1.getnum1() / obj2.getnum1());
    return newobj;
}

int main() {
    Cal<int> num1(2);
    Cal<int> num2(4);
    Cal<int> num3 = num1 + num2;
    cout<<num1-num2<<endl;
    cout<<num2*num3<<endl;
    cout<<num1/num2<<endl;
    cout << num3 << endl; 
    Cal<float> num4(2.5);
    Cal<float> num5(4.3);
    cout<<endl;
    cout << num4+num5 << endl;
    cout << num4-num5 << endl;
    cout << num4*num5 << endl;
    cout << num4/num5 << endl;
    Cal<float> num6 = num4 + num5;
    cout << endl;
    Cal<string> num7("Hello");
    Cal<string> num8("World");
    cout << num7 + num8 << endl;
    return 0;
}
