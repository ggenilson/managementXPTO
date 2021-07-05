int FcgetFunction () {
	char * fields[] = { "ID", "FUNÇÃO", "ESTADO" };
	
	return getEntity(fields, pathFunction, 3);
}
