int Wpdel () {
	int id;
	
	printf("Especifique o código do Posto de Trabalho, para assim eliminar:\n");
	scanf("%d", &id);
	
	return removeField(pathWorkPlace, id, 6);
}
