typedef struct {
    char id[5];
    char designation[50];
    char serieNumber[20];
    char AcquisitionDate[20];
    char warranty[20];
    int idSupplier;
	int idManufacturer;
	int idComponentType;
	char condition[50];
	int idWorkPlace;
	char obs[100];
    char status[10];
} component;

component componentData[1001];

int contComponent = 0;

void getFieldsToEditCp () {
	int i;
	for (i = 0; i < 9; i++) {
		printf("%s\n", fieldsComponentToEdit[i]);
	}
}

void pastComponentToData () {
	char * sub;
	int k, i;
	
	//Arquivo de entrada
	FILE *input = fopen(pathComponent, "r");
    
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
	    			strcpy(componentData[contComponent].designation, sub);
				} else if (k == 2) {
	    			strcpy(componentData[contComponent].serieNumber, sub);
				} else if (k == 3) {
					strcpy(componentData[contComponent].AcquisitionDate, sub);
				} else if (k == 4) {
					strcpy(componentData[contComponent].warranty, sub);
				} else if (k == 5) {
					componentData[contComponent].idManufacturer = atoi(sub);
				} else if (k == 6) {
					componentData[contComponent].idSupplier = atoi(sub);
				} else if (k == 7) {
					componentData[contComponent].idComponentType = atoi(sub);
				} else if (k == 8) {
					strcpy(componentData[contComponent].condition, sub);
				} else if (k == 9) {
					componentData[contComponent].idWorkPlace = atoi(sub);
				} else if (k == 10) {
					strcpy(componentData[contComponent].obs, sub);
				} else if (k == 11) {
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

int CpUpdate () {
	pastComponentToData();
	int values[] = { 1 };
	
	setbuf(stdin, NULL);
	
	int id, ret = 0, field, i;
	char newValue[100];
	
	printf("Especifique o código do Componente, para assim editar:\n");
	scanf("%d", &id);
	setbuf(stdin, NULL);
	
	printf("Qual campo quer editar: ");
	scanf("%d", &field);
	setbuf(stdin, NULL);

	for (i = 0; i < contComponent; i++) {
		if (atoi(componentData[i].id) == id) {
			ret = 1;
			
			if (field == 1 || field == 2 || field == 8 || field == 10) {
				printf("Novo valor: ");
				gets(newValue);
				setbuf(stdin, NULL);
				
				if (field == 1) {
					strcpy(componentData[i].designation, newValue);
				} else if (field == 2) {
					strcpy(componentData[i].serieNumber, newValue);
				} else if (field == 8) {
					strcpy(componentData[i].condition, newValue);
				} else if (field == 10) {
					strcpy(componentData[i].obs, newValue);
				}
				
				break;
			}
			
			if (field == 3) {
				char sms1[] = "Nova Data de Aquisição, formato (dd-mm-aaaa)";
			    char day[4] = "", month[4] = "", year[10] = "", AcquisitionDate[20] = "";
				setbuf(stdin, NULL);
					
				do {
					printf("%s\n", sms1);
					printf("\tDia: ");
					scanf("%s", day);
					setbuf(stdin, NULL);
					
					printf("\tMês: ");
					scanf("%s", month);
					setbuf(stdin, NULL);
					
					printf("\tAno: ");
					scanf("%s", year);
					setbuf(stdin, NULL);
					
					if (atoi(day) < 1 || atoi(day) > 31 || atoi(month) < 1 || atoi(month) > 12 || atoi(year) < 1) {
						textcolor(RED);
						printf("Problema com os dados de entrada, verifique a data digitada!\n\n");
						textcolor(GREEN);
					}
				} while(atoi(day) < 1 || atoi(day) > 31 || atoi(month) < 1 || atoi(month) > 12 || atoi(year) < 1);
				
				strcat(AcquisitionDate, day);
				strcat(AcquisitionDate, "-");
				strcat(AcquisitionDate, month);
				strcat(AcquisitionDate, "-");
				strcat(AcquisitionDate, year);
				strcpy(componentData[i].AcquisitionDate, AcquisitionDate);
				break;
			}
			
			if (field == 4) {
				char sms2[] = "Nova Garantia, formato (dd-mm-aaaa)";
			    char day1[4] = "", month1[4] = "", year1[10] = "", warranty[20] = "";
				setbuf(stdin, NULL);
					
				do {
					printf("%s\n", sms2);
					printf("\tDia: ");
					scanf("%s", day1);
					setbuf(stdin, NULL);
					
					printf("\tMês: ");
					scanf("%s", month1);
					setbuf(stdin, NULL);
					
					printf("\tAno: ");
					scanf("%s", year1);
					setbuf(stdin, NULL);
					
					if (atoi(day1) < 1 || atoi(day1) > 31 || atoi(month1) < 1 || atoi(month1) > 12 || atoi(year1) < 1) {
						textcolor(RED);
						printf("Problema com os dados de entrada, verifique a data digitada!\n\n");
						textcolor(GREEN);
					}
				} while(atoi(day1) < 1 || atoi(day1) > 31 || atoi(month1) < 1 || atoi(month1) > 12 || atoi(year1) < 1);
				
				strcat(warranty, day1);
				strcat(warranty, "-");
				strcat(warranty, month1);
				strcat(warranty, "-");
				strcat(warranty, year1);
				strcpy(componentData[i].warranty, warranty);
				break;
			}	
			
			if (field == 5) {
				printf("Selecione o novo Fornecedor:\n");
				componentData[i].idManufacturer = getFK1(pathCompany, values, 1, 2, 2);
				break;
			}
			
			if (field == 6) {
				printf("Selecione o novo Fabricante:\n");
				componentData[i].idSupplier = getFK1(pathCompany, values, 1, 1, 2);
				break;
			}
			
			if (field == 7) {
				printf("Selecione o novo Tipo de Componente:\n");
				componentData[i].idComponentType = getFK(pathComponentType, values, 1, 2);
				break;
			}
			
			if (field == 9) {
				printf("Selecione o novo Fabricante:\n");
				componentData[i].idWorkPlace = getFK(pathWorkPlace, values, 1, 6);
				break;
			}
		}
	}
	
	if (ret) {
		FILE *input = fopen(pathComponent, "w+");
	
		for (i = 0; i < contComponent; i++) {
			fprintf(input, "%s#%s#%s#%s#%s#%d>#%d>#%d>#%s#%d>#%s#%s", componentData[i].id, componentData[i].designation, componentData[i].serieNumber, componentData[i].AcquisitionDate, componentData[i].warranty, componentData[i].idSupplier, componentData[i].idManufacturer, componentData[i].idComponentType, componentData[i].condition, componentData[i].idWorkPlace, componentData[i].obs, componentData[i].status);
		}
		
		fclose(input);
	}
	
	contComponent = 0;
	
    return ret;
}
