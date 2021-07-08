int CpStore () {	
	setbuf(stdin, NULL);
	
    struct component {
    	int id;
        char designation[50];
        char serieNumber[20];
        char *AcquisitionDate;
        char *warranty;
        int idSupplier;
		int idManufacturer;
		int idComponentType;
		char condition[50];
		int idWorkPlace;
		char obs[100];
        char *status;
    } cp;
    
    int values[] = { 1 };

    printf("Designação: ");
    gets(cp.designation);
    setbuf(stdin, NULL);
    
    printf("Nº de Série: ");
    gets(cp.serieNumber);
    setbuf(stdin, NULL);
    
    char sms1[] = "Data de Aquisição, formato (dd-mm-yyyy)";
    cp.AcquisitionDate = getDate(sms1);
    
    printf("DATA: %s\n\n\n", cp.AcquisitionDate);
    
    char sms2[] = "Garantia, formato (dd-mm-yyyy)";
    cp.warranty = getDate(sms2);
    
    printf("%s\n", cp.warranty);
    
    puts("Selecione o Fornecedor:");
    cp.idManufacturer = getFK1(pathCompany, values, 1, 2, 2);
    
    puts("Selecione o Fabricante:");
    cp.id = getFK1(pathCompany, values, 1, 1, 2);
    
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
    
    fprintf(file, "%d#%s#%s#%s#%s#%d>#%d>#%d>#%s#%d>#%s#%s", cp.id, cp.designation, cp.serieNumber, cp.AcquisitionDate, cp.warranty, cp.idSupplier, cp.idManufacturer, cp.idComponentType, cp.condition, cp.idWorkPlace, cp.obs, cp.status);
    fclose(file);
    fclose(fileReader);
    
    return 1;
}
