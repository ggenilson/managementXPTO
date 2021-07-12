typedef struct {
    char id[5];
    char nDocI[50];
    char nDocE[50];
    int idWorkPlace;
    int idComponent;
    int idCompany;
    int idOperationType;
    char outDate[20];
    char comeDate[20];
    char guessDate[20];
    int idEmployee;
    char operationDate[20];
    char money[100];
	char obs[100];
    char status[10];
} operation;

operation operationData[1001];

int contOperation = 0;

void getFieldsToEditOpt () {
	int i;
	for (i = 0; i < 12; i++) {
		printf("%s\n", fieldsOperationToEdit[i]);
	}
}

void pastOperationToData () {
	char * sub;
	int k, i;
	
	//Arquivo de entrada
	FILE *input = fopen(pathOperation, "r");
    
    //Uma string larga o suficiente para extrair o texto total de cada linha
    char lineText[1001] = "";
    
    while(fgets(lineText, 1001, input)) {
	    sub = strtok(lineText, "#");
	    k = 0;
	    
	    strcpy(operationData[contOperation].id, sub);
	    
	    while (sub) {
	    	sub = strtok(NULL, "#");
	    	
	    	if (sub) {
	    		k++;
	    		
	    		if (k == 1) {
	    			strcpy(operationData[contOperation].nDocI, sub);
				} else if (k == 2) {
	    			strcpy(operationData[contOperation].nDocE, sub);
				} else if (k == 3) {
					operationData[contOperation].idWorkPlace = atoi(sub);
				} else if (k == 4) {
					operationData[contOperation].idComponent = atoi(sub);
				} else if (k == 5) {
					operationData[contOperation].idCompany = atoi(sub);
				} else if (k == 6) {
					operationData[contOperation].idOperationType = atoi(sub);
				} else if (k == 7) {
					strcpy(operationData[contOperation].outDate, sub);
				} else if (k == 8) {
					strcpy(operationData[contOperation].comeDate, sub);
				} else if (k == 9) {
					strcpy(operationData[contOperation].guessDate, sub);
				} else if (k == 10) {
					operationData[contOperation].idEmployee = atoi(sub);
				} else if (k == 11) {
					strcpy(operationData[contOperation].operationDate, sub);
				} else if (k == 12) {
					strcpy(operationData[contOperation].money, sub);
				} else if (k == 13) {
					strcpy(operationData[contOperation].obs, sub);
				} else if (k == 14) {
					strcpy(operationData[contOperation].status, sub);
				}
			}
		}
		
		contOperation++;
    }
    
    fclose(input);
    
    if (contOperation > 0) {
    	getFieldsToEditOpt();
	} else {
		printf("Tabela não possui algum dado para editar ...\n");
	}
}

int OptUpdate () {
	pastOperationToData();
	int values[] = { 1 };
	
	setbuf(stdin, NULL);
	
	int id, ret = 0, field, i;
	char newValue[100];
	
	printf("Especifique o código da Operação, para assim editar:\n");
	scanf("%d", &id);
	setbuf(stdin, NULL);
	
	printf("Qual campo quer editar: ");
	scanf("%d", &field);
	setbuf(stdin, NULL);

	for (i = 0; i < contOperation; i++) {
		if (atoi(operationData[i].id) == id) {
			ret = 1;
			
			if (field == 1 || field == 2 || field == 12 || field == 13) {
				printf("Novo valor: ");
				gets(newValue);
				setbuf(stdin, NULL);
				
				if (field == 1) {
					strcpy(operationData[i].nDocI, newValue);
				} else if (field == 2) {
					strcpy(operationData[i].nDocE, newValue);
				} else if (field == 12) {
					strcpy(operationData[i].money, newValue);
				} else if (field == 13) {
					strcpy(operationData[i].obs, newValue);
				}
				
				break;
			}
			
			if (field == 3) {
			 	puts("Selecione o novo Posto de Trabalho:");
    			operationData[i].idWorkPlace = getFK(pathWorkPlace, values, 1, 6);
				break;
			}
			
			if (field == 4) {
				puts("Selecione o novo Componente:");
    			operationData[i].idComponent = getFK(pathComponent, values, 1, 11);
				break;
			}	
			
			if (field == 5) {
				puts("Selecione a nova Empresa:");
			    operationData[i].idCompany = getFK(pathCompany, values, 1, 3);
			    break;
			}
			
			if (field == 6) {
				puts("Selecione o novo Tipo da Operação:");
			    operationData[i].idOperationType = getFK(pathOperationType, values, 1, 2);
			    break;
			}
			
			if (field == 7) {
				char sms1[] = "Nova Data de Saída, formato (dd-mm-aaaa)";
			    char day[4] = "", month[4] = "", year[10] = "", outDate[20] = "";
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
				
				strcat(outDate, day);
				strcat(outDate, "-");
				strcat(outDate, month);
				strcat(outDate, "-");
				strcat(outDate, year);
				strcpy(operationData[i].outDate, outDate);
				break;
			}
			
			if (field == 8) {
				char sms2[] = "Nova Data de Chegada, formato (dd-mm-aaaa)";
			    char day1[4] = "", month1[4] = "", year1[10] = "", comeDate[20] = "";
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
				
				strcat(comeDate, day1);
				strcat(comeDate, "-");
				strcat(comeDate, month1);
				strcat(comeDate, "-");
				strcat(comeDate, year1);
				strcpy(operationData[i].comeDate, comeDate);
				break;
			}
			
			if (field == 9) {
				char sms3[] = "Nova Data Prevista de Chegada, formato (dd-mm-aaaa)";
			    char day2[4] = "", month2[4] = "", year2[10] = "", guessDate[20] = "";
				setbuf(stdin, NULL);
	
				do {
					printf("%s\n", sms3);
					printf("\tDia: ");
					scanf("%s", day2);
					setbuf(stdin, NULL);
					
					printf("\tMês: ");
					scanf("%s", month2);
					setbuf(stdin, NULL);
					
					printf("\tAno: ");
					scanf("%s", year2);
					setbuf(stdin, NULL);
					
					if (atoi(day2) < 1 || atoi(day2) > 31 || atoi(month2) < 1 || atoi(month2) > 12 || atoi(year2) < 1) {
						textcolor(RED);
						printf("Problema com os dados de entrada, verifique a data digitada!\n\n");
						textcolor(GREEN);
					}
				} while(atoi(day2) < 1 || atoi(day2) > 31 || atoi(month2) < 1 || atoi(month2) > 12 || atoi(year2) < 1);
				
				strcat(guessDate, day2);
				strcat(guessDate, "-");
				strcat(guessDate, month2);
				strcat(guessDate, "-");
				strcat(guessDate, year2);
				strcpy(operationData[i].guessDate, guessDate);
				break;
			}
			
			if (field == 10) {
				puts("Selecione o novo Funionário:");
    			operationData[i].idEmployee = getFK(pathEmploye, values, 1, 4);
				break;
			}
			
			if (field == 11) {
				char sms4[] = "Nova Data da Operação, formato (dd-mm-aaaa)";
			    char day3[4] = "", month3[4] = "", year3[10] = "", operationDate[20] = "";
				setbuf(stdin, NULL);
	
				do {
					printf("%s\n", sms4);
					printf("\tDia: ");
					scanf("%s", day3);
					setbuf(stdin, NULL);
					
					printf("\tMês: ");
					scanf("%s", month3);
					setbuf(stdin, NULL);
					
					printf("\tAno: ");
					scanf("%s", year3);
					setbuf(stdin, NULL);
					
					if (atoi(day3) < 1 || atoi(day3) > 31 || atoi(month3) < 1 || atoi(month3) > 12 || atoi(year3) < 1) {
						textcolor(RED);
						printf("Problema com os dados de entrada, verifique a data digitada!\n\n");
						textcolor(GREEN);
					}
				} while(atoi(day3) < 1 || atoi(day3) > 31 || atoi(month3) < 1 || atoi(month3) > 12 || atoi(year3) < 1);
				
				strcat(operationDate, day3);
				strcat(operationDate, "-");
				strcat(operationDate, month3);
				strcat(operationDate, "-");
				strcat(operationDate, year3);
				strcpy(operationData[i].operationDate, operationDate);
				break;
			}
		}
	}
	
	if (ret) {
		FILE *input = fopen(pathOperation, "w+");
	
		for (i = 0; i < contOperation; i++) {
			fprintf(input, "%s#%s#%s#%d>#%d>#%d>#%d>#", operationData[i].id, operationData[i].nDocI, operationData[i].nDocE, operationData[i].idWorkPlace, operationData[i].idComponent, operationData[i].idCompany, operationData[i].idOperationType);
		    fprintf(input, "%s#%s#%s#%d>#%s#", operationData[i].outDate, operationData[i].comeDate, operationData[i].guessDate, operationData[i].idEmployee, operationData[i].operationDate);
		    fprintf(input, "%s#%s#%s", operationData[i].money, operationData[i].obs, operationData[i].status);
		}
		
		fclose(input);
	}
	
	contOperation = 0;
	
    return ret;
}
