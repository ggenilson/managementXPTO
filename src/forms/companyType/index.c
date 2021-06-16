int CTgetCompanyTypes () {
	char * fields[] = { "ID", "TIPO", "ESTADO" };
	
	//Arquivo de entrada
	FILE *input = fopen(pathCompanyType, "r");
	
	return getEntity(fields, input, 3);
}
