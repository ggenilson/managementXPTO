typedef struct {
	char id[10], type[50], status[10];
} componentType;

componentType componentTypeData[1001];

int contComponentType = 0;

void getFieldsToEditCpT () {
	int i;
	for (i = 0; i < 2; i++) {
		printf("%s\n", fieldsComponentTypeToEdit[i]);
	}
}

void pastComponentTypeToData () {
	char * sub;
	int k, i;
	
	//Arquivo de entrada
	FILE *input = fopen(pathComponentType, "r");
    
    /*if (!input) {
    	return 0;
	}*/
    
    //Uma string larga o suficiente para extrair o texto total de cada linha
    char lineText[1001] = "";
    
    while(fgets(lineText, 1001, input)) {
	    sub = strtok(lineText, "#");
	    k = 0;
	    
	    strcpy(componentTypeData[contComponentType].id, sub);
	    
	    while (sub) {
	    	sub = strtok(NULL, "#");
	    	
	    	if (sub) {
	    		k++;
	    		if (k == 1) {
	    			strcpy(componentTypeData[contComponentType].type, sub);
				} else if (k == 2) {
					strcpy(componentTypeData[contComponentType].status, sub);
				}
			}
		}
		
		contComponentType++;
    }
    
    fclose(input);
    
    if (contComponentType > 0) {
    	getFieldsToEditCpT();
	} else {
		printf("Tabela não possui algum dado para editar ...\n");
	}
}

int CpTupdate () {
	pastComponentTypeToData();
	
	setbuf(stdin, NULL);
	
	int id, ret = 0, field, i;
	char newCompany[100], newValue[100];
	
	printf("Especifique o código do Componente, para assim editar:\n");
	scanf("%d", &id);
	setbuf(stdin, NULL);
	
	printf("Qual campo quer editar: ");
	scanf("%d", &field);
	setbuf(stdin, NULL);

	for (i = 0; i < contComponentType; i++) {
		if (atoi(componentTypeData[i].id) == id) {
			ret = 1;
			
			if (field == 1) {
				printf("Novo valor: ");
				gets(newValue);
				setbuf(stdin, NULL);
	
				strcpy(componentTypeData[i].type, newValue);
				break;
			}
			
			if (field == 2) {
				char *auxStatus = getStatus(0);
				strcpy(componentTypeData[i].status, auxStatus);
				break;
			}	
		}
	}
	
	if (ret) {
		FILE *input = fopen(pathComponentType, "w+");
	
		for (i = 0; i < contComponentType; i++) {
			fprintf(input, "%s#%s#%s", componentTypeData[i].id, componentTypeData[i].type, componentTypeData[i].status);
		}
		
		fclose(input);
	}
	
	contComponentType = 0;
	
    return ret;
}
