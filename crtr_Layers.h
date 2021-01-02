/*
*----------------------------------------------
* crtr_Layers.h
*----------------------------------------------
*/

//Funciones 01------------------------------------------------------
void crtr_Layers( 	FILE **Driver_ArchivoDXF,		//01
					char Layer_NodosLabel_Name[],	//02
					char Layer_NodosMark_Name[],	//03
					char Layer_AristasLabel_Name[],	//04
					char Layer_AristasLine_Name[],	//05
					int NodosLabel_color,			//06
					int NodosMark_color,			//07
					int AristasLabel_color,			//08
					int AristasLine_color)			//09				
{
	fprintf(*Driver_ArchivoDXF,"%s\n",Layer_NodosMark_Name);
}
// Functions END--------------------------------------------

