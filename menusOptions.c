char * initialOptions[] = {
	"Gerir Componentes",
    "Gerir Tipo de Componentes",
    "Gerir Posto de Trabalho",
	"Gerir Funcionario",
	"Gerir Funcao",
	"Gerir Operacoes",
	"Gerir Tipo de Operacoes",
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


void renderInitialOptions () {
	int j;
	int length = sizeof(initialOptions) / sizeof(initialOptions[0]);
	
	for (j = 0; j < length; j++) {
		printf("%d - %s\n", j + 1, initialOptions[j]);
	}
	
	getNewLine(1);
}

void renderCrudOptions () {
	int j;
	int length = sizeof(crudOptions) / sizeof(crudOptions[0]);
	
	for (j = 0; j < length; j++) {
		printf("%d -  %s\n", j + 1, crudOptions[j]);
	}
	
	getNewLine(1);
}
