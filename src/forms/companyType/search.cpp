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
	
	if (nFields <= 4) {
		for (j = 0; j < nFields; j++) {
			printf("%dº campo: ", j + 1);
			scanf("%d", &fieldsSearchCompanyType[j]);
			setbuf(stdin, NULL);
		}
	}
	
	printf("\nPesquisa: ");
	gets(searchCompanyType);
	setbuf(stdin, NULL);
}

int CTsearch () {
	char * fields[] = { "ID", "TIPO", "Estado" };
	
	getTypesSearch();
	
	//Arquivo de entrada
	FILE *input = fopen(pathCompanyType, "r");
	
	return getEntitySearch(fields, input, 3, fieldsCompanyType, fieldsSearchCompanyType, nFields, searchCompanyType);
}
