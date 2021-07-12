int Cpdel () {
	int id;
	
	printf("Especifique o código do Componente, para assim eliminar:\n");
	scanf("%d", &id);
	
	return removeField(pathComponent, id, 11);
}
