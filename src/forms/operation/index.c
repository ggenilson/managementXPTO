int OpgetComponents () {
	char * fields[] = { 
		"ID          ", 
		"DOC. INTERNO",
		"DOC. EXTERNO",
		"POSTO       ", 
		"COMPONENTE", 
		"EMPRESA", 
		"TIPO OPERAÇÃO", 
		"DATA SAÍDA", 
		"DATA CHEGADA", 
		"DATA PREVISTA", 
		"FUNCIONÁRIO", 
		"DATA OPERAÇÃO", 
		"MONTANTE", 
		"OBSERVAÇÃO", 
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
