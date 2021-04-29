#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "./src/utils/sms.c"
#include "./src/utils/index.c"
#include "./src/utils/consts.c"
#include "./src/forms/Components.c"
#include "./src/utils/menusOptions.c"

int main() {
	setlocale(LC_ALL, "Portuguese");
	fullScreen();
	system("color 70");
		
	textcolor(GREEN);
	
	int option, crudOption, control = 0, answer;
	char ans;
	
	do {
		//Chamando o menu principal
		getHeader();
		renderInitialOptions();
		scanf("%i", &option);
		
		if (option == 11) {
			exitApplication();
		} else if (option < 1 || option > 11) {
			printf("\nOpção inválida\n\n");

			if (getAnswer(sms)) {
				system("cls");
			} else {
				exit(1);
			}
		} else {
			//Chamando o menu para o CRUD
			system("cls");
			getHeader();
			printf("Menu -> %s\n\n", initialOptions[option - 1]);
			renderCrudOptions();
			scanf("%i", &crudOption);
			
			if (crudOption == 6) {
				system("cls");
			} else {
				system("cls");
				getHeader();
				printf("Menu    -> %s\n", initialOptions[option - 1]);
				printf("Submenu -> %s\n\n", crudOptions[crudOption - 1]);
						
				if (crudOption == 1) {
					Components();
				} else if (crudOption == 2) {
					Components();
				}
			}
		}
	} while(control == 0);

    return 0;
}
