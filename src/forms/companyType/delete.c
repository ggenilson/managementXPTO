int del () {
	int id, ret = 0;
	
	printf("Especifique o código da Empresa, para assim eliminar:\n");
	scanf("%d", &id);
	
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
