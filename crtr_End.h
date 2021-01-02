//crtr_End.h
//Funciones 01------------------------------------------------------
void crtr_END( 	FILE **Driver_ArchivoDXF)
{
	fprintf(*Driver_ArchivoDXF,"0\n");
	fprintf(*Driver_ArchivoDXF,"ENDSEC\n");
	fprintf(*Driver_ArchivoDXF,"0\n");
	fprintf(*Driver_ArchivoDXF,"EOF\n");
}
//Funciones 01--------
