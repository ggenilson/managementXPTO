int fieldsSearchCompanyType[4];
int nFields;

void getTypesSearch () {
	int i, j;
	
	for (i = 0; i < 4; i++) {
		printf("%s\n", fieldsCompanyType[i]);
	}
	
	printf("\nPor quantos campos quer pesquisar?\n");
	scanf("%d", &nFields);
	
	if (nFields <= 4) {
		for (j = 0; j < nFields; j++) {
			printf("%dº campo: ", j + 1);
			scanf("%d", &fieldsSearchCompanyType[j]);
		}
	}
	
	printf("\n");
}

int CTsearch () {
	char * fields[] = { "ID", "TIPO", "Estado" };
	
	getTypesSearch();
	
	//Arquivo de entrada
	FILE *input = fopen(pathCompanyType, "r");
	
	return getEntitySearch(fields, input, 3, fieldsCompanyType, fieldsSearchCompanyType, nFields);
}
