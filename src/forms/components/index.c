int CpTgetComponents () {
	char * fields[] = { "ID", "COMPON", "ESTADO" };
	
	return getEntity(fields, pathComponent, 3);
}
