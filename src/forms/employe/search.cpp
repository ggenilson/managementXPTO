int fieldsSearchEmployee[4];
int nFields;
char searchEmployee[100];

void getTypesSearchE () {
	int i, j;
	
	for (i = 0; i < 4; i++) {
		printf("%s\n", fieldsCompanyType[i]);
	}
	
	printf("\nPor quantos campos quer pesquisar?\n");
	scanf("%d", &nFields);
	setbuf(stdin, NULL);
	
	if (nFields <= 4 && nFields >= 1) {
		for (j = 0; j < nFields; j++) {
			printf("%d? campo: ", j + 1);
			scanf("%d", &fieldsSearchCompanyType[j]);
			fieldsSearchCompanyType[j] = fieldsSearchCompanyType[j] - 1;
			setbuf(stdin, NULL);
		}
		
		printf("\nPesquisa: ");
		gets(searchCompanyType);
		setbuf(stdin, NULL);
		
		printf("\n\nResultado encontrado:\n");
	} else {
		printf("Valor inv?lido!\n");
	}
}

int Esearch () {
	char * fields[] = { "ID", "TIPO", "ESTADO" };
	
	getTypesSearchE();
	
	return getEntitySearch(fields, pathCompanyType, 3, fieldsSearchCompanyType, nFields, searchCompanyType);
}
