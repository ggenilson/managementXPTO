#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "./src/utils/sms.c"
#include "./src/utils/paths.c"
#include "./src/utils/index.c"
#include "./src/utils/consts.c"
#include "./src/forms/components.c"
#include "./src/forms/companyType/store.c"
#include "./src/utils/menusOptions.c"

int main() {
	setlocale(LC_ALL, "Portuguese");
	fullScreen();
	system("color 70");
		
	textcolor(GREEN);
	
	//Variáveis responsáveis por receber os valores das oplicações
	int option, crudOption;
	
	//Variáveis controladoras dos ciclos
	int control = 0, control1 = 0;
	
	//Variáveis responsáveis por manipular as respostas
	int answer, res;
	char ans, help[2];
	
	do {
		//Chamando o menu principal
		getHeader();
		renderInitialOptions();
		scanf("%i", &option);
		
		if (option == 11) {
			//Terminando a Aplicação
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
						if (crudOption == 1) {
							//*****************************************************************
							//Área para alocação do formulário para cadastro do Tipo de Empresa
							do {
								getAll(option, crudOption, 1);
								
								res = CTStore();
								
								if (res) {
									textcolor(BLUE);
									printf("\nTipo de empresa 'INSERIDA' com sucesso!\n");
								} else {
									textcolor(RED);
									printf("\nErro inesperado!\nSugestão: Verifique o caminho do ficheiro!\n");
								}
								
								textcolor(GREEN);
								
								printf("\nAinda pretende 'INSERIR'?\n(s/n)\n");
								scanf(" %c", &ans);
							} while(ans == 's' || ans == 'S');
							
							system("cls");
						}
					}
				}
			} while(!control1);
		}
	} while(!control);

    return 0;
}
