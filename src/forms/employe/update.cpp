typedef struct {
	char id[5];
    char name[100];
    int idFunction;
    char desc[100];
    char status[10];
} employe;

employe employeData[1001];

int contEmploye = 0;

void getFieldsToEditEp () {
	int i;
	for (i = 0; i < 4; i++) {
		printf("%s\n", fieldsEmployeToEdit[i]);
	}
}

void pastEmployeToData () {
	char * sub;
	int k, i;
	
	//Arquivo de entrada
	FILE *input = fopen(pathEmploye, "r");
    
    //Uma string larga o suficiente para extrair o texto total de cada linha
    char lineText[1001] = "";
    
    while(fgets(lineText, 1001, input)) {
	    sub = strtok(lineText, "#");
	    k = 0;
	    
	    strcpy(employeData[contEmploye].id, sub);
	    
	    while (sub) {
	    	sub = strtok(NULL, "#");
	    	
	    	if (sub) {
	    		k++;
	    		
	    		if (k == 1) {
	    			strcpy(employeData[contEmploye].name, sub);
				} else if (k == 2) {
	    			employeData[contEmploye].idFunction = atoi(sub);
				} else if (k == 3) {
					strcpy(employeData[contEmploye].desc, sub);
				} else if (k == 4) {
					strcpy(employeData[contEmploye].status, sub);
				}
			}
		}
		
		contEmploye++;
    }
    
    fclose(input);
    
    if (contEmploye > 0) {
    	getFieldsToEditEp();
	} else {
		printf("Tabela não possui algum dado para editar ...\n");
	}
}

int Epupdate () {
	pastEmployeToData();
	
	setbuf(stdin, NULL);
	
	int id, ret = 0, field, i;
	char newValue[100];
	
	printf("Especifique o código do Funcionário, para assim editar:\n");
	scanf("%d", &id);
	setbuf(stdin, NULL);
	
	printf("Qual campo quer editar: ");
	scanf("%d", &field);
	setbuf(stdin, NULL);

	for (i = 0; i < contEmploye; i++) {
		if (atoi(employeData[i].id) == id) {
			ret = 1;
			
			if (field == 1 || field == 3) {
				printf("Novo valor: ");
				gets(newValue);
				setbuf(stdin, NULL);
				
				if (field == 1) {
					strcpy(employeData[i].name, newValue);
				} else {
					strcpy(employeData[i].desc, newValue);
				}
				
				break;
			}
			
			if (field == 2) {
				printf("Selecione a nova Função do Funcionário:\n");
				int values[] = { 1 };
				employeData[i].idFunction = getFK(pathFunction, values, 1, 2);
				break;
			}
			
			if (field == 4) {
				char *auxStatus = getStatus(0);
				strcpy(employeData[i].status, auxStatus);
				break;
			}	
		}
	}
	
	if (ret) {
		FILE *input = fopen(pathEmploye, "w+");
	
		for (i = 0; i < contEmploye; i++) {
			fprintf(input, "%s#%s#%d>#%s#%s", employeData[i].id, employeData[i].name, employeData[i].idFunction, employeData[i].desc, employeData[i].status);
		}
		
		fclose(input);
	}
	
	contEmploye = 0;
	
    return ret;
}
