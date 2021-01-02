//crtr_Nodos.h
//Funciones 01------------------------------------------------------
void crtr_Nodos(FILE	**Driver_ArchivoDXF,		//01
				float	***VecX_Nodos,				//02
				float	***VecY_Nodos,				//03
				int 	Nodos_nElements,			//04
				char 	Layer_NodosMark_Name[],		//05
				float 	NodosMark_radio,			//06
				int 	NodosMark_color)			//07		
{
	int i;
	
	for (i=0;i<Nodos_nElements;i++)
	{
		fprintf(*Driver_ArchivoDXF,"0\n");
		fprintf(*Driver_ArchivoDXF,"CIRCLE\n");
		fprintf(*Driver_ArchivoDXF,"8\n");
		fprintf(*Driver_ArchivoDXF,"%s\n",Layer_NodosMark_Name);
		
		fprintf(*Driver_ArchivoDXF,"62\n");
		fprintf(*Driver_ArchivoDXF,"%i\n",NodosMark_color);
		
		fprintf(*Driver_ArchivoDXF,"10\n");
		fprintf(*Driver_ArchivoDXF,"%f\n",float(*(*(*VecX_Nodos)+i)));
		fprintf(*Driver_ArchivoDXF,"20\n");
		fprintf(*Driver_ArchivoDXF,"%f\n",float(*(*(*VecY_Nodos)+i)));
		fprintf(*Driver_ArchivoDXF,"40\n");
		fprintf(*Driver_ArchivoDXF,"%f\n",NodosMark_radio);
		
		/*		
		printf("%3i ", i);
		printf("%12.5f ", float (*(*(*VecX_Nodos)+i)));
		printf("%12.5f\n",float (*(*(*VecY_Nodos)+i)));
		*/
	}	
};
// Functions END--------------------------------------------
