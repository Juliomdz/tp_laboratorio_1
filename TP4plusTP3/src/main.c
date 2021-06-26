#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int main()
{
    LinkedList* listaEmpleados=ll_newLinkedList();
    char archivoBinario[]={"data.bin"};
    char archivoTexto[]={"data.csv"};
    int opcion;
    int flagStatusTexto=0; //STATUS:0 no cargado; 1 cargado igual en memoria y archivo; 2 con modificaciones para guardar.
    int flagStatusBinario=0; //STATUS:0 no cargado; 1 cargado igual en memoria y archivo; 2 con modificaciones para guardar.

    printf("\n\tBienvenido al programa de administracion de nomina de empleados.\n");
    do{
        utn_getNumero(&opcion,"\n   MENU:\n"
                        "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n"
                        "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n"
                        "3. Alta de empleado\n"
                        "4. Modificar datos de empleado\n"
                        "5. Baja de empleado\n"
                        "6. Listar empleados\n"
                        "7. Ordenar empleados\n"
                        "8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n"
                        "9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n"
                        "10. Salir\n"
                        "\nElija una opcion:"
                        ,"Opcion invalida.\n",1,10,2);

                        switch(opcion){
                        case 1:
                            if(controller_loadFromText(archivoTexto,listaEmpleados) == 0)
                              {
                                flagStatusTexto=1;
                                if(flagStatusBinario==0)
                                {flagStatusBinario=2;}
                              }
                            break;
                        case 2:
                            if(controller_loadFromBinary(archivoBinario,listaEmpleados) == 0)
                              {
                                flagStatusBinario=1;
                                if(flagStatusTexto==0)
                                {flagStatusTexto=2;}
                            }
                            break;
                        case 3:
                            if(controller_addEmployee(listaEmpleados) == 0){
                                flagStatusTexto=2;
                                flagStatusBinario=2;
                            }
                            break;
                        case 4:
                            if(controller_editEmployee(listaEmpleados) == 0){
                                flagStatusTexto=2;
                                flagStatusBinario=2;
                            }
                            break;
                        case 5:
                            if(controller_removeEmployee(listaEmpleados) == 0){
                                flagStatusTexto=2;
                                flagStatusBinario=2;
                            }
                            break;
                        case 6:
                            controller_ListEmployee(listaEmpleados);
                            break;
                        case 7:
                            if(controller_sortEmployee(listaEmpleados) == 0){
                                flagStatusBinario=2;
                                flagStatusTexto=2;
                            }
                            break;
                        case 8:
                            if(flagStatusTexto ==2){
                                controller_saveAsText(archivoTexto,listaEmpleados);
                                flagStatusTexto=1;
                            }else{
                                printf("No hay cambios para guardar.\n");
                            }
                            break;
                        case 9:
                            if(flagStatusBinario ==2){
                                controller_saveAsBinary(archivoBinario,listaEmpleados);
                                flagStatusBinario = 1;
                            }else{
                                printf("No hay cambios para guardar.\n");
                            }
                            break;
                        case 10:
                          controller_close(listaEmpleados);
                            break;
                        }
    }while(opcion != 10);
    return 0;
}
