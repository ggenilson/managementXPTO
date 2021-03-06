typedef struct {
	char id[10], type[50], status[10];
} companyType;

companyType companyTypeData[1001];

int contCompanyType = 0;

void getFieldsToEditCT () {
	int i;
	for (i = 0; i < 2; i++) {
		printf("%s\n", fieldsCompanyTypeToEdit[i]);
	}
}

void pastCompanyTypeToData () {
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
	    
	    strcpy(companyTypeData[contCompanyType].id, sub);
	    
	    while (sub) {
	    	sub = strtok(NULL, "#");
	    	
	    	if (sub) {
	    		k++;
	    		if (k == 1) {
	    			strcpy(companyTypeData[contCompanyType].type, sub);
				} else if (k == 2) {
					strcpy(companyTypeData[contCompanyType].status, sub);
				}
			}
		}
		
		contCompanyType++;
    }
    
    fclose(input);
    
    if (contCompanyType > 0) {
    	getFieldsToEditCT();
	} else {
		printf("Tabela n?o possui algum dado para editar ...\n");
	}
}

int CTupdate () {
	pastCompanyTypeToData();
	
	setbuf(stdin, NULL);
	
	int id, ret = 0, field, i;
	char newCompany[100], newValue[100];
	
	printf("Especifique o c?digo da Empresa, para assim editar:\n");
	scanf("%d", &id);
	setbuf(stdin, NULL);
	
	printf("Qual campo quer editar: ");
	scanf("%d", &field);
	setbuf(stdin, NULL);

	for (i = 0; i < contCompanyType; i++) {
		if (atoi(companyTypeData[i].id) == id) {
			ret = 1;
			
			if (field == 1) {
				printf("Novo valor: ");
				gets(newValue);
				setbuf(stdin, NULL);
	
				strcpy(companyTypeData[i].type, newValue);
				break;
			}
			
			if (field == 2) {
				char *auxStatus = getStatus(0);
				strcpy(companyTypeData[i].status, auxStatus);
				break;
			}	
		}
	}
	
	if (ret) {
		FILE *input = fopen(pathCompanyType, "w+");
	
		for (i = 0; i < contCompanyType; i++) {
			fprintf(input, "%s#%s#%s", companyTypeData[i].id, companyTypeData[i].type, companyTypeData[i].status);
		}
		
		fclose(input);
	}
	
	contCompanyType = 0;
	
    return ret;
}
