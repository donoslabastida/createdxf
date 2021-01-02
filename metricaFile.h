/*
*--------------------------------------------
* metricaFile.h
*--------------------------------------------
*
*	01 metricaFM
*
*--------------------------------------------
*/

#define ASCCI_LF 10
#define ASCCI_BLANCKSPACE 32

// Functions 1--------------------------------------------
int metricaFile(char File_Name[],
		    	char File_Address[],
		    	int* Row_total,
				int* codeASCCI_LF_Conteo,
				int* codeASCCI_BLANCSPACE_Conteo)
{
	int i = 0;
	FILE *File_Driver;
	char File_Path [200] = "";
	
	int CharacterCode;
	int Status = NO_LINKED;
	
	*codeASCCI_LF_Conteo = VACIO;
	*codeASCCI_BLANCSPACE_Conteo = VACIO;
	*Row_total = VACIO;
	
	strcat(File_Path,File_Address);
    strcat(File_Path,File_Name);	
	
    File_Driver = fopen(File_Path,"r");
    if (File_Driver != NULL)
    {
    	Status = AVAILABLE;
    	do
    	{	
    		i++;
			CharacterCode = getc(File_Driver);
			//Término de renglón
			if (CharacterCode== ASCCI_LF)
			(*codeASCCI_LF_Conteo)++;
			//Espacio en blanco
			if (CharacterCode == ASCCI_BLANCKSPACE)
			(*codeASCCI_BLANCSPACE_Conteo)++;
    	}
    	while (CharacterCode != EOF);
    	fclose(File_Driver);	    
    	
    	//Agregar un renglón por el equivalente 
		//LF antes del código EOF
    	*Row_total = int (*codeASCCI_LF_Conteo) + 1;
	}
	return Status;
}
// Functions 1--------------------------------------------
