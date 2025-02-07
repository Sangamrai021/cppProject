#include <iostream>  // For input and output using the console
#include <fstream>   // For file input and output operations

using namespace std;

#define MAX_STUDENTS 100  // Maximum number of students allowed

// Class to store and manage student information
class Student {
private:
    int rollNo;           // Roll number of the student
    char name[50];        // Name of the student
    float marks;          // Marks obtained by the student

public:
    // Function to input student details
    void inputStudent() {
        cout << "Enter Roll No: ";
        cin >> rollNo;   // Taking roll number as input
        cin.ignore();    // Ignore leftover newline character

        cout << "Enter Name: ";
        cin.getline(name, 50);  // Taking name as input with space

        cout << "Enter Marks: ";
        cin >> marks;    // Taking marks as input
    }

    // Function to display student details
    void displayStudent() {
        cout << "Roll No: " << rollNo << ", Name: " << name << ", Marks: " << marks << endl;
    }

    // Function to get roll number (used for searching)
    int getRollNo() { 
        return rollNo; 
    }

    // Save student data to a file
    void saveToFile() {
        ofstream file("students.txt", ios::app);  // Open file in append mode
        if (file.is_open()) {                      // Check if file opened successfully
            file << rollNo << " " << name << " " << marks << endl;  // Write student details to file
            file.close();  // Close the file
        } else {
            cout << "Error opening file for writing!\n";
        }
    }

    // Load all student data from the file
    //
    static int loadFromFile(Student students[]) { // data is same for all object of this class 
        ifstream file("students.txt");  // Open file in read mode
        int count = 0;  // Counter for the number of students loaded

        if (file.is_open()) {            // Check if file opened successfully
            while (file >> students[count].rollNo >> students[count].name >> students[count].marks) {
                count++;  // Increase count for each student loaded
            }
            file.close();  // Close the file
        } else {
            cout << "Error opening file for reading!\n";
        }
        return count;  // Return the number of students loaded
    }
};

// Function to search for a student by roll number
void searchStudent(Student students[], int count, int rollNo) {
    bool found = false;  // Flag to check if student is found

    for (int i = 0; i < count; i++) {  // Loop through all students
        if (students[i].getRollNo() == rollNo) {  // Check if roll number matches
            cout << "Student Found: ";
            students[i].displayStudent();  // Display student details
            found = true;
            break;
        }
    }

    if (!found) {  // If student not found, display message
        cout << "Student not found!\n";
    }
}

int main() {
    Student students[MAX_STUDENTS];  // Array to store student records
    int studentCount = Student::loadFromFile(students);  // Load existing students from file
    int choice;  // Variable to store user menu choice

    do {
        // Display the menu
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;  // Get user choice

        if (choice == 1) {  // Add a new student
            if (studentCount < MAX_STUDENTS) {  // Check if there is space for more students
                students[studentCount].inputStudent();  // Input student details
                students[studentCount].saveToFile();    // Save student details to file
                studentCount++;  // Increase student count
            } else {
                cout << "Student limit reached!\n";
            }
        } 
        else if (choice == 2) {  // Display all students
            cout << "\nStudent List:\n";
            for (int i = 0; i < studentCount; i++) {
                students[i].displayStudent();  // Display each student's details
            }
        } 
        else if (choice == 3) {  // Search for a student
            int roll;
            cout << "Enter Roll No to Search: ";
            cin >> roll;  // Get roll number to search
            searchStudent(students, studentCount, roll);  // Search and display result
        }

    } while (choice != 4);  // Exit when user chooses 4

    cout << "Exiting program...\n";  // Goodbye message
    return 0;
}