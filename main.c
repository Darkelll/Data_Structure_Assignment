#include <stdio.h>

// Student name(string), StudentID(string), service type(string), and priroty
// level(urgent, normal) (int? because choose 0 | 1 based on the priority)

// Each user should select the data structure to work with????

// Queue

// Linked List

// Stack

// Menu
/*===== Smart Student Service Centre System =====
1. Add new student request
2. Serve next student
3. Display waiting queue
4. Display completed services
5. Search completed service by student ID
6. Undo last completed service
7. Display system summary
8. Exit
Enter your choice*/

int main() {

  int choice;

  do {
    printf("\n\n");
    printf("\t\t\t\t===== Smart Student Service Centre System =====\n");
    printf("\t\t\t\t1. Add new student request\n");
    printf("\t\t\t\t2. Serve next student\n");
    printf("\t\t\t\t3. Display waiting queue\n");
    printf("\t\t\t\t4. Display completed services\n");
    printf("\t\t\t\t5. Search completed service by student ID\n");
    printf("\t\t\t\t6. Undo last completed service\n");
    printf("\t\t\t\t7. Display system summary\n");
    printf("\t\t\t\t8. Exit\n\n");
    printf("Enter your choice (1-8): ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Choice 1");
      break;
    case 2:
      printf("choice 2");
      break;
    case 3:
      printf("choice 2");
      break;
    case 4:
      printf("choice 2");
      break;
    case 5:
      printf("choice 2");
      break;
    case 6:
      printf("choice 2");
      break;
    case 7:
      printf("choice 2");
      break;
    case 8:
      break;
    default:
      printf("Please pick enter correct number\n");
      break;
    }
  } while (choice != 8);

  return 0;
}