#include <iostream>
#include <fstream>
using namespace std;

// Base class Shape
class Shape {
protected:
    string type;
    double area;

public:
    // Constructor
    Shape(const string& type) : type(type), area(0.0) {}

    // Virtual destructor
    virtual ~Shape() {}

    // Getter for type
    const string& getType() const {
        return type;
    }

    // Getter for area
    double getArea() const {
        return area;
    }

    // Abstract method to be overridden by subclasses
    virtual void calculateArea() = 0;

    // Print information about the shape
    void printInfo() const {
        cout << "Type: " << type << ", Area: " << area << endl;
    }

    // Abstract file IO methods
    virtual void readFromFile(istream& in) = 0;
    virtual void writeToFile(ofstream& outFile) const = 0;
};

// Circle is a subclass of Shape
class Circle : public Shape {
private:
    double radius;

public:
    // Constructor
    Circle() : Shape("Circle"), radius(0.0) {}

    // Calculate circle area
    void calculateArea() override {
        area = 3.141592653589793 * radius * radius;
    }

    // Read circle data from console input (cin)
    void readFromFile(istream& in) override {
        cout << "Enter radius for a circle: ";
        in >> radius;
        calculateArea(); // Update the area after reading input
    }

    // Write circle data to file
    void writeToFile(ofstream& outFile) const override {
        outFile << getType() << " " << radius << endl;
    }
};

// Square is a subclass of Shape
class Square : public Shape {
private:
    double sideLength;

public:
    // Constructor
    Square() : Shape("Square"), sideLength(0.0) {}

    // Calculate square area
    void calculateArea() override {
        area = sideLength * sideLength;
    }

    // Read square data from console input (cin)
    void readFromFile(istream& in) override {
        cout << "Enter side length for a square: ";
        in >> sideLength;
        calculateArea(); // Update the area after reading input
    }

    // Write square data to file
    void writeToFile(ofstream& outFile) const override {
        outFile << getType() << " " << sideLength << endl;
    }
};

int main() {
    // Create Circle and Square instances
    Circle circle;
    Square square;

    // Read dimensions from user
    circle.readFromFile(cin);
    square.readFromFile(cin);

    // Print information about the shapes
    circle.printInfo();
    square.printInfo();

    // Write shape data to file
    ofstream outFile("shapes.txt");
    if (outFile.is_open()) {
        circle.writeToFile(outFile);
        square.writeToFile(outFile);
        outFile.close();
    } else {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    // Read shape data from file
    ifstream inFile("shapes.txt");
    if (inFile.is_open()) {
        Circle loadedCircle;
        Square loadedSquare;

        loadedCircle.readFromFile(inFile);
        loadedSquare.readFromFile(inFile);

        inFile.close();

        // Print loaded information
        loadedCircle.printInfo();
        loadedSquare.printInfo();
    } else {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    return 0;
}
