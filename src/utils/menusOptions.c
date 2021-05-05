char * initialOptions[] = {
	"Gerir Componentes",
    "Gerir Tipo de Componentes",
    "Gerir Posto de Trabalho",
	"Gerir Funcionário",
	"Gerir Função",
	"Gerir Operações",
	"Gerir Tipo de Operações",
	"Gerir Empresa",
	"Gerir Tipo de Empresa",
	"Gerir Contacto",
	"Sair"
};

char * crudOptions[] = {
	"Inserir",
	"Alterar",
	"Eliminar",
	"Listar",
	"Pesquisar",
	"Voltar"
};

void getNewLine (int number) {
	int i = 0;
	
	for (i = 0; i < number; i++) {
		printf("\n");
	}
}

void getHeader () {
	printf("--------------------------------------------------------------------------- XPTO MANAGEMENT ----------------------------------------------------------------------------");
	getNewLine(2);
}

void renderInitialOptions () {
	int j;
	int length = sizeof(initialOptions) / sizeof(initialOptions[0]);
	
	printf("-----------------------------------\n");

	for (j = 0; j < length; j++) {
		if (j < 9) {
			printf("%d  ->  %s\n", j + 1, initialOptions[j]);
		} else {
			printf("%d ->  %s\n", j + 1, initialOptions[j]);
		}

		printf("-----------------------------------\n");
	}
	
	getNewLine(1);
	
	printf("Escolha uma opção (1, 2, ... ou %d):\n", length);
}

void renderCrudOptions () {
	int j;
	int length = sizeof(crudOptions) / sizeof(crudOptions[0]);
	
	printf("-----------------------------------\n");
	
	for (j = 0; j < length; j++) {
		printf("%d ->  %s\n", j + 1, crudOptions[j]);
		printf("-----------------------------------\n");
	}
	
	getNewLine(1);
	
	printf("Escolha uma opção (1, 2 ... ou %d):\n", length);
}

//Função responsável por trazer o Header e a escrita dos menus e submenus selecioandos
void getAll (int opt, int cdOpt, int type) {
	system("cls");
	getHeader();
	printf("Menu    -> %s\n", initialOptions[opt - 1]);
	
	if (type) {
		printf("Submenu -> %s\n\n", crudOptions[cdOpt - 1]);
	}
}
