#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
		int id;
		char name[50];
		int age;
		float gpa;
}student;

typedef struct node{
	struct student data;
	struct node *next;

}node;

node *head=NULL;

void addStudent(const student *const ptr);
void displayStudents(void);
void searchStudent(int id);
void updateStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);
void deleteStudent(int id);

void main(){
	//-------------------//
	setvbuf(stdout, NULL, _IONBF, 0); setvbuf(stderr, NULL, _IONBF, 0);
	//-------------------//

	bool running=true;
	char choice;
	student newStudent;
	int idTemp;

	printf("Welcome!..");
	while (running){
		printf("\n---------------------------------------------------"
				"\n1-Add student."
				"\n2-Display students."
				"\n3-Search by ID."
				"\n4-Update student."
				"\n5-Delete student."
				"\n6-Calculate average GPA."
				"\n7-Search for highest GPA."
				"\n8-Exit."
				"\nSelect an option: ");
		scanf(" %c",&choice);
		printf("---------------------------------------------------\n");
		switch(choice){
			case '1':
				printf("Enter ID: ");
				scanf("%d", &newStudent.id);
				printf("Enter Name: ");
				scanf("%s", newStudent.name);
				printf("Enter Age: ");
				scanf("%d",&newStudent.age);
				printf("Enter GPA: ");
				scanf("%f", &newStudent.gpa);
				addStudent(&newStudent);
				break;
			case '2':
				displayStudents();
				break;
			case '3':
				printf("Enter ID: ");
				scanf("%d", &idTemp);
				searchStudent(idTemp);
				break;
			case '4':
				printf("Enter ID: ");
				scanf("%d", &idTemp);
				updateStudent(idTemp);
				break;
			case '5':
				printf("Enter ID: ");
				scanf("%d", &idTemp);
				deleteStudent(idTemp);
				break;
			case '6':
				printf("Average GPA: %f\n", calculateAverageGPA());
				break;
			case '7':
				searchHighestGPA();
				break;
			case '8':
				printf("Exiting....");
				running=false;
				break;
			default:
				printf("Error, invalid choice!");
		}
	}
}

void addStudent(const student *const ptr){
	    node *temp = head;
	    while (temp != NULL) {
	        if (temp->data.id == ptr->id) {
	            printf("Student with ID %d already exists.", ptr->id);
	            return;
	        }
	        temp = temp->next;
	    }

	    node *newNode = (node *)malloc(sizeof(node));
	    if (!newNode) {
	        printf("Memory allocation failed!\n");
	        return;
	    }

	    newNode->data = *ptr;
	    newNode->next = NULL;

	    if (head == NULL) {
	        head = newNode;
	    }
	    else {
	        temp = head;
	        while (temp->next != NULL) {
	            temp = temp->next;
	        }
	        temp->next = newNode;
	    }

	    printf("Student added successfully.");
}

void displayStudents(void){
	if (head == NULL) {
	        printf("No students found.");
	        return;
	    }

	    node *temp = head;
	    printf("Student List:\n");
	    while (temp != NULL) {
	        printf("ID: %d, Name: %s, AGE: %d, GPA: %f\n", temp->data.id, temp->data.name,temp->data.age, temp->data.gpa);
	        temp = temp->next;
	    }
}
void searchStudent(int id){
	node *temp = head;
	    while (temp != NULL) {
	        if (temp->data.id == id) {
	            printf("Student Found:\nID: %d, Name: %s, AGE: %d, GPA: %f", temp->data.id, temp->data.name,temp->data.age, temp->data.gpa);
	            return;
	        }
	        temp = temp->next;
	    }
	    printf("Student with ID %d not found.", id);
}
void updateStudent(int id){
	node *temp = head;
	    while (temp != NULL) {
	        if (temp->data.id == id) {
	            printf("Enter new name: ");
	            scanf("%s", temp->data.name);
	            printf("Enter new GPA: ");
	            scanf("%f", &temp->data.gpa);
	            printf("Student updated successfully.");
	            return;
	        }
	        temp = temp->next;
	    }
	    printf("Student with ID %d not found.", id);
}
float calculateAverageGPA(void){
	if (head == NULL) {
	        printf("No students found.\n");
	        return 0.0;
	    }

	    float sum = 0.0;
	    int count = 0;
	    node *temp = head;

	    while (temp != NULL) {
	        sum += temp->data.gpa;
	        count++;
	        temp = temp->next;
	    }
	    if (count == 0) {
	        return 0.0;
	    }
	    else {
	        return sum / count;
	    }
}
void searchHighestGPA(void){
	if (head == NULL) {
	        printf("No students found.\n");
	        return;
	    }

	    node *temp = head;
	    node *highest = head;

	    while (temp != NULL) {
	        if (temp->data.gpa > highest->data.gpa) {
	            highest = temp;
	        }
	        temp = temp->next;
	    }
	    printf("Student with Highest GPA is:\nID: %d, Name: %s, AGE: %d, GPA: %f",
	           highest->data.id, highest->data.name,highest->data.age, highest->data.gpa);
}
void deleteStudent(int id){
	node *temp = head, *prev = NULL;
	    while (temp != NULL && temp->data.id != id) {
	        prev = temp;
	        temp = temp->next;
	    }
	    if (temp == NULL) {
	        printf("Student with ID %d not found.", id);
	        return;
	    }
	    if (prev == NULL) {
	        head = temp->next;
	    }
	    else {
	        prev->next = temp->next;
	    }
	    free(temp);
	    printf("Student deleted successfully.");
}
