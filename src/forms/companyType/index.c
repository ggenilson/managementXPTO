int CTgetCompanyTypes () {
	char * fields[] = { "ID", "TIPO" };
	
	//Arquivo de entrada
	FILE *input = fopen(pathCompanyType, "r");
	
	return getEntity(fields, input, 2);
}
