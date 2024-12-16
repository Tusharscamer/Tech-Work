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
template <typename C>
class App : public Cal<C> {
    public:
        App() {}
};
int main() {
    Cal<string> num;
    cin>>num;
    Cal<string> num8;
    cin>>num8;
    cout << num+ num8 << endl;
    return 0;
}
