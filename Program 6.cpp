#include <iostream>

class DB; // Forward declaration

class DM {
    private:
        float meters;
        float centimeters;
    public:
        DM(float m = 0, float cm = 0) : meters(m), centimeters(cm) {}

        void input() {
            std::cout << "Enter distance in meters and centimeters:\n";
            std::cout << "Meters: ";
            std::cin >> meters;
            std::cout << "Centimeters: ";
            std::cin >> centimeters;
        }

        void display() const {
            std::cout << "Distance: " << meters << " meters and " << centimeters << " centimeters\n";
        }

        friend void add(DM&, DB&);
};

class DB {
    private:
        float feet;
        float inches;
    public:
        DB(float f = 0, float in = 0) : feet(f), inches(in) {}

        void input() {
            std::cout << "Enter distance in feet and inches:\n";
            std::cout << "Feet: ";
            std::cin >> feet;
            std::cout << "Inches: ";
            std::cin >> inches;
        }

        void display() const {
            std::cout << "Distance: " << feet << " feet and " << inches << " inches\n";
        }

        friend void add(DM&, DB&);
};

void add(DM &dm, DB &db) {
    // Converting DB to DM
    float totalInches = db.feet * 12 + db.inches;
    float totalCentimeters = totalInches * 2.54;
    float totalMeters = totalCentimeters / 100;

    // Adding DM and converted DB
    dm.meters += totalMeters;
    dm.centimeters += (totalCentimeters - static_cast<int>(totalMeters) * 100);

    // Adjusting centimeters to meters if necessary
    if (dm.centimeters >= 100) {
        dm.meters += 1;
        dm.centimeters -= 100;
    }

    dm.display();
}

int main() {
    DM distanceDM;
    DB distanceDB;

    distanceDM.input();
    distanceDB.input();

    std::cout << "Choose the unit for the result (1 for DM, 2 for DB): ";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        add(distanceDM, distanceDB); // The result will be displayed in meters and centimeters
    } else {
        std::cout << "Conversion to DB and addition is not implemented yet.\n";
    }

    return 0;
}
