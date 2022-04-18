/* Gokhan Gunesoglu   gokhangunesoglu@gmail.com */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string>				

struct Lesson {
	char name[40];
	int code;
	int credit;
	int akts;
	char teacher[50];
	Lesson* prev;
	Lesson* next;
};

bool isThisCircleList = false;								//false=lineer list // true=circle list
Lesson* head;
Lesson* foot;
int lessonCode = 1000;
int nodeCount = 0;
Lesson* head2;
Lesson* foot2;

void loadDemo();
void loadDemo2();
void writeString(char ptr[], std::string str);
bool compareLetter(char str1[], char str2[]);
void clearData(char* ptr);
Lesson* createNewNode();
void addNodeToHead();
void addNodeToFoot();
void addNodeToIndex();
void printList();
Lesson* findNodeByName(Lesson* start, char name[]);
Lesson* findNodeByTeacher(Lesson* start, char name[]);
Lesson* findNodeByCode(Lesson* start, int code);
void findNodeAndWrite(int key);
void deleteNode(Lesson* willBeDelete);
void findNodeAndRemove(int key);
void addNodeToNextOfTheLessonCode();
void bridgeLists(Lesson* list1, Lesson* list2);
void printActions();
bool userScreen();

int main() {												////main is here////	////main is here////	////main is here////

	loadDemo();		//you can command it if u dont need a demo
	loadDemo2();	//you can command it if u dont need bridgeLists

	printf("Wellcome, Enter a number:\n");
	printf("0 = Exit   1-12 = Actions   Higer numbers print actions...\n");
	while (userScreen()) {
	}
	if (isThisCircleList) {
		printf("list was circle\n");
	}
	else {
		printf("list was lineer\n");
	}
	printf("Okey than, See you later...");

	return 0;
}														////////////////////	////////////////////	////////////////////

void loadDemo() {
	head = (Lesson*)malloc(sizeof(Lesson));
	Lesson* iter = head;
	nodeCount++;
	clearData(iter->name);
	iter->code = ++lessonCode;
	iter->credit = 6;
	iter->akts = 8;
	writeString(iter->name, "Veri Yapilari");
	writeString(iter->teacher, "Gokhan Muzaffer Gunesoglu");

	iter->next = (Lesson*)malloc(sizeof(Lesson));
	clearData(iter->next->name);
	iter->next->prev = iter;
	iter = iter->next;
	nodeCount++;
	iter->code = ++lessonCode;
	iter->credit = 4;
	iter->akts = 6;
	writeString(iter->name, "Sayisal Analiz");
	writeString(iter->teacher, "Gokhan Muzaffer Gunesoglu");


	iter->next = (Lesson*)malloc(sizeof(Lesson));
	clearData(iter->next->name);
	iter->next->prev = iter;
	iter = iter->next;
	nodeCount++;
	iter->code = ++lessonCode;
	iter->credit = 4;
	iter->akts = 6;
	writeString(iter->name, "Sayisal Analiz");
	writeString(iter->teacher, "Damla Nur Emlik");

	iter->next = (Lesson*)malloc(sizeof(Lesson));
	clearData(iter->next->name);
	iter->next->prev = iter;
	iter = iter->next;
	nodeCount++;
	iter->code = ++lessonCode;
	iter->credit = 3;
	iter->akts = 4;
	writeString(iter->name, "Ayrik Matematik");
	writeString(iter->teacher, "Ali Esref Atasoy");

	iter->next = (Lesson*)malloc(sizeof(Lesson));
	clearData(iter->next->name);
	iter->next->prev = iter;
	iter = iter->next;
	nodeCount++;
	iter->code = ++lessonCode;
	iter->credit = 4;
	iter->akts = 6;
	writeString(iter->name, "Lineer Cebir");
	writeString(iter->teacher, "Zekiye Tekin");

	iter->next = (Lesson*)malloc(sizeof(Lesson));
	clearData(iter->next->name);
	iter->next->prev = iter;
	iter = iter->next;
	nodeCount++;
	iter->code = ++lessonCode;
	iter->credit = 6;
	iter->akts = 8;
	writeString(iter->name, "Veri Yapilari");
	writeString(iter->teacher, "Emre Tantu");

	iter->next = (Lesson*)malloc(sizeof(Lesson));
	clearData(iter->next->name);
	iter->next->prev = iter;
	iter = iter->next;
	nodeCount++;
	iter->code = ++lessonCode;
	iter->credit = 3;
	iter->akts = 4;
	writeString(iter->name, "Ayrik Matematik");
	writeString(iter->teacher, "Ali Esref Atasoy");
	foot = iter;
	if (isThisCircleList) {
		head->prev = foot;
		foot->next = head;
	}
}

void loadDemo2() {
	head2 = (Lesson*)malloc(sizeof(Lesson));
	Lesson* iter = head2;
	nodeCount++;
	clearData(iter->name);
	iter->code = ++lessonCode;
	iter->credit = 6;
	iter->akts = 8;
	writeString(iter->name, "(2) Veri Yapilari");
	writeString(iter->teacher, "(2) Gokhan Muzaffer Gunesoglu");

	iter->next = (Lesson*)malloc(sizeof(Lesson));
	clearData(iter->next->name);
	iter->next->prev = iter;
	iter = iter->next;
	nodeCount++;
	iter->code = ++lessonCode;
	iter->credit = 4;
	iter->akts = 6;
	writeString(iter->name, "(2) Sayisal Analiz");
	writeString(iter->teacher, "(2) Gokhan Muzaffer Gunesoglu");

	iter->next = (Lesson*)malloc(sizeof(Lesson));
	clearData(iter->next->name);
	iter->next->prev = iter;
	iter = iter->next;
	nodeCount++;
	iter->code = ++lessonCode;
	iter->credit = 4;
	iter->akts = 6;
	writeString(iter->name, "(2) Sayisal Analiz");
	writeString(iter->teacher, "(2) Damla Nur Emlik");

	iter->next = (Lesson*)malloc(sizeof(Lesson));
	clearData(iter->next->name);
	iter->next->prev = iter;
	iter = iter->next;
	nodeCount++;
	iter->code = ++lessonCode;
	iter->credit = 3;
	iter->akts = 4;
	writeString(iter->name, "(2) Ayrik Matematik");
	writeString(iter->teacher, "(2) Ali Esref Atasoy");

	iter->next = (Lesson*)malloc(sizeof(Lesson));
	clearData(iter->next->name);
	iter->next->prev = iter;
	iter = iter->next;
	nodeCount++;
	iter->code = ++lessonCode;
	iter->credit = 4;
	iter->akts = 6;
	writeString(iter->name, "(2) Lineer Cebir");
	writeString(iter->teacher, "(2) Zekiye Tekin");

	iter->next = (Lesson*)malloc(sizeof(Lesson));
	clearData(iter->next->name);
	iter->next->prev = iter;
	iter = iter->next;
	nodeCount++;
	iter->code = ++lessonCode;
	iter->credit = 6;
	iter->akts = 8;
	writeString(iter->name, "(2) Veri Yapilari");
	writeString(iter->teacher, "(2) Emre Tantu");

	iter->next = (Lesson*)malloc(sizeof(Lesson));
	clearData(iter->next->name);
	iter->next->prev = iter;
	iter = iter->next;
	nodeCount++;
	iter->code = ++lessonCode;
	iter->credit = 3;
	iter->akts = 4;
	writeString(iter->name, "(2) Ayrik Matematik");
	writeString(iter->teacher, "(2) Ali Esref Atasoy");
	foot2 = iter;
	if (isThisCircleList) {
		head2->prev = foot2;
		foot2->next = head2;
	}
}

void writeString(char ptr[], std::string str) {
	int i = 0;
	while (str[i] != NULL) {
		ptr[i] = str[i];
		i++;
	}
}

bool compareLetter(char str1[], char str2[]) {
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0') {
		if (str1[i] != str2[i])
			return false;
		i++;
	}
	return true;
}

void clearData(char* ptr) {
	for (int i = 0; i < sizeof(Lesson); i++) {
		ptr[i] = NULL;
	}
}

Lesson* createNewNode() {
	Lesson* newNode = (Lesson*)malloc(sizeof(Lesson));
	clearData(newNode->name);
	printf("Name of lesson:\n");
	scanf("%i"); //for bugs
	gets_s(newNode->name);
	printf("Name of teacher:\n");
	gets_s(newNode->teacher);
	printf("Lesson akts:\n");
	scanf("%i", &newNode->akts);
	printf("Lesson credit:\n");
	scanf("%i", &newNode->credit);
	newNode->code = ++lessonCode;
	nodeCount++;
	return newNode;
}

void addNodeToHead() {
	Lesson* newNode = createNewNode();
	if (head == NULL) {						//0 node
		head = foot = newNode;
		if (isThisCircleList) {
			head->next = head->prev = head;
		}
	}
	else {								//1 and more node
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		if (isThisCircleList) {			//if is it circle
			foot->next = head;
			head->prev = foot;
		}
	}
	printList();
}

void addNodeToFoot() {
	Lesson* newNode = createNewNode();
	if (head == NULL) {
		head = foot = newNode;
		if (isThisCircleList) {
			head->next = head->prev = head;
		}
	}
	else {
		newNode->prev = foot;
		foot->next = newNode;
		foot = newNode;
		if (isThisCircleList) {
			foot->next = head;
			head->prev = foot;
		}
	}
	printList();
}

void addNodeToIndex() {
	Lesson* iter = head;
	int key;
	printf("List has %i node, enter a number range(0 to %i)\n", nodeCount, nodeCount);
	do {
		printf("Wich index do you want to add:");
		scanf("%i", &key);
		if (key > nodeCount || key < 0) {
			printf("Please enter a key range 0 to %i\n", nodeCount);
		}
	} while (key > nodeCount || key < 0);
	if (key == 0) {
		addNodeToHead();
		return;
	}
	if (key == nodeCount) {
		addNodeToFoot();
		return;
	}
	for (int i = 0; i < key - 1; i++) {
		iter = iter->next;
	}
	Lesson* newNode = createNewNode();
	iter->next->prev = newNode;
	newNode->next = iter->next;
	iter->next = newNode;
	newNode->prev = iter;
	printList();
}

void printList() {
	if (head == NULL) {
		printf("List is empty\n");
		return;
	}
	Lesson* iter = head;
	printf("============================================================Current List============================================================\n");
	while (iter != foot) {
		printf("[Lesson Code: %i]  [Lesson AKTS: %i]  [Lesson Credit: %i]  [Lesson Name: %s]  [Lesson Teacher: %s]\n", iter->code, iter->akts, iter->credit, iter->name, iter->teacher);
		iter = iter->next;
	}
	printf("[Lesson Code: %i]  [Lesson AKTS: %i]  [Lesson Credit: %i]  [Lesson Name: %s]  [Lesson Teacher: %s]\n\n", iter->code, iter->akts, iter->credit, iter->name, iter->teacher);
}

Lesson* findNodeByName(Lesson* start, char name[]) {
	while (start != foot) {
		if (compareLetter(start->name, name))
			return start;
		start = start->next;
	}
	if (compareLetter(start->name, name))
		return start;
	return NULL;
}

Lesson* findNodeByTeacher(Lesson* start, char name[]) {
	while (start != foot) {
		if (compareLetter(start->teacher, name)) {
			return start;
		}
		start = start->next;
	}
	if (compareLetter(start->teacher, name)) {
		return start;
	}
	return NULL;
}

Lesson* findNodeByCode(Lesson* start, int code) {
	while (start != foot) {
		if (start->code == code)
			return start;
		start = start->next;
	}
	if (start->code == code)
		return start;
	return NULL;
}

void findNodeAndWrite(int key) {
	Lesson* iter = head;
	if (key == 1) {
		int i = 0;
		char name[25];
		printf("Enter name of the lesson:\n");
		scanf("%i"); //bugs
		gets_s(name);
		while (true) {
			iter = findNodeByName(iter, name);
			if (iter != NULL) {
				if (i == 0)
					printf("===========================================================Lessons Found===========================================================\n");
				printf("[Lesson Code: %i]  [Lesson AKTS: %i]  [Lesson Credit: %i]  [Lesson Name: %s]  [Lesson Teacher: %s]\n", iter->code, iter->akts, iter->credit, iter->name, iter->teacher);
				i++;
				iter = iter->next;
			}
			else {
				if (i == 0)
					printf("Lesson coudnot find...\n");
				printf("\n");
				return;
			}
		}
	}if (key == 2) {
		int i = 0;
		char name[50];
		printf("Enter name and surname of the teacher:\n");
		scanf("%i"); //bugs
		gets_s(name);
		while (true) {
			iter = findNodeByTeacher(iter, name);
			if (iter != NULL) {
				if (i == 0)
					printf("===========================================================Lessons Found===========================================================\n");
				printf("[Lesson Code: %i]  [Lesson AKTS: %i]  [Lesson Credit: %i]  [Lesson Name: %s]  [Lesson Teacher: %s]\n", iter->code, iter->akts, iter->credit, iter->name, iter->teacher);
				i++;
				iter = iter->next;
			}
			else {
				if (i == 0)
					printf("Teacher coudnot find...\n");
				printf("\n");
				return;
			}
		}
	}
	int code;
	printf("Enter the code of lesson:");
	scanf("%i", &code);
	iter = findNodeByCode(iter, code);
	if (iter != NULL) {
		printf("===========================================================Lesson Found===========================================================\n");
		printf("[Lesson Code: %i]  [Lesson AKTS: %i]  [Lesson Credit: %i]  [Lesson Name: %s]  [Lesson Teacher: %s]\n\n", iter->code, iter->akts, iter->credit, iter->name, iter->teacher);
	}
	else {
		printf("Lesson code coudnot find...\n\n");
	}
	return;
}

void deleteNode(Lesson* willBeDelete) {
	Lesson* temp = willBeDelete;			//if this node is head
	if (temp == head) {
		if (head == foot) { 				//if this node is the last one node (its also foot)
			free(head);
			head = NULL;
			foot = NULL;
			nodeCount--;
			return;
		}
		head = head->next;
		if (isThisCircleList) {
			head->prev = foot;
			foot->next = head;
		}
		else
			head->prev = NULL;
		free(willBeDelete);
		nodeCount--;
		return;
	}
	if (temp == foot) {  	 				//if this node is foot and its not head (we have min 2 node)
		foot = foot->prev;
		if (isThisCircleList) {
			foot->next = head;
			head->prev = foot;
		}
		else
			foot->next = NULL;
		free(willBeDelete);
		nodeCount--;
		return;
	}
	temp = temp->prev;					//if this node is not head or foot (we have min 3 node)
	temp->next = temp->next->next;
	temp->next->prev = temp;
	free(willBeDelete);
	nodeCount--;
	return;
}

void findNodeAndRemove(int key) {
	Lesson* iter = head;
	if (key == 1) {
		char name[25];
		printf("Enter name of the lesson:\n");
		scanf("%i"); //bugs
		gets_s(name);
		int i = 0;
		while (true) {
			iter = findNodeByName(iter, name);
			if (iter != NULL) {
				if (i == 0)
					printf("============================================================Removed Lessons============================================================\n");
				printf("[Lesson Code: %i]  [Lesson AKTS: %i]  [Lesson Credit: %i]  [Lesson Name: %s]  [Lesson Teacher: %s]\n", iter->code, iter->akts, iter->credit, iter->name, iter->teacher);
				deleteNode(iter);
				iter = iter->next;
				i++;
			}
			else {
				if (i == 0)
					printf("Lesson coudnot find...\n");
				printf("\n");
				printList();
				return;
			}
		}
	}
	if (key == 2) {
		char name[50];
		printf("Enter name and surname of the teacher:\n");
		scanf("%i"); //bugs
		gets_s(name);
		int i = 0;
		while (iter != NULL) {
			iter = findNodeByTeacher(iter, name);
			if (iter != NULL) {
				if (i == 0)
					printf("============================================================Removed Teachers============================================================\n");
				printf("[Lesson Code: %i]  [Lesson AKTS: %i]  [Lesson Credit: %i]  [Lesson Name: %s]  [Lesson Teacher: %s]\n", iter->code, iter->akts, iter->credit, iter->name, iter->teacher);
				deleteNode(iter);
				iter = iter->next;
				i++;
			}
			else {
				if (i == 0)
					printf("Teacher coudnot find...\n");
				printf("\n");
				printList();
				return;
			}
		}
	}
	int code;
	printf("Enter the code of lesson:");
	scanf("%i", &code);
	iter = findNodeByCode(iter, code);
	if (iter != NULL) {
		printf("============================================================Removed Lesson============================================================\n");
		printf("[Lesson Code: %i]  [Lesson AKTS: %i]  [Lesson Credit: %i]  [Lesson Name: %s]  [Lesson Teacher: %s]\n\n", iter->code, iter->akts, iter->credit, iter->name, iter->teacher);
		deleteNode(iter);
		printList();
	}
	else {
		printf("Lesson code coudnot find...\n\n");
	}
	return;
}

void addNodeToNextOfTheLessonCode() {
	int lessonCode;
	printf("Enter an lesson code:");
	scanf("%i", &lessonCode);
	Lesson* iter = findNodeByCode(head, lessonCode);
	if (iter == foot) {											//you cant add to head this that command
		addNodeToFoot();									//that why we check just foot
		return;
	}
	Lesson* newNode = createNewNode();
	iter->next->prev = newNode;
	newNode->next = iter->next;
	iter->next = newNode;
	newNode->prev = iter;
	printList();
}

void bridgeLists() {
	foot->next = head2;
	head2->prev = foot;
	foot = foot2;
	if (isThisCircleList) {
		foot->next = head;
		head->prev = foot;
	}
}

void printActions() {
	printf("1  => Print List\n");
	printf("2  => Add lesson to head of list\n");
	printf("3  => Add lesson to foot of list\n");
	printf("4  => Add lesson to index wich you want\n");
	printf("5  => Find lessons by name\n");
	printf("6  => Find lessons by teacher\n");
	printf("7  => Find lesson by lesson code\n");
	printf("8  => Remove lessons by name\n");
	printf("9  => Remove lessons by teacher\n");
	printf("10 => Remove lesson by lesson code\n");
	printf("11 => Add Lesson to next of the lesson code\n");
	printf("12 => Bridge to Lists\n");
	printf("0  => Exit\n");
}

bool userScreen() {
	int number;
	printf("Enter a number:");
	scanf("%i", &number);
	switch (number) {
	case 0:
		return false;
	case 1:
		printList();
		return true;
	case 2:
		addNodeToHead();
		return true;
	case 3:
		addNodeToFoot();
		return true;
	case 4:
		addNodeToIndex();
		return true;
	case 5:
		findNodeAndWrite(1);
		return true;
	case 6:
		findNodeAndWrite(2);
		return true;
	case 7:
		findNodeAndWrite(3);
		return true;
	case 8:
		findNodeAndRemove(1);
		return true;
	case 9:
		findNodeAndRemove(2);
		return true;
	case 10:
		findNodeAndRemove(3);
		return true;
	case 11:
		addNodeToNextOfTheLessonCode();
		return true;
	case 12:
		bridgeLists();
		return true;
	default:
		printActions();
		return true;
	}
}







