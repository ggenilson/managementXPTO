int CgetCompany () {
	char * fields[] = { "ID", "NOME", "TIPO", "ESTADO" };
	char *fks[] = { pathCompanyType };
	int fksFieldsShow[] = { 1 };
	int endLineFK[] = { 2 };
	
	return getEntityFK(fields, pathCompany, 3, fks, fksFieldsShow, endLineFK);
}
