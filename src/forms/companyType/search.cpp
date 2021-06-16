int fieldsSearchCompanyType[4];
int nFields;
char searchCompanyType[100];

void getTypesSearch () {
	int i, j;
	
	for (i = 0; i < 4; i++) {
		printf("%s\n", fieldsCompanyType[i]);
	}
	
	printf("\nPor quantos campos quer pesquisar?\n");
	scanf("%d", &nFields);
	setbuf(stdin, NULL);
	
	if (nFields <= 4 && nFields >= 1) {
		for (j = 0; j < nFields; j++) {
			printf("%dº campo: ", j + 1);
			scanf("%d", &fieldsSearchCompanyType[j]);
			fieldsSearchCompanyType[j] = fieldsSearchCompanyType[j] - 1;
			setbuf(stdin, NULL);
		}
		
		printf("\nPesquisa: ");
		gets(searchCompanyType);
		setbuf(stdin, NULL);
		
		printf("\n\nResultado encontrado:\n");
	} else {
		printf("Valor inválido!\n");
	}
}

int CTsearch () {
	char * fields[] = { "ID", "TIPO", "ESTADO" };
	
	getTypesSearch();
	
	//Arquivo de entrada
	FILE *input = fopen(pathCompanyType, "r");
	
	return getEntitySearch(fields, input, 3, fieldsCompanyType, fieldsSearchCompanyType, nFields, searchCompanyType);
}
