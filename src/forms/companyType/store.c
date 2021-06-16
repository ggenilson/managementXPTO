int CTStore () {	
	setbuf(stdin, NULL);
	
    struct company {
    	int id;
        char type[100];
        char *status;
    } cn;

    puts("Tipo da Empresa:");
    gets(cn.type);
    setbuf(stdin, NULL);
    
    cn.status = getStatus();
    
    FILE *file, *fileReader;
    
    file = fopen(pathCompanyType, "a");
    fileReader = fopen(pathCompanyType, "r");
    
    if (!file || !fileReader) {
    	printf("Arquivo não pode ser aberto!\n");
    	
    	return 0;
	}
	
	char str[200];
	cn.id = getNewID(str, fileReader);
    
    fprintf(file, "%d#%s#%s\n", cn.id, cn.type, cn.status);
    fclose(file);
    fclose(fileReader);
    
    return 1;
}
