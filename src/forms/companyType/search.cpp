int CTsearch () {
	char * fields[] = { "ID", "TIPO", "Estado" };
	
	//Arquivo de entrada
	FILE *input = fopen(pathCompanyType, "r");
	
	return getEntity(fields, input, 3, fieldsCompanyType, 4);
}
