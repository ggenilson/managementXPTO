int Optdel () {
	int id;
	
	printf("Especifique o código da Operação, para assim eliminar:\n");
	scanf("%d", &id);
	
	return removeField(pathOperation, id, 14);
}
