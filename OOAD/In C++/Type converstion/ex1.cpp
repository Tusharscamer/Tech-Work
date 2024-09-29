#include<iostream>
using namespace std;

// Forward declaration of Percentage class
class Percentage;

class CG {
private:
    int cg;
public:
    // Constructors
    CG() {}
    CG(int cg) {
        this->cg = cg;
    }
    explicit CG(Percentage &p); // Declare constructor for conversion from Percentage

    // Conversion operator
    operator Percentage();

    int getcg() {
        return cg;
    }
    void setcg(int c) {
        cg = c;
    }
    void display() {
        cout << cg << endl;
    }
};

class Percentage {
private:
    int per;
public:
    // Getters and Setters
    int getper() {
        return per;
    }
    void setper(int p) {
        per = p;
    }

    // Constructors
    Percentage() {}
    Percentage(int p) {
        per = p;
    }
    explicit Percentage(CG &c); // Declare constructor for conversion from CG
    operator CG(); // Conversion operator

    void display() {
        cout << per << endl;
    }
};

// Define constructor for CG from Percentage
CG::CG(Percentage &p) {
    cg = p.getper() / 10;
}

// Define conversion operator for CG to Percentage
CG::operator Percentage() {
    return Percentage(cg * 10);
}

// Define constructor for Percentage from CG
Percentage::Percentage(CG &c) {
    per = c.getcg() * 10;
}

// Define conversion operator for Percentage to CG
Percentage::operator CG() {
    return CG(per / 10);
}

int main() {
    CG c(7); // Create CG object with 7 CG value
    Percentage p = static_cast<Percentage>(c); // Correctly cast CG to Percentage
    CG c1=static_cast<CG>(p);
    c1.display();
    p.display(); // Display the percentage (70)
    return 0;
}
