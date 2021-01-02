//crtr_Header.h
//Funciones 01------------------------------------------------------
void crtr_Header( 	FILE **Driver_ArchivoDXF)
{
	fprintf(*Driver_ArchivoDXF,"0\n");
	fprintf(*Driver_ArchivoDXF,"SECTION\n");
	fprintf(*Driver_ArchivoDXF,"2\n");
	fprintf(*Driver_ArchivoDXF,"ENTITIES\n");
}
//Funciones 01------------------------------------------------------
