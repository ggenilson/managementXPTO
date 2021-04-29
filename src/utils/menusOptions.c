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
	"Apagar",
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
	
	printf("------------------------------\n");

	for (j = 0; j < length; j++) {
		if (j < 9) {
			printf("%d -  %s\n", j + 1, initialOptions[j]);
		} else {
			printf("%d - %s\n", j + 1, initialOptions[j]);
		}

		printf("------------------------------\n");
	}
	
	getNewLine(1);
}

void renderCrudOptions () {
	int j;
	int length = sizeof(crudOptions) / sizeof(crudOptions[0]);
	
	printf("------------------------------\n");
	
	for (j = 0; j < length; j++) {
		printf("%d -  %s\n", j + 1, crudOptions[j]);
		printf("------------------------------\n");
	}
	
	getNewLine(1);
}
