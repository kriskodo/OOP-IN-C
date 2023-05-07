#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Name class
typedef char * Name;

Name nameConstructor(void) {
    Name new_name = (Name) malloc(sizeof(char) * 256);  // Allocate memory for the name
    return new_name;
}

int nameDestructor(Name this) {
    free(this);  // Deallocate the memory for the name
    return 0;
}

Name putName(Name this, char * char_array) {
    strcpy(this, char_array);  // Copy the given character array into the allocated memory for the name
    return this;
}

// Define the Employee class
typedef struct {
    int employee_number;
    Name name;
} EmployeeStr;

typedef EmployeeStr * EmployeePtr;

EmployeePtr employeeConstructor(void) {
    EmployeePtr new_employee = (EmployeePtr) malloc(sizeof(EmployeeStr));  // Allocate memory for the employee
    new_employee->name = nameConstructor();  // Allocate memory for the name of the employee
    return new_employee;
}

int employeeInitialize(EmployeePtr this, int emp_no, Name name) {
    this->employee_number = emp_no;
    putName(this->name, name);
    return 0;
}

int employeeSetEmployeeNumber(EmployeePtr this, int emp_no) {
    this->employee_number = emp_no;
    return 0;
}

int employeeGetEmployeeNumber(EmployeePtr this, int error) {
    if (this == NULL) {
        return error;  // Return error if the employee object is null
    }
    return this->employee_number;
}

int employeeSetEmployeeName(EmployeePtr this, Name name) {
    putName(this->name, name);
    return 0;
}

Name employeeGetEmployeeName(EmployeePtr this, int error) {
    if (this == NULL) {
        return NULL;  // Return null if the employee object is null
    }

    return this->name;
}

int main() {
    // Create a new employee
    EmployeePtr emp = employeeConstructor();

    employeeInitialize(emp, 12345, "John Smith");

    employeeSetEmployeeName(emp, "Kris");
    employeeSetEmployeeNumber(emp, 1);

    printf("Employee Number: %d\n", employeeGetEmployeeNumber(emp, -1));
    printf("Employee Name: %s\n", employeeGetEmployeeName(emp, -1));

    nameDestructor(emp->name);
    free(emp);

    return 0;
}