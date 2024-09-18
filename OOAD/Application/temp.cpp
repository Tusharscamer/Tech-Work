#include <iostream>
#include <functional>

using namespace std;

class Auditorium {
    int rows, cols;
    int** seats; // Dynamically allocated 2D array to store seat status

public:
    // Constructor to initialize the 2D array with all seats vacant (1)
    Auditorium(int r, int c) : rows(r), cols(c) {
        seats = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            seats[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                seats[i][j] = 1; // 1 denotes vacant
            }
        }
    }

    // Destructor to free dynamically allocated memory
    ~Auditorium() {
        for (int i = 0; i < rows; ++i) {
            delete[] seats[i];
        }
        delete[] seats;
    }

    // Lambda function to count vacant seats
    int countVacantSeats() const {
        auto countVacant = [this]() {
            int vacantCount = 0;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (seats[i][j] == 1) // 1 denotes vacant
                        vacantCount++;
                }
            }
            return vacantCount;
        };
        return countVacant();
    }

    // Overload pre-increment operator to occupy a seat (set to 0)
    Auditorium& operator++() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (seats[i][j] == 1) {
                    seats[i][j] = 0; // Occupy the first vacant seat found
                    return *this;
                }
            }
        }
        return *this;
    }

    // Overload pre-decrement operator to vacate a seat (set to 1)
    Auditorium& operator--() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (seats[i][j] == 0) {
                    seats[i][j] = 1; // Vacate the first occupied seat found
                    return *this;
                }
            }
        }
        return *this;
    }

    // Function to display the seating arrangement
    void displaySeats() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << seats[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Auditorium a(3, 3); // 3x3 auditorium

    cout << "Initial seating arrangement:" << endl;
    a.displaySeats();

    cout << "\nVacant seats: " << a.countVacantSeats() << endl;

    // Occupying a seat
    ++a;
    cout << "\nAfter occupying one seat:" << endl;
    a.displaySeats();

    cout << "\nVacant seats: " << a.countVacantSeats() << endl;

    // Vacating a seat
    --a;
    cout << "\nAfter vacating one seat:" << endl;
    a.displaySeats();

    cout << "\nVacant seats: " << a.countVacantSeats() << endl;

    return 0;
}
