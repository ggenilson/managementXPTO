int fieldsSearchComponent[4];
int nFields;
char searchComponent[100];

void getTypesSearchCp () {
	int i, j;
	
	for (i = 0; i < 4; i++) {
		printf("%s\n", fieldsComponentType[i]);
	}
	
	printf("\nPor quantos campos quer pesquisar?\n");
	scanf("%d", &nFields);
	setbuf(stdin, NULL);
	
	if (nFields <= 4 && nFields >= 1) {
		for (j = 0; j < nFields; j++) {
			printf("%dº campo: ", j + 1);
			scanf("%d", &fieldsSearchComponent[j]);
			fieldsSearchComponent[j] = fieldsSearchComponent[j] - 1;
			setbuf(stdin, NULL);
		}
		
		printf("\nPesquisa: ");
		gets(searchComponent);
		setbuf(stdin, NULL);
		
		printf("\n\nResultado encontrado:\n");
	} else {
		printf("Valor inválido!\n");
	}
}

int Cpsearch () {
	char * fields[] = { "ID", "COMPON", "ESTADO" };
	
	getTypesSearchCp();
	
	return getEntitySearch(fields, pathComponent, 3, fieldsSearchComponent, nFields, searchComponent);
}
