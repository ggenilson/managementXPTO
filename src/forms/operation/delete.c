int Optdel () {
	int id;
	
	printf("Especifique o c�digo da Opera��o, para assim eliminar:\n");
	scanf("%d", &id);
	
	return removeField(pathOperation, id, 14);
}
