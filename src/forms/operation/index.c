int OpgetComponents () {
	char * fields[] = { 
		"ID          ", 
		"DOC. INTERNO",
		"DOC. EXTERNO",
		"POSTO       ", 
		"COMPONENTE", 
		"EMPRESA", 
		"TIPO OPERA��O", 
		"DATA SA�DA", 
		"DATA CHEGADA", 
		"DATA PREVISTA", 
		"FUNCION�RIO", 
		"DATA OPERA��O", 
		"MONTANTE", 
		"OBSERVA��O", 
		"ESTADO      " 
	};
	
	char *fks[] = { 
		pathWorkPlace, 
		pathComponent, 
		pathCompany, 
		pathOperationType, 
		pathEmploye,
	};
	
	int fksFieldsShow[] = { 1, 1, 1, 1, 1 };
	int endLineFK[] = { 6, 11, 3, 2, 4 };
	
	return getEntityFK(fields, pathOperation, 14, fks, fksFieldsShow, endLineFK);
}
