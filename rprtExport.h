/*
*-------------------------------------------------------------------
*	rprtExport.h
*-------------------------------------------------------------------
*/

int rprtExport(	int 	File_DXF_STATUS,			//01
				int 	Nodos_nElements,			//02
				int 	Aristas_nElements,			//03
				char	FileDXFNm_Out[],			//04
				char	FileAddress_Out[],			//05	
				char	Layer_NodosLabel_Name[],	//06
				char	Layer_NodosMark_Name[],		//07
				char	Layer_AristasLabel_Name[],	//08
				char	Layer_AristasLine_Name[],	//09		
				float 	NodosLabel_offset_X,		//10
				float 	NodosLabel_offset_Y,		//11
				float 	AristasLabel_offset_X,		//12
				float 	AristasLabel_offset_Y,		//13
				float 	NodosMark_Radio,			//14
				float 	NodosLabel_Height,			//15
				float 	AristasLabel_Height,		//16
				int 	NodosLabel_color,			//17
				int 	NodosMark_color,			//18
				int 	AristasLabel_color,			//19
				int 	AristasLine_color,			//20
				int		Layer_STATUS_Layers,		//21
				int 	Layer_STATUS_NodosMark, 	//22		
				int 	Layer_STATUS_NodosLabel,	//23
				int 	Layer_STATUS_AristasLine,	//24
				int 	Layer_STATUS_AristasLabel)	//25
{
	int index = 0;

	printf("--------------------------------------\n");
	printf("Exportar MapaRED a DXF\n");
    printf("Desnino:\n");
    printf("%s\n",FileDXFNm_Out);			
	printf("%s\n",FileAddress_Out);	
    printf("--------------------------------------\n");
	printf("Status:");
	

    if (File_DXF_STATUS == CREATED) 
	{
		printf(" %s\n","CREATED");
		printf("--------------------------------------\n");
		printf("Elementos en vectores\n");
		printf("Nodos:   %3i\n",Nodos_nElements);
		printf("Aristas: %3i\n",Aristas_nElements);
		printf("--------------------------------------\n");
		printf("Capas incluidas:\n");

		if (Layer_STATUS_NodosMark == SELECT)
		{
			index++;
			printf("%2i %s\n",index,Layer_NodosMark_Name);
			printf("     Radio de marcas: %12.5f\n",NodosMark_Radio);
			printf("     Color: %3i\n",NodosMark_color);	
		}	
		if (Layer_STATUS_NodosLabel == SELECT)	
		{
			index++;
			printf("%2i %s\n",index,Layer_AristasLine_Name);
			printf("     Color: %3i\n",AristasLine_color);		
		}
		if (Layer_STATUS_AristasLine == SELECT)
		{
			index++;
			printf("%2i %s\n",index,Layer_NodosLabel_Name);
			printf("     Altura de texto: ");
			printf("%12.5f\n",NodosLabel_Height);
			printf("     Color: %3i\n",NodosLabel_color);
			printf("     Offset\n");
			printf("     X: %12.5f\n",NodosLabel_offset_X);
			printf("     Y: %12.5f\n",NodosLabel_offset_Y);				    
		}
		if (Layer_STATUS_AristasLabel == SELECT)	
		{
			index++;
			printf("%2i %s\n",index,Layer_AristasLabel_Name);
			printf("     Altura de texto: ");
			printf("%12.5f\n",AristasLabel_Height);
			printf("     Color: %3i\n",AristasLabel_color);
			printf("     Offset\n");
			printf("     X: %12.5f\n",AristasLabel_offset_X);
			printf("     Y: %12.5f\n",AristasLabel_offset_Y);	    
		}
   	}
	else
	printf(" %s\n","NO_CREATED");
}
// Functions END--------------------------------------------
