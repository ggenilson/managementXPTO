int CpTgetComponentTypes () {
	char * fields[] = { "ID", "COMPON", "ESTADO" };
	
	return getEntity(fields, pathComponentType, 3);
}
