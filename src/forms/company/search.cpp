int fieldsSearchCompany[4];
int nFields;
char searchCompany[100];

void getTypesSearchC () {
	int i, j;
	
	for (i = 0; i < 5; i++) {
		printf("%s\n", fieldsCompany[i]);
	}
	
	printf("\nPor quantos campos quer pesquisar?\n");
	scanf("%d", &nFields);
	setbuf(stdin, NULL);
	
	if (nFields <= 5 && nFields >= 1) {
		for (j = 0; j < nFields; j++) {
			printf("%dº campo: ", j + 1);
			scanf("%d", &fieldsSearchCompany[j]);
			fieldsSearchCompany[j] = fieldsSearchCompany[j] - 1;
			setbuf(stdin, NULL);
		}
		
		printf("\nPesquisa: ");
		gets(searchCompany);
		setbuf(stdin, NULL);
		
		printf("\n\nResultado encontrado:\n");
	} else {
		printf("Valor inválido!\n");
	}
}

int Csearch () {
	char * fields[] = { "ID", "NOME", "TIPO", "ESTADO" };
	
	getTypesSearchC();
	
	return getEntitySearch(fields, pathCompany, 3, fieldsSearchCompany, nFields, searchCompany);
}
