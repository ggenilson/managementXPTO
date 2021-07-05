int Fcdel () {
	int id;
	
	printf("Especifique o código da Função, para assim eliminar:\n");
	scanf("%d", &id);
	
	return removeField(pathFunction, id, 2);
}
