int getWorkPlace () {
	char * fields[] = { "ID", "DESIGN", "LOCAL", "SEC��O", "DESC", "FUNC", "ESTADO" };
	char *fks[] = { pathEmploye };
	int fksFieldsShow[] = { 1 };
	int endLineFK[] = { 4 };
	
	return getEntityFK(fields, pathWorkPlace, 6, fks, fksFieldsShow, endLineFK);
}
