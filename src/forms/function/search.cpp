int fieldsSearchFunction[4];
int nFields;
char searchFunction[100];

void getTypesSearchFc() {
	int i, j;
	
	for (i = 0; i < 4; i++) {
		printf("%s\n", fieldsFunction[i]);
	}
	
	printf("\nPor quantos campos quer pesquisar?\n");
	scanf("%d", &nFields);
	setbuf(stdin, NULL);
	
	if (nFields <= 4 && nFields >= 1) {
		for (j = 0; j < nFields; j++) {
			printf("%d� campo: ", j + 1);
			scanf("%d", &fieldsSearchFunction[j]);
			fieldsSearchFunction[j] = fieldsSearchFunction[j] - 1;
			setbuf(stdin, NULL);
		}
		
		printf("\nPesquisa: ");
		gets(searchFunction);
		setbuf(stdin, NULL);
		
		printf("\n\nResultado encontrado:\n");
	} else {
		printf("Valor inv�lido!\n");
	}
}

int Fcsearch () {
	char * fields[] = { "ID", "FUN��O", "ESTADO" };
	
	getTypesSearchFc();
	
	return getEntitySearch(fields, pathFunction, 3, fieldsSearchFunction, nFields, searchFunction);
}
