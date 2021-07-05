typedef struct {
	char id[10], name[50], status[10];
	int type;
} company;

company companyData[1001];

int contCompany = 0;

void getFieldsToEditC () {
	int i;
	for (i = 0; i < 3; i++) {
		printf("%s\n", fieldsCompanyToEdit[i]);
	}
}

void pastCompanyToData () {
	char * sub;
	int k, i;
	
	//Arquivo de entrada
	FILE *input = fopen(pathCompany, "r");
    
    //Uma string larga o suficiente para extrair o texto total de cada linha
    char lineText[1001] = "";
    
    while(fgets(lineText, 1001, input)) {
	    sub = strtok(lineText, "#");
	    k = 0;
	    
	    strcpy(companyData[contCompany].id, sub);
	    
	    while (sub) {
	    	sub = strtok(NULL, "#");
	    	
	    	if (sub) {
	    		k++;
	    		
	    		if (k == 1) {
	    			strcpy(companyData[contCompany].name, sub);
				} else if (k == 2) {
	    			companyData[contCompany].type = atoi(sub);
				} else if (k == 3) {
					strcpy(companyData[contCompany].status, sub);
				}
			}
		}
		
		contCompany++;
    }
    
    fclose(input);
    
    if (contCompany > 0) {
    	getFieldsToEditC();
	} else {
		printf("Tabela não possui algum dado para editar ...\n");
	}
}

int Cupdate () {
	pastCompanyToData();
	
	setbuf(stdin, NULL);
	
	int id, ret = 0, field, i;
	char newCompany[100], newValue[100];
	
	printf("Especifique o código da Empresa, para assim editar:\n");
	scanf("%d", &id);
	setbuf(stdin, NULL);
	
	printf("Qual campo quer editar: ");
	scanf("%d", &field);
	setbuf(stdin, NULL);

	for (i = 0; i < contCompany; i++) {
		if (atoi(companyData[i].id) == id) {
			ret = 1;
			
			if (field == 1) {
				printf("Novo valor: ");
				gets(newValue);
				setbuf(stdin, NULL);
				strcpy(companyData[i].name, newValue);
				break;
			}
			
			if (field == 2) {
				printf("Selecione o novo Tipo de Empresa:\n");
				int values[] = { 1 };
				companyData[i].type = getFK(pathCompanyType, values, 1, 2);
				break;
			}
			
			if (field == 3) {
				char *auxStatus = getStatus(0);
				strcpy(companyData[i].status, auxStatus);
				break;
			}	
		}
	}
	
	if (ret) {
		FILE *input = fopen(pathCompany, "w+");
	
		for (i = 0; i < contCompany; i++) {
			fprintf(input, "%s#%s#%d>#%s", companyData[i].id, companyData[i].name, companyData[i].type, companyData[i].status);
		}
		
		fclose(input);
	}
	
	contCompany = 0;
	
    return ret;
}
