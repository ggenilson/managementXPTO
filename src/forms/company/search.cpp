int fieldsSearchCompany[5];
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
			printf("%d? campo: ", j + 1);
			scanf("%d", &fieldsSearchCompany[j]);
			fieldsSearchCompany[j] = fieldsSearchCompany[j] - 1;
			setbuf(stdin, NULL);
		}
		
		printf("\nPesquisa: ");
		gets(searchCompany);
		setbuf(stdin, NULL);
		
		printf("\nResultado encontrado:\n");
	} else {
		printf("Valor inv?lido!\n");
	}
}

int Csearch () {
	char * fields[] = { "ID", "NOME", "TIPO", "ESTADO" };
	
	getTypesSearchC();
	
	char *fks[] = { pathCompanyType };
	int fksFieldsShow[] = { 1 };
	int endLineFK[] = { 2 };
	
	return getEntityFKSearch(fields, pathCompany, 3, fks, fksFieldsShow, endLineFK, fieldsSearchCompany, nFields, searchCompany);
}
