#include <iostream>
#include <vector>
#include <ctime> // For time-related functions
#include <algorithm> // For bubble sort

class Car {
public:
    std::string plate;
    std::string manufacturer;
    std::string modelName;
    std::string modelYear;
    std::string plateNumber;

    time_t entryTime;
    time_t exitTime;
    int totalHours;
    float totalCost;

    Car(const std::string& plate, const std::string& manufacturer, const std::string& modelName,
        const std::string& modelYear, const std::string& plateNumber)
        : plate(plate), manufacturer(manufacturer), modelName(modelName), modelYear(modelYear),
          plateNumber(plateNumber), entryTime(time(nullptr)), exitTime(0), totalHours(0), totalCost(0.0) {}
};

// Main parking database (vector of Car objects)
std::vector<Car> parkingDatabase;

// Function to record exit time and calculate parking charge
void recordExit(int carIndex) {
    if (carIndex >= 0 && carIndex < parkingDatabase.size()) {
        Car& car = parkingDatabase[carIndex];
        car.exitTime = time(nullptr);
        double totalHours = difftime(car.exitTime, car.entryTime) / 3600.0;
        car.totalHours = static_cast<int>(totalHours);
        if (totalHours <= 0.5) {
            car.totalCost = 0.0;
        } else if (totalHours <= 2.0) {
            car.totalCost = 3.0;
        } else {
            car.totalCost = 3.0 + (totalHours - 2.0) * 1.5;
        }
    } else {
        std::cout << "Error: Invalid car index.\n";
    }
}

// Function to display parking database
void displayParkingDatabase() {
    std::cout << "Parking Database:\n";
    for (size_t i = 0; i < parkingDatabase.size(); ++i) {
        const Car& car = parkingDatabase[i];
        std::cout << "Car " << (i + 1) << ": Plate: " << car.plate << ", Manufacturer: " << car.manufacturer
                  << ", Model: " << car.modelName << ", Year: " << car.modelYear
                  << ", Plate Number: " << car.plateNumber
                  << ", Entry Time: " << std::ctime(&car.entryTime)
                  << ", Exit Time: " << (car.exitTime == 0 ? "Not exited" : std::ctime(&car.exitTime))
                  << ", Total Hours: " << car.totalHours
                  << ", Total Cost: $" << car.totalCost << "\n";
    }
}

// Bubble Sort algorithm to sort cars based on the year of manufacture
void bubbleSort() {
    for (size_t i = 0; i < parkingDatabase.size(); ++i) {
        for (size_t j = 0; j < parkingDatabase.size() - i - 1; ++j) {
            if (parkingDatabase[j].modelYear > parkingDatabase[j + 1].modelYear) {
                std::swap(parkingDatabase[j], parkingDatabase[j + 1]);
            }
        }
        std::cout << "Iteration " << (i + 1) << ":\n";
        displayParkingDatabase();
        std::cout << std::endl;
    }
}

// Manual input of data
void manualInputData() {
    while (true) {
        std::string plate, manufacturer, modelName, modelYear, plateNumber;
        std::cout << "Enter plate number (or 'done' to finish): ";
        std::getline(std::cin, plate);
        if (plate == "done") {
            break;
        }
        std::cout << "Enter manufacturer: ";
        std::getline(std::cin, manufacturer);
        std::cout << "Enter model name: ";
        std::getline(std::cin, modelName);
        std::cout << "Enter model year: ";
        std::getline(std::cin, modelYear);
        std::cout << "Enter plate number: ";
        std::getline(std::cin, plateNumber);
        parkingDatabase.emplace_back(plate, manufacturer, modelName, modelYear, plateNumber);
        std::cout << "Car parked successfully.\n";
    }
}

// Main function
int main() {
    // Manual input of data
    std::cout << "Manual input of data:\n";
    manualInputData();

    // Example usage
    recordExit(0); // Assuming the first car exited
    
    // Display parking database
    std::cout << "\nInitial Parking Database:\n";
    displayParkingDatabase();
    
    // Sorting based on the year of manufacture using Bubble Sort
    std::cout << "\nSorting based on the year of manufacture using Bubble Sort:\n";
    bubbleSort();
    
    // Display parking database after sorting
    std::cout << "\nParking Database after sorting:\n";
    displayParkingDatabase();

    return 0;
}
