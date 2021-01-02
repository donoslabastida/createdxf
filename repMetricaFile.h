/*
*------------------------------------------------
* repMetricaFile.h
*------------------------------------------------
*
*	01	printerF_i
*
*/

//Function 01-------------------------------------
void repMetricFile(	char File_Name[],
		    		char File_Address[],
		    		int status,
					int codeASCCI_LF_Conteo,
					int codeASCCI_BLANCSPACE_Conteo,
					int Row_total)
{ 
	char status_label [20] = Label_NO_AVAILABLE;
						
	printf("%s\n",TITLE_DIVLINESRT);
	printf("%s\n",TITLE_TBL_03); 
    printf("%s\n",TITLE_DIVLINESRT);
   	printf("1. Nombre: %s\n",File_Name);
	printf("2. Ruta: %s\n",File_Address);
	 	
	if (status == int(AVAILABLE))
	{
		strcpy(status_label,Label_AVAILABLE);
		printf("3. Status: %s\n",status_label);
		printf("%s\n",TITLE_DIVLINESRT);
		printf("Caracteres de control\n");
		printf("4. LF:         %5d\n",codeASCCI_LF_Conteo);
		printf("5. BLANCSPACE: %5d\n",codeASCCI_BLANCSPACE_Conteo);
		printf("6. Renglones:  %5d\n",Row_total);	
	}
	else
	printf("3. Status: %s\n",status_label);
	printf("%s\n",TITLE_DIVLINESRT);
}
//Function END-------------------------------------
