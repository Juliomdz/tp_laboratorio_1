#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Permite extraer los datos de un archivo de texto y guardarlos en memoria.
 * \param path char* Cadena de carateres que representa la ruta o nombre del archivo.
 * \param pArrayListEmployee LinkedList* Puntero que contiene la direccion de memoria de la lista de punteros donde se guardaran los datos.
 * \return int Retorna 0 si pudo hacer la carga en memoria; 1 si ya fueron cargados previamente; -1 si es nula.
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);


/** \brief Permite extraer los datos de un archivo binario y guardarlos en memoria.
 * \param path char* Cadena de carateres que representa la ruta o nombre del archivo.
 * \param pArrayListEmployee LinkedList* LinkedList* Puntero que contiene la direccion de memoria de la lista de punteros donde se guardaran los datos.
 * \return int Retorna 0 si pudo hacer la carga en memoria; 1 si ya fueron cargados previamente; -1 si es nula.
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);



/** \brief Permite crear un empleado y agregarlo a una lista.
 * \param pArrayListEmployee LinkedList* Puntero que contiene la direccion de la lista de punteros donde se guardara el nuevo empleado.
 * \return int Retorna 0 si pudo hacer el alta,1 si se cancela o -1 si hubo un error.
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);


/** \brief Funcion que permite editar un empleado de la lista.
 * \param pArrayListEmployee LinkedList* Puntero que contiene la direccion de la lista de punteros que apuntan a los empleados.
 * \return int Retorna 0 si pudo hacer la edicion,1 si se cancela o -1 su hubo un error.
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);


/** \brief Funcion principal que elimina un empleado de la lista.
 * \param pArrayListEmployee LinkedList* Puntero que contiene la lista de punteros que apuntan a los empleados.
 * \return int Retorna 0 si pudo hacer la baja,1 si se cancela o -1 su hubo un error.
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/** \brief Funcion que muestra todos los empleados disponibles.
 * \param pArrayListEmployee LinkedList* Puntero que contiene la direccion de memoria de la lista de punteros que apuntan a los empleados.
 * \return int Retorna 0 si pudo mostrar los empleados o -1 si hubo un error.
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);


/** \brief Permite ordenar la lista de punteros que apuntan a los empleados.
 * \param pArrayListEmployee LinkedList* Puntero que contiene la direccion de la lista con los punteros de los empleados.
 * \return int Retorna 0 si pudo hacer el ordenamiento,1 si se cancelo o -1 si hubo un error.
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);



/** \brief Permite guardar la lista de empleados en un archivo de texto.
 * \param path char* Cadena de caracteres que representa la ruta o nombre del archivo donde se escribiran los datos.
 * \param pArrayListEmployee LinkedList* Puntero que contiene la direccion de memoria de la lista de  empleados a guardar.
 * \return int Retorna 0 si pudo hacer el guardado o -1 si hubo un error.
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


/** \brief Permite guardar la lista en forma binaria.
 * \param path char* Cadena de caracteres que representa la ruta o nombre del archivo donde se escribiran los datos.
 * \param pArrayListEmployee LinkedList* Puntero que contiene la direccion de memoria de la lista de  empleados a guardar.
 * \return int Retorna 0 si pudo hacer el guardado o -1 si hubo un error.
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Cierra el programa, borrando la lista de memoria y liberandola.
 * \param pArrayListEmployee LinkedList* Puntero que contiene la direccion de memoria de la lista de  empleados.
 * \return int Retorna 0 si completó el borrado; -1 si no hay lista que borrar.
 */
int controller_close(LinkedList* pArrayListEmployee);
