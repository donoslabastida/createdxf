//crtr_NodosLabel.h
//Funciones 03-----------------------------------------------------------------
void crtr_NodosLabel(	FILE	**Driver_ArchivoDXF,		//01
						float	***VecX_Nodos,				//02
						float	***VecY_Nodos,				//03
						int 	Nodos_nElements,			//04
						float 	NodosLabel_offset_X,		//05
						float 	NodosLabel_offset_Y,		//06
						char 	Layer_AristasLabel_Name[],	//07
						float 	NodosLabel_Height,			//08				
						int 	NodosLabel_color)			//09		
{
	int i;
	
	//Texto_Angulo = 0.0;
	
	for (i=0;i<Nodos_nElements;i++)
	{
		fprintf(*Driver_ArchivoDXF,"0\n");
		fprintf(*Driver_ArchivoDXF,"TEXT\n");
		fprintf(*Driver_ArchivoDXF,"8\n");
		fprintf(*Driver_ArchivoDXF,"%s\n",Layer_AristasLabel_Name);
		
		fprintf(*Driver_ArchivoDXF,"62\n");
		fprintf(*Driver_ArchivoDXF,"%i\n",NodosLabel_color);
		
		fprintf(*Driver_ArchivoDXF,"10\n");
		fprintf(*Driver_ArchivoDXF,"%f\n",float(*(*(*VecX_Nodos)+i))+NodosLabel_offset_X);
		fprintf(*Driver_ArchivoDXF,"20\n");
		fprintf(*Driver_ArchivoDXF,"%f\n",float(*(*(*VecY_Nodos)+i))+NodosLabel_offset_Y);
		fprintf(*Driver_ArchivoDXF,"40\n");
		fprintf(*Driver_ArchivoDXF,"%f\n",NodosLabel_Height);
		fprintf(*Driver_ArchivoDXF,"1\n");
		fprintf(*Driver_ArchivoDXF,"%i\n",i);					
	}	
}
