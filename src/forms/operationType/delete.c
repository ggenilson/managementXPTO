int Opdel () {
	int id;
	
	printf("Especifique o c�digo do Tipo da Opera��o, para assim eliminar:\n");
	scanf("%d", &id);
	
	return removeField(pathOperationType, id, 2);
}
