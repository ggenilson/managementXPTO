int getEmployes () {
	char * fields[] = { "ID", "NOME", "FUN��O", "DESC", "ESTADO" };
	char *fks[] = { pathFunction };
	int fksFieldsShow[] = { 1 };
	int endLineFK[] = { 2 };
	
	return getEntityFK(fields, pathEmploye, 4, fks, fksFieldsShow, endLineFK);
}
