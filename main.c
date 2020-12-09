#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include"Student.h"

int main() {
	srand(time(NULL));

	Student* list = createrandomstudent();

	while (1)
	{
		printf("1. Add \n2. Add random\n3. Show list\n4. Delete student by number\n5. Delete student by surname\n6. Delete bad students\n7. Show mates\n8. Show good students\n9. Output into file\na. Read from file\nb. Show by surname\n");
		char choose;
		choose = _getch();
		switch (choose)
		{
		case '1':
		{
			add(&list, FALSE);
			break;
		}
		case '2':
		{
			add(&list, TRUE);
			break;
		}
		case '3':
		{
			output(list);
			break;
		}
		case '4':
		{
			int student;
			scanf_s("%d", &student);
			list = deletestudent(list, student);
			break;
		}
		case '5':
		{
			char surname[256];
			gets_s(surname, 256);
			deletebysurname(list, surname);
			break;
		}
		case '6':
		{
			list = deletebadstudents(list);
			break;
		}
		case '7':
		{
			char group[256];
			gets_s(group, 256);
			outputmates(list, group);
			break;
		}
		case '8':
		{
			outputgoodstudents(list);
			break;
		}
		case '9':
		{
			puttofile(list);
			break;
		}
		case 'a':
		{
			loadfromfile(&list);
			break;
		}
		case 'b':
		{
			char surname[256];
			gets_s(surname, 256);
			outputbysurname(list, surname);
			break;
		}

		}
	}

	system("pause");
	return 0;
}


