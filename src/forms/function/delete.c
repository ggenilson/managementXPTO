int Fcdel () {
	int id;
	
	printf("Especifique o c�digo da Fun��o, para assim eliminar:\n");
	scanf("%d", &id);
	
	return removeField(pathFunction, id, 2);
}
