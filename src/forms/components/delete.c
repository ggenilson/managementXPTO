int Cpdel () {
	int id;
	
	printf("Especifique o código da Empresa, para assim eliminar:\n");
	scanf("%d", &id);
	
	return removeField(pathComponent, id, 2);
}
