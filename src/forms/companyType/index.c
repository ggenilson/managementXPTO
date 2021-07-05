int CTgetCompanyTypes () {
	char * fields[] = { "ID", "TIPO", "ESTADO" };
	
	return getEntity(fields, pathCompanyType, 3);
}
