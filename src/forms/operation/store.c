int OptStore () {	
	setbuf(stdin, NULL);
	
    struct operation {
    	int id;
        char nDocI[50];
        char nDocE[50];
        int idWorkPlace;
        int idComponent;
        int idCompany;
        int idOperationType;
        int idEmployee;
        double money;
		char obs[100];
        char *status;
    } op;
    
    int values[] = { 1 };
    char outDate[20] = "", comeDate[20] = "", guessDate[20] = "", operationDate[20] = "";

    printf("Número do Documento Interno: ");
    gets(op.nDocI);
    setbuf(stdin, NULL);
    
    printf("Número do Documento Externo: ");
    gets(op.nDocE);
    setbuf(stdin, NULL);
    
    puts("Selecione o Posto de Trabalho:");
    op.idWorkPlace = getFK(pathWorkPlace, values, 1, 6);
    
    puts("Selecione o Componente:");
    op.idComponent = getFK(pathComponent, values, 1, 11);
    
    puts("Selecione a Empresa:");
    op.idCompany = getFK(pathCompany, values, 1, 3);
    
    puts("Selecione o Tipo da Operação:");
    op.idOperationType = getFK(pathOperationType, values, 1, 2);
    
    /******************** Pegando as datas *******************************/
    
    char sms1[] = "Data de Saída, formato (dd-mm-aaaa)";
    char day[4] = "", month[4] = "", year[10] = "";
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
    
    char sms2[] = "Data de Chegada, formato (dd-mm-aaaa)";
    char day1[4] = "", month1[4] = "", year1[10] = "";
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
	
	char sms3[] = "Data Prevista de Chegada, formato (dd-mm-aaaa)";
    char day2[4] = "", month2[4] = "", year2[10] = "";
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
	
	/*******************************************************************************************/
	
	puts("Selecione o Funionário:");
    op.idEmployee = getFK(pathEmploye, values, 1, 4);
    
    /******************************************************************************************/
    char sms4[] = "Data da Operação, formato (dd-mm-aaaa)";
    char day3[4] = "", month3[4] = "", year3[10] = "";
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
	/******************************************************************************************************/
    
    printf("Montante: ");
	scanf("%lf", &op.money);
	setbuf(stdin, NULL);
    
    printf("Observação: ");
	gets(op.obs);
	setbuf(stdin, NULL);
    
    op.status = getStatus(0);
    
    FILE *file, *fileReader;
    
    file = fopen(pathOperation, "a");
    fileReader = fopen(pathOperation, "r");
    
    if (!file || !fileReader) {
    	printf("Arquivo não pode ser aberto!\n");
    	
    	return 0;
	}
	
	char str[200];
	op.id = getNewID(str, fileReader);
    
    fprintf(file, "%d#%s#%s#%d>#%d>#%d>#%d>#", op.id, op.nDocI, op.nDocE, op.idWorkPlace, op.idComponent, op.idCompany, op.idOperationType);
    fprintf(file, "%s#%s#%s#%d>#%s#", outDate, comeDate, guessDate, op.idEmployee, operationDate);
    fprintf(file, "%lf#%s#%s", op.money, op.obs, op.status);
    fclose(file);
    fclose(fileReader);
    
    return 1;
}
