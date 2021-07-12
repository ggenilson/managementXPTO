typedef struct {
	char id[10], type[50], status[10];
} operationType;

operationType operationTypeData[1001];

int contOperationType = 0;

void getFieldsToEditOp () {
	int i;
	for (i = 0; i < 2; i++) {
		printf("%s\n", fieldsOperationTypeToEdit[i]);
	}
}

void pastOperationTypeToData () {
	char * sub;
	int k, i;
	
	//Arquivo de entrada
	FILE *input = fopen(pathOperationType, "r");
    
    //Uma string larga o suficiente para extrair o texto total de cada linha
    char lineText[1001] = "";
    
    while(fgets(lineText, 1001, input)) {
	    sub = strtok(lineText, "#");
	    k = 0;
	    
	    strcpy(operationTypeData[contOperationType].id, sub);
	    
	    while (sub) {
	    	sub = strtok(NULL, "#");
	    	
	    	if (sub) {
	    		k++;
	    		if (k == 1) {
	    			strcpy(operationTypeData[contOperationType].type, sub);
				} else if (k == 2) {
					strcpy(operationTypeData[contOperationType].status, sub);
				}
			}
		}
		
		contOperationType++;
    }
    
    fclose(input);
    
    if (contOperationType > 0) {
    	getFieldsToEditOp();
	} else {
		printf("Tabela não possui algum dado para editar ...\n");
	}
}

int OpUpdate () {
	pastOperationTypeToData();
	
	setbuf(stdin, NULL);
	
	int id, ret = 0, field, i;
	char newValue[100];
	
	printf("Especifique o código do Tipo de Operação, para assim editar:\n");
	scanf("%d", &id);
	setbuf(stdin, NULL);
	
	printf("Qual campo quer editar: ");
	scanf("%d", &field);
	setbuf(stdin, NULL);

	for (i = 0; i < contOperationType; i++) {
		if (atoi(operationTypeData[i].id) == id) {
			ret = 1;
			
			if (field == 1) {
				printf("Novo valor: ");
				gets(newValue);
				setbuf(stdin, NULL);
	
				strcpy(operationTypeData[i].type, newValue);
				break;
			}
			
			if (field == 2) {
				char *auxStatus = getStatus(0);
				strcpy(operationTypeData[i].status, auxStatus);
				break;
			}	
		}
	}
	
	if (ret) {
		FILE *input = fopen(pathOperationType, "w+");
	
		for (i = 0; i < contOperationType; i++) {
			fprintf(input, "%s#%s#%s", operationTypeData[i].id, operationTypeData[i].type, operationTypeData[i].status);
		}
		
		fclose(input);
	}
	
	contOperationType = 0;
	
    return ret;
}
