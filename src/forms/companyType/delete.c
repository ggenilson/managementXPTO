int del () {
	int id;
	
	printf("Especifique o código da Empresa, para assim eliminar:\n");
	scanf("%d", &id);
	
	//Arquivo de entrada
	FILE *input = fopen(pathCompanyType, "r");
	
	//Arquivo de saída
    FILE *output = fopen("helpful.txt", "w");
    
    //Uma string larga o suficiente para extrair o texto total de cada linha
    char lineText[1001] = "";
    unsigned int curLine = 1;
    
    while(fgets(lineText, 1001, input)){
    	printf("%s\n", lineText);
        if(curLine != id){
            fputs(lineText, output);
        }
        
        memset(lineText, 0, sizeof(char) * 1001);
        curLine++;
    }
    
    system("pause");
    
    fclose(input);
    fclose(output);
    
    remove(pathCompanyType);
    rename("helpful.txt", pathCompanyType);
    
    return 0;
}
