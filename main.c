//Importando todas bibliotecas necessárias para o funcionamento da Aplicação
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

//Importando Funções de funcionamento geral
#include "./src/utils/sms.c"
#include "./src/utils/paths.c"
#include "./src/utils/index.c"
#include "./src/utils/consts.c"
#include "./src/utils/menusOptions.c"
#include "./src/utils/renderOptions.c"

//Importando Funções de Company Type
#include "./src/forms/companyType/index.c"
#include "./src/forms/companyType/store.c"
#include "./src/forms/companyType/delete.c"
#include "./src/forms/companyType/search.cpp"
#include "./src/forms/companyType/update.cpp"

//Importando Funções de Company
#include "./src/forms/company/index.c"
#include "./src/forms/company/store.c"
#include "./src/forms/company/delete.c"
#include "./src/forms/company/search.cpp"
#include "./src/forms/company/update.cpp"

//Importando Funções de Component Type
#include "./src/forms/componentType/index.c"
#include "./src/forms/componentType/store.c"
#include "./src/forms/componentType/delete.c"
#include "./src/forms/componentType/search.cpp"
#include "./src/forms/componentType/update.cpp"

//Importando Funções de Function
#include "./src/forms/function/index.c"
#include "./src/forms/function/store.c"
#include "./src/forms/function/delete.c"
#include "./src/forms/function/search.cpp"
#include "./src/forms/function/update.cpp"

//Importando Funções de Employe
#include "./src/forms/employe/index.c"
#include "./src/forms/employe/store.c"
#include "./src/forms/employe/delete.c"
#include "./src/forms/employe/search.cpp"
#include "./src/forms/employe/update.cpp"

//Importando Funções de WorkPlace
#include "./src/forms/workPlace/index.c"
#include "./src/forms/workPlace/store.c"
#include "./src/forms/workPlace/delete.c"
//#include "./src/forms/workPlace/search.cpp"
#include "./src/forms/workPlace/update.cpp"

//Importando Funções de Components
#include "./src/forms/components/index.c"
#include "./src/forms/components/store.c"
#include "./src/forms/components/delete.c"
#include "./src/forms/components/search.cpp"
#include "./src/forms/components/update.cpp"

int main() {
	setlocale(LC_ALL, "Portuguese");
	fullScreen();
	system("color 70");
		
	textcolor(GREEN);
	
	//Variáveis responsáveis por receber os valores das aplicações
	int option, crudOption;
	
	//Variáveis controladoras dos ciclos
	int control = 0, control1 = 0;
	
	//Variáveis responsáveis por manipular as respostas
	int answer;
	char help[2];
	
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
						ComponentsOptions(option, crudOption);
					} else if (option == 2) {
						//Lidando com o Tipo Componente
						ComponentTypeOptions(option, crudOption);
					} else if (option == 3) {
						//Lidando com o Posto de Trabalho
						WorkPlaceOptions(option, crudOption);
					} else if (option == 4) {
						//Lidando com o Funcionário
						EmployeOptions(option, crudOption);
					} else if (option == 5) {
						//Lidando com a Função
						FunctionOptions(option, crudOption);
					} else if (option == 8) {
						//Lidando com a Empresa
						CompanyOptions(option, crudOption);
					} else if (option == 9) {
						//Lidando com o Tipo Empresa
						CompanyTypeOptions(option, crudOption);
					}
				}
			} while(!control1);
		}
	} while(!control);

    return 0;
}
