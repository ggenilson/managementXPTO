int fieldsSearchOperationType[4];
int nFields;
char searchOperationType[100];

void getTypesSearchOp () {
	int i, j;
	
	for (i = 0; i < 4; i++) {
		printf("%s\n", fieldsOperationType[i]);
	}
	
	printf("\nPor quantos campos quer pesquisar?\n");
	scanf("%d", &nFields);
	setbuf(stdin, NULL);
	
	if (nFields <= 4 && nFields >= 1) {
		for (j = 0; j < nFields; j++) {
			printf("%dº campo: ", j + 1);
			scanf("%d", &fieldsSearchOperationType[j]);
			fieldsSearchOperationType[j] = fieldsSearchOperationType[j] - 1;
			setbuf(stdin, NULL);
		}
		
		printf("\nPesquisa: ");
		gets(searchOperationType);
		setbuf(stdin, NULL);
		
		printf("\n\nResultado encontrado:\n");
	} else {
		printf("Valor inválido!\n");
	}
}

int Opsearch () {
	char * fields[] = { "ID", "TIPO", "ESTADO" };
	
	getTypesSearchOp();
	
	return getEntitySearch(fields, pathOperationType, 3, fieldsSearchOperationType, nFields, searchOperationType);
}
