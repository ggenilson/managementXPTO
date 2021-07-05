int CpTdel () {
	int id;
	
	printf("Especifique o código do Tipo do Componente, para assim eliminar:\n");
	scanf("%d", &id);
	
	return removeField(pathComponentType, id, 2);
}
