int getOperationTypes () {
	char * fields[] = { "ID", "TIPO", "ESTADO" };
	
	return getEntity(fields, pathOperationType, 3);
}
