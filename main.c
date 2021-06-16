//Importando todas bibliotecas necess�rias para o funcionamento da Aplica��o
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

//Importando Fun��es de funcionamento geral
#include "./src/utils/sms.c"
#include "./src/utils/paths.c"
#include "./src/utils/index.c"
#include "./src/utils/consts.c"
#include "./src/forms/components.c"
#include "./src/utils/menusOptions.c"

//Importando Fun��es de Company Type
#include "./src/forms/companyType/index.c"
#include "./src/forms/companyType/store.c"
#include "./src/forms/companyType/delete.c"
#include "./src/forms/companyType/search.cpp"
#include "./src/forms/companyType/update.cpp"

int main() {
	setlocale(LC_ALL, "Portuguese");
	//fullScreen();
	system("color 70");
		
	textcolor(GREEN);
	
	//Vari�veis respons�veis por receber os valores das aplica��es
	int option, crudOption;
	
	//Vari�veis controladoras dos ciclos
	int control = 0, control1 = 0;
	
	//Vari�veis respons�veis por manipular as respostas
	int answer, res;
	char ans, help[2];
	
	do {
		//Chamando o menu principal
		getHeader();
		renderInitialOptions();
		scanf("%i", &option);
		
		if (option == 11) {
			//Terminando a Aplica��o
			exitApplication();
		} else if (option < 1 || option > 11) {
			int a = getQuestion(1);
		} else {
			do {
				//Chamando o menu para o CRUD (Inserir, Atualizar, Ler e Apagar)
				getAll(option, crudOption, 0);
				getNewLine(1);
				renderCrudOptions();
				scanf("%i", &crudOption);
			
				if (crudOption == 6) {
					system("cls");
					control1 = 1;
				} else if (crudOption > 6 || crudOption < 1) {
					int b = getQuestion(0);
					
					if (b == 10) {
						control1 = 1;
					}
				} else {
					getAll(option, crudOption, 1);
							
					if (option == 1) {
						Components();
					} else if (option == 2) {
						Components();
					} else if (option == 9) {
						//Lidando com o Tipo Empresa
						if (crudOption == 1) {
							//*****************************************************************
							//�rea para aloca��o do formul�rio para cadastro do Tipo de Empresa
							do {
								getAll(option, crudOption, 1);
								
								res = CTStore();
								
								ans = getAnswerColor(res, storeCompany, errStore);
							} while(ans == 's' || ans == 'S');
							
							system("cls");
						} else if (crudOption == 2) {
							do {
								getAll(option, crudOption, 1);
								
								res = CTupdate();
								
								ans = getAnswerColor(res, updateCompany, notFoundCompany);
							} while(ans == 's' || ans == 'S');
							
							system("cls");
						} else if (crudOption == 3) {
							do {
								getAll(option, crudOption, 1);
								
								res = CTdel();
								
								ans = getAnswerColor(res, deleteCompany, notFoundCompany);
							} while(ans == 's' || ans == 'S');
							
							system("cls");
						} else if (crudOption == 4) {
							getAll(option, crudOption, 1);
								
							res = CTgetCompanyTypes();
							
							system("cls");
						} else if (crudOption == 5) {
							getAll(option, crudOption, 1);
								
							res = CTsearch();
							
							system("cls");
						}
					}
				}
			} while(!control1);
		}
	} while(!control);

    return 0;
}
