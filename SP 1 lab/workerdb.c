
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "readfile.h"

// set boundaries
#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 20
#define MIN_SALARY 30000
#define MAX_SALARY 150000
#define MAX_ID 999999
#define MIN_ID 100000

// employee struct
typedef struct {
    int id;
    char first_name[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
    int salary;
} Employee;

// database struct
typedef struct {
    Employee employees[MAX_EMPLOYEES];
    int num_employees;
} EmployeeDB;

// function prototypes
void print_menu();
void print_database(EmployeeDB db);
void lookup_by_id(EmployeeDB db);
void lookup_by_last_name(EmployeeDB db);
void add_employee(EmployeeDB *db);

// main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *file_name = argv[1];
    
    // open file function
int file_open_result = open_file(file_name);
if (file_open_result == -1) {
    printf("Error: file could not be opened.\n");
    exit(EXIT_FAILURE);
}

    // read file into database
EmployeeDB db;
db.num_employees = 0;
int id, salary;
char first_name[MAX_NAME_LENGTH], last_name[MAX_NAME_LENGTH];
while (read_int(&id) == 0 &&
       read_string(first_name) == 0 &&
       read_string(last_name) == 0 &&
       read_int(&salary) == 0) {
    // create employee struct
    Employee emp;
    emp.id = id;
    strcpy(emp.first_name, first_name);
    strcpy(emp.last_name, last_name);
    emp.salary = salary;
    
    // add employee to database
    db.employees[db.num_employees++] = emp;
}

    // close file function
close_file();

     // main loop function
    int choice = 0;
    while (choice != 5) {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                print_database(db);
                break;
            case 2:
                lookup_by_id(db);
                break;
            case 3:
                lookup_by_last_name(db);
                break;
            case 4:
                add_employee(&db);
                break;
            case 5:
                printf("goodbye!\n");
                break;
            default:
                printf("Hey, %d is not between 1 and 5, try again...\n", choice);
        }
    }
    
    return 0;
}
    
// print menu function
void print_menu() {
    printf("\nEmployee DB Menu:\n");
    printf("----------------------------------\n");
    printf("  (1) Print the Database\n");
    printf("  (2) Lookup by ID\n");
    printf("  (3) Lookup by Last Name\n");
    printf("  (4) Add an Employee\n");
    printf("  (5) Quit\n");
    printf("----------------------------------\n");
    printf("Enter your choice: ");
}

// print database function
void print_database(EmployeeDB db) {
    printf("\nNAME\t\t\tSALARY\t\tID\n");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < db.num_employees; i++) {
        Employee emp = db.employees[i];
        printf("%s %s\t\t%d\t\t%d\n", emp.first_name, emp.last_name, emp.salary, emp.id);
    }
    printf("---------------------------------------------------------------\n");
    printf(" Number of Employees (%d)\n\n", db.num_employees);
}

// lookup_by_id function
void lookup_by_id(EmployeeDB db) {
    int id;
    printf("Enter the employee ID: ");
    scanf("%d", &id);
    
    for (int i = 0; i < db.num_employees; i++) {
        if (db.employees[i].id == id) {
            Employee emp = db.employees[i];
            printf("\nEmployee found:\n");
            printf("Name: %s %s\n", emp.first_name, emp.last_name);
            printf("Salary: %d\n", emp.salary);
            printf("ID: %d\n", emp.id);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

// lookup_by_last_name function
void lookup_by_last_name(EmployeeDB db) {
    char last_name[MAX_NAME_LENGTH];
    printf("Enter the employee's last name: ");
    scanf("%s", last_name);
    
    for (int i = 0; i < db.num_employees; i++) {
        if (strcmp(db.employees[i].last_name, last_name) == 0) {
            Employee emp = db.employees[i];
            printf("\nEmployee found:\n");
            printf("Name: %s %s\n", emp.first_name, emp.last_name);
            printf("Salary: %d\n", emp.salary);
            printf("ID: %d\n", emp.id);
            return;
        }
    }
    printf("Employee with last name %s not found.\n", last_name);
}

// add_employee function
void add_employee(EmployeeDB *db) {
    if (db->num_employees >= MAX_EMPLOYEES) {
        printf("Employee database is full.\n");
        return;
    }
    
    Employee new_emp;
    printf("Enter the employee's first name: ");
    scanf("%s", new_emp.first_name);
    printf("Enter the employee's last name: ");
    scanf("%s", new_emp.last_name);
    printf("Enter the employee's salary: ");
    scanf("%d", &new_emp.salary);
   
   // Assign the new employee's ID by taking the ID of the last employee and adding 1
    new_emp.id = db->employees[db->num_employees - 1].id + 1;
    
    if (new_emp.salary < MIN_SALARY || new_emp.salary > MAX_SALARY) {
        printf("Error: Salary must be between %d and %d.\n", MIN_SALARY, MAX_SALARY);
        return;
    }

    if (new_emp.id < MIN_ID || new_emp.id > MAX_ID) {
        printf("Error: ID must be between %d and %d.\n", MIN_ID, MAX_ID);
        return;
    }
    
    db->employees[db->num_employees++] = new_emp;
    printf("Employee added successfully.\n");
}
