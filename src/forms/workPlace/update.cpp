typedef struct {    
    char id[5];
    char designation[100];
    char place[100];
    char section[100];
    char desc[100];
    int idEmploye;
    char status[10];
} workplace;

workplace workplaceData[1001];

int contWorkPlace = 0;

void getFieldsToEditWp () {
	int i;
	for (i = 0; i < 5; i++) {
		printf("%s\n", fieldsWorkPlaceToEdit[i]);
	}
}

void pastWorkPlaceToData () {
	char * sub;
	int k, i;
	
	//Arquivo de entrada
	FILE *input = fopen(pathWorkPlace, "r");
    
    //Uma string larga o suficiente para extrair o texto total de cada linha
    char lineText[1001] = "";
    
    while(fgets(lineText, 1001, input)) {
	    sub = strtok(lineText, "#");
	    k = 0;
	    
	    strcpy(workplaceData[contWorkPlace].id, sub);
	    
	    while (sub) {
	    	sub = strtok(NULL, "#");
	    	
	    	if (sub) {
	    		k++;
	    		
	    		if (k == 1) {
	    			strcpy(workplaceData[contWorkPlace].designation, sub);
				} else if (k == 2) {
	    			strcpy(workplaceData[contWorkPlace].place, sub);
				} else if (k == 3) {
					strcpy(workplaceData[contWorkPlace].section, sub);
				} else if (k == 4) {
					strcpy(workplaceData[contWorkPlace].desc, sub);
				} else if (k == 5) {
					workplaceData[contWorkPlace].idEmploye = atoi(sub);
				} else if (k == 6) {
					strcpy(workplaceData[contWorkPlace].status, sub);
				}
			}
		}
		
		contWorkPlace++;
    }
    
    fclose(input);
    
    if (contWorkPlace > 0) {
    	getFieldsToEditWp();
	} else {
		printf("Tabela não possui algum dado para editar ...\n");
	}
}

int Wpupdate () {
	pastWorkPlaceToData();
	
	setbuf(stdin, NULL);
	
	int id, ret = 0, field, i;
	char newValue[100];
	
	printf("Especifique o código do Posto de Trabalho, para assim editar:\n");
	scanf("%d", &id);
	setbuf(stdin, NULL);
	
	printf("Qual campo quer editar: ");
	scanf("%d", &field);
	setbuf(stdin, NULL);

	for (i = 0; i < contWorkPlace; i++) {
		if (atoi(workplaceData[i].id) == id) {
			ret = 1;
			
			if (field != 5 && field != 6) {
				printf("Novo valor: ");
				gets(newValue);
				setbuf(stdin, NULL);
				
				if (field == 1) {
					strcpy(workplaceData[i].designation, newValue);
				} else if (field == 2) {
					strcpy(workplaceData[i].place, newValue);
				} else if (field == 3) {
					strcpy(workplaceData[i].section, newValue);
				} else if (field == 4) {
					strcpy(workplaceData[i].desc, newValue);
				}
				
				break;
			}
			
			if (field == 5) {
				printf("Selecione o novo Funcionário:\n");
				int values[] = { 1 };
				workplaceData[i].idEmploye = getFK(pathEmploye, values, 1, 4);
				break;
			}
			
			if (field == 6) {
				char *auxStatus = getStatus(0);
				strcpy(workplaceData[i].status, auxStatus);
				break;
			}	
		}
	}
	
	if (ret) {
		FILE *input = fopen(pathWorkPlace, "w+");
	
		for (i = 0; i < contWorkPlace; i++) {
			fprintf(input, "%s#%s#%s#%s#%s#%d>#%s\n", workplaceData[i].id, workplaceData[i].designation, workplaceData[i].place, workplaceData[i].section, workplaceData[i].desc, workplaceData[i].idEmploye, workplaceData[i].status);
		}
		
		fclose(input);
	}
	
	contWorkPlace = 0;
	
    return ret;
}
