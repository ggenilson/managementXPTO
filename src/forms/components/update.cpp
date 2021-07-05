typedef struct {
	char id[10], type[50], status[10];
} component;

component componentData[1001];

int contComponent = 0;

void getFieldsToEditCp () {
	int i;
	for (i = 0; i < 2; i++) {
		printf("%s\n", fieldsComponentTypeToEdit[i]);
	}
}

void pastComponentToData () {
	char * sub;
	int k, i;
	
	//Arquivo de entrada
	FILE *input = fopen(pathComponent, "r");
    
    /*if (!input) {
    	return 0;
	}*/
    
    //Uma string larga o suficiente para extrair o texto total de cada linha
    char lineText[1001] = "";
    
    while(fgets(lineText, 1001, input)) {
	    sub = strtok(lineText, "#");
	    k = 0;
	    
	    strcpy(componentData[contComponent].id, sub);
	    
	    while (sub) {
	    	sub = strtok(NULL, "#");
	    	
	    	if (sub) {
	    		k++;
	    		if (k == 1) {
	    			strcpy(componentData[contComponent].type, sub);
				} else if (k == 2) {
					strcpy(componentData[contComponent].status, sub);
				}
			}
		}
		
		contComponent++;
    }
    
    fclose(input);
    
    if (contComponent > 0) {
    	getFieldsToEditCp();
	} else {
		printf("Tabela não possui algum dado para editar ...\n");
	}
}

int Cpupdate () {
	pastComponentToData();
	
	setbuf(stdin, NULL);
	
	int id, ret = 0, field, i;
	char newCompany[100], newValue[100];
	
	printf("Especifique o código do Componente, para assim editar:\n");
	scanf("%d", &id);
	setbuf(stdin, NULL);
	
	printf("Qual campo quer editar: ");
	scanf("%d", &field);
	setbuf(stdin, NULL);

	for (i = 0; i < contComponent; i++) {
		if (atoi(componentData[i].id) == id) {
			ret = 1;
			
			if (field == 1) {
				printf("Novo valor: ");
				gets(newValue);
				setbuf(stdin, NULL);
	
				strcpy(componentData[i].type, newValue);
				break;
			}
			
			if (field == 2) {
				char *auxStatus = getStatus(0);
				strcpy(componentData[i].status, auxStatus);
				break;
			}	
		}
	}
	
	if (ret) {
		FILE *input = fopen(pathComponent, "w+");
	
		for (i = 0; i < contComponent; i++) {
			fprintf(input, "%s#%s#%s", componentData[i].id, componentData[i].type, componentData[i].status);
		}
		
		fclose(input);
	}
	
	contComponent = 0;
	
    return ret;
}
