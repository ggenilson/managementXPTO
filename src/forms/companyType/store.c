int CTStore () {	
    struct company {
    	int id;
        char type[100];
    } cn;

    puts("Tipo da Empresa:");
    gets(cn.type);
    
    FILE *file, *fileReader;
    
    file = fopen("C:\\Genilson\\Projects\\XPTOManagement\\src\\archives\\companyType.txt" , "a");
    fileReader = fopen("C:\\Genilson\\Projects\\XPTOManagement\\src\\archives\\companyType.txt", "r");
    
    if (!file || !fileReader) {
    	printf("Arquivo não pode ser aberto!\n");
    	
    	return 0;
	}
	
	char str[200];
	int counter;
	//cn.id = getNewID(str, fileReader);
    
    fprintf(file, "%d#%s\n", cn.id, cn.type);
    fclose(file);
    
    return 1;
}
