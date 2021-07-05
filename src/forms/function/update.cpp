typedef struct {
	char id[10], function[50], status[10];
} function;

function functionData[1001];

int contFunction = 0;

void getFieldsToEditFc () {
	int i;
	for (i = 0; i < 2; i++) {
		printf("%s\n", fieldsCompanyTypeToEdit[i]);
	}
}

void pastFunctionToData () {
	char * sub;
	int k, i;
	
	//Arquivo de entrada
	FILE *input = fopen(pathCompanyType, "r");
    
    /*if (!input) {
    	return 0;
	}*/
    
    //Uma string larga o suficiente para extrair o texto total de cada linha
    char lineText[1001] = "";
    
    while(fgets(lineText, 1001, input)) {
	    sub = strtok(lineText, "#");
	    k = 0;
	    
	    strcpy(functionData[contFunction].id, sub);
	    
	    while (sub) {
	    	sub = strtok(NULL, "#");
	    	
	    	if (sub) {
	    		k++;
	    		if (k == 1) {
	    			strcpy(functionData[contFunction].function, sub);
				} else if (k == 2) {
					strcpy(functionData[contFunction].status, sub);
				}
			}
		}
		
		contFunction++;
    }
    
    fclose(input);
    
    if (contFunction > 0) {
    	getFieldsToEditFc();
	} else {
		printf("Tabela não possui algum dado para editar ...\n");
	}
}

int FcUpdate () {
	pastFunctionToData();
	
	setbuf(stdin, NULL);
	
	int id, ret = 0, field, i;
	char newCompany[100], newValue[100];
	
	printf("Especifique o código da Empresa, para assim editar:\n");
	scanf("%d", &id);
	setbuf(stdin, NULL);
	
	printf("Qual campo quer editar: ");
	scanf("%d", &field);
	setbuf(stdin, NULL);

	for (i = 0; i < contFunction; i++) {
		if (atoi(functionData[i].id) == id) {
			ret = 1;
			
			if (field == 1) {
				printf("Novo valor: ");
				gets(newValue);
				setbuf(stdin, NULL);
	
				strcpy(functionData[i].function, newValue);
				break;
			}
			
			if (field == 2) {
				char *auxStatus = getStatus(0);
				strcpy(functionData[i].status, auxStatus);
				break;
			}	
		}
	}
	
	if (ret) {
		FILE *input = fopen(pathFunction, "w+");
	
		for (i = 0; i < contFunction; i++) {
			fprintf(input, "%s#%s#%s", functionData[i].id, functionData[i].function, functionData[i].status);
		}
		
		fclose(input);
	}
	
	contFunction = 0;
	
    return ret;
}
