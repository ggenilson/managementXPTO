int CTupdate () {
	setbuf(stdin, NULL);
	fflush(stdin);
	
	int id, ret = 0;
	char newCompany[100];
	
	printf("Especifique o código da Empresa, para assim editar:\n");
	scanf("%d", &id);
	
	setbuf(stdin, NULL);
	
	printf("Escreva o novo nome da Empresa:\n");
	gets(newCompany);
	
	setbuf(stdin, NULL);
	fflush(stdin);
	
	//Arquivo de entrada
	FILE *input = fopen(pathCompanyType, "r");
	
	//Arquivo de saída
    FILE *output = fopen("helpful.txt", "w");
    
    if (!input || !output) {
    	return 5;
	}
    
    //Uma string larga o suficiente para extrair o texto total de cada linha
    char lineText[1001] = "";
    
    int index, idCompare;
	char * aux, * found;
    
    while(fgets(lineText, 1001, input)) {
    	found = strchr(lineText, '#');
		index = found ? found - lineText : -1;
		
		aux = substring(lineText, 0, index);
		idCompare = atoi(aux);
    	
        if(id != idCompare) {
            fputs(lineText, output);
        } else {
        	fprintf(output, "%d#%s\n", idCompare, newCompany);
        	ret = 1;
		}
        
        memset(lineText, 0, sizeof(char) * 1001);
    }
    
    fclose(input);
    fclose(output);
    
    remove(pathCompanyType);
    rename("helpful.txt", pathCompanyType);
    
    return ret;
}
