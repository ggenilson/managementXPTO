int CStore () {	
	setbuf(stdin, NULL);
	
    struct company {
    	int id;
        char name[100];
        int idCompanyType;
        char *status;
    } cn;
    
    int values[] = { 1 };

    printf("Nome da Empresa: ");
    gets(cn.name);
    setbuf(stdin, NULL);
    
    puts("Selecione o tipo da Empresa:");
    cn.idCompanyType = getFK(pathCompanyType, values, 1, 2);
    
    cn.status = getStatus(1);
    
    FILE *file, *fileReader;
    
    file = fopen(pathCompany, "a");
    fileReader = fopen(pathCompany, "r");
    
    if (!file || !fileReader) {
    	printf("Arquivo não pode ser aberto!\n");
    	
    	return 0;
	}
	
	char str[200];
	cn.id = getNewID(str, fileReader);
    
    fprintf(file, "%d#%s#%d>#%s\n", cn.id, cn.name, cn.idCompanyType, cn.status);
    fclose(file);
    fclose(fileReader);
    
    return 1;
}
