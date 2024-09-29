// C++ program for the above approach
#include <iostream>
using namespace std;

// Box Class
class box {

public:
    int length;
    int breadth;
    int height;
      int *p;
    // Function that sets the dimensions
    void set_dimensions(int length1, int breadth1,
                        int height1,int x)
    {
        length = length1;
        breadth = breadth1;
        height = height1;
          p=new int;
      *p=x;
    }

    // Function to display the dimensions
    // of the Box object
    void show_data()
    {
        cout << " Length = " << length
             << "\n Breadth = " << breadth
             << "\n Height = " << height
             << "\n P int pointing to = "<<p<<" value is"<<*p<< endl;
    }
};

// Driver Code
int main()
{
    // Object of class Box
    box B1, B3;

    // Set dimensions of Box B1
    B1.set_dimensions(14, 12, 16,100);
    B1.show_data();

    // When copying the data of object
    // at the time of initialization
    // then copy is made through
    // COPY CONSTRUCTOR
    box B2 = B1;
    B2.show_data();

    // When copying the data of object
    // after initialization then the
    // copy is done through DEFAULT
    // ASSIGNMENT OPERATOR
    int y=2;
    *B1.p=2;
    B1.show_data();
    B2.show_data();
    B3 = B1;
    int z=3;
    B1.p=&z;
    B1.show_data();
    B3.show_data();

    return 0;
}
