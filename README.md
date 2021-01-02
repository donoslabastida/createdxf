# createdxf.cpp
Crea un dibujo en un archivo de formato dxf, totalmente funcional, definiendo solo la seccion ENTITIES.
----------------------------------------------------------------------------
Este código toma las bases mostradas en la publicación del sitio oficial de Autodesk Autocad.
https://www.autodesk.com/techpubs/autocad/acad2000/dxf/writing_a_dxf_file_dxf_aa.htm

El proceso de creación del archivo de salida en formato dxf requiere de un archivo de configuración llamado config00.txt, que se describe a contemnn continuación.

-------------------------------------------------------
Tipo de archivo: txt (texto ASCCI plano)

-------------------------------------------------------
Descripción del contenido 

Contenido
Registros:	7 en 7 reglones. 
Tipo:		Números tipo coma flotante.

-------------------------------------------------------		

Orden de aparición y nombre de cada registro

Offset
1. NodosLabel_offset_X 
2. NodosLabel_offset_Y 
3. AristasLabel_offset_X 
4. AristasLabel_offset_Y 

Size
5. NodosMark_Radio 
6. NodosLabel_Height 
7. AristasLabel_Height

-------------------------------------------------------
Ejemplo 
Contenido de archivo de configuración:

50.00	
50.00	
50.00	
50.00	
50.0	
100.0	
70.0	

-------------------------------------------------------

Explicación del contenido del archivo ejemplo:

50.00	(1. NodosLabel_offset_X)
50.00	(2. NodosLabel_offset_Y)
50.00	(3. AristasLabel_offset_X)
50.00	(4. AristasLabel_offset_Y)
50.0	(5. NodosMark_Radio)
100.0	(6. NodosLabel_Height)
70.0	(7. AristasLabel_Height)
-------------------------------------------------------
