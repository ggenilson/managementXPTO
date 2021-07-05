int EpStore () {	
	setbuf(stdin, NULL);
	
    struct employe {
    	int id;
        char name[100];
        int idFunction;
        char desc[100];
        char *status;
    } ep;
    
    int values[] = { 1 };

    printf("Nome do Funcionário: ");
    gets(ep.name);
    setbuf(stdin, NULL);
    
    puts("Selecione a Função do Funcionário:");
    ep.idFunction = getFK(pathFunction, values, 1, 2);
    
    printf("Decrição:\n");
    gets(ep.desc);
    setbuf(stdin, NULL);
    
    ep.status = getStatus(1);
    
    FILE *file, *fileReader;
    
    file = fopen(pathEmploye, "a");
    fileReader = fopen(pathEmploye, "r");
    
    if (!file || !fileReader) {
    	printf("Arquivo não pode ser aberto!\n");
    	
    	return 0;
	}
	
	char str[200];
	ep.id = getNewID(str, fileReader);
    
    fprintf(file, "%d#%s#%d>#%s#%s\n", ep.id, ep.name, ep.idFunction, ep.desc, ep.status);
    fclose(file);
    fclose(fileReader);
    
    return 1;
}
