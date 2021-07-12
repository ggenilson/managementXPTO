int CpStore () {	
	setbuf(stdin, NULL);
	
    struct component {
    	int id;
        char designation[50];
        char serieNumber[20];
        int idSupplier;
		int idManufacturer;
		int idComponentType;
		char condition[50];
		int idWorkPlace;
		char obs[100];
        char *status;
    } cp;
    
    int values[] = { 1 };
    char AcquisitionDate[20] = "", warranty[20] = "";

    printf("Designação: ");
    gets(cp.designation);
    setbuf(stdin, NULL);
    
    printf("Nº de Série: ");
    gets(cp.serieNumber);
    setbuf(stdin, NULL);
    
    /******************** Pegando as datas *******************************/
    
    char sms1[] = "Data de Aquisição, formato (dd-mm-aaaa)";
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
	
	strcat(AcquisitionDate, day);
	strcat(AcquisitionDate, "-");
	strcat(AcquisitionDate, month);
	strcat(AcquisitionDate, "-");
	strcat(AcquisitionDate, year);
    
    char sms2[] = "Garantia, formato (dd-mm-aaaa)";
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
	
	strcat(warranty, day1);
	strcat(warranty, "-");
	strcat(warranty, month1);
	strcat(warranty, "-");
	strcat(warranty, year1);
    
    /*********************************************************************/
    
    puts("Selecione o Fornecedor:");
    cp.idManufacturer = getFK1(pathCompany, values, 1, 2, 2);
    
    puts("Selecione o Fabricante:");
    cp.idSupplier = getFK1(pathCompany, values, 1, 1, 2);
    
    puts("Selecione o Tipo do Componente:");
    cp.idComponentType = getFK(pathComponentType, values, 1, 2);
    
    printf("Condição: ");
	scanf("%s", cp.condition);
	setbuf(stdin, NULL);
    
    puts("Selecione o Posto de Trabalho:");
    cp.idWorkPlace = getFK(pathWorkPlace, values, 1, 6);
    
    printf("Observação:");
	gets(cp.obs);
	setbuf(stdin, NULL);
    
    cp.status = getStatus(0);
    
    FILE *file, *fileReader;
    
    file = fopen(pathComponent, "a");
    fileReader = fopen(pathComponent, "r");
    
    if (!file || !fileReader) {
    	printf("Arquivo não pode ser aberto!\n");
    	
    	return 0;
	}
	
	char str[200];
	cp.id = getNewID(str, fileReader);
    
    fprintf(file, "%d#%s#%s#%s#%s#%d>#%d>#%d>#%s#%d>#%s#%s", cp.id, cp.designation, cp.serieNumber, AcquisitionDate, warranty, cp.idSupplier, cp.idManufacturer, cp.idComponentType, cp.condition, cp.idWorkPlace, cp.obs, cp.status);
    fclose(file);
    fclose(fileReader);
    
    return 1;
}
