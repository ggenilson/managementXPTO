int fieldsSearchComponentType[4];
int nFields;
char searchComponentType[100];

void getTypesSearchCpT () {
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
			scanf("%d", &fieldsSearchComponentType[j]);
			fieldsSearchComponentType[j] = fieldsSearchComponentType[j] - 1;
			setbuf(stdin, NULL);
		}
		
		printf("\nPesquisa: ");
		gets(searchComponentType);
		setbuf(stdin, NULL);
		
		printf("\n\nResultado encontrado:\n");
	} else {
		printf("Valor inválido!\n");
	}
}

int CpTsearch () {
	char * fields[] = { "ID", "COMPON", "ESTADO" };
	
	getTypesSearchCpT();
	
	return getEntitySearch(fields, pathComponentType, 3, fieldsSearchComponentType, nFields, searchComponentType);
}
