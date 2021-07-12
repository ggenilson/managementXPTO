int Opdel () {
	int id;
	
	printf("Especifique o código do Tipo da Operação, para assim eliminar:\n");
	scanf("%d", &id);
	
	return removeField(pathOperationType, id, 2);
}
