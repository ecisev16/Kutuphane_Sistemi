#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
   char* name;
   int age;
};

struct employee {
   struct person info;
   float salary;
   struct employee* next;
};

struct department {
   char* name;
   struct employee* head;  // pointer to the head of an employee list
   struct department* next;
};

struct department* dept_head = NULL;

struct department* new_department(char* name) {
   struct department* new_department = (struct department*)malloc(sizeof(struct department));
   new_department->name = (char*)malloc(strlen(name) + 1);
   strcpy(new_department->name, name);
   new_department->head = NULL;  // initialize employee list to NULL
   new_department->next = NULL;
   return new_department;
}

struct employee* new_employee(char* name, int age, float salary) {
   struct employee* new_employee = (struct employee*)malloc(sizeof(struct employee));
   new_employee->info.name = (char*)malloc(strlen(name) + 1);
   strcpy(new_employee->info.name, name);
   new_employee->info.age = age;
   new_employee->salary = salary;
   new_employee->next = NULL;
   return new_employee;
}

void add_to_dept_list(char* dept_name, char* emp_name, int emp_age, float emp_salary) {
   // Check if the department already exists
   struct department* current = dept_head;
   while (current != NULL && strcmp(current->name, dept_name) != 0) {
      current = current->next;
