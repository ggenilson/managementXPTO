int FcgetFunction () {
	char * fields[] = { "ID", "FUN��O", "ESTADO" };
	
	return getEntity(fields, pathFunction, 3);
}
