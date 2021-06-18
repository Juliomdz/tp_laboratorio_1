/** \brief Funcion que lee los datos de tipo Employee desde un archivo de texto y los alamacena en una lista Linkedlist.
 * \param pFile FILE* Puntero que contiene la direccion del archivo de donde se extraeran los datos.
 * \param pArrayListEmployee LinkedList* Puntero que contiene la direccion de la lista donde se guardaran los datos.
 * \return int Retorna 0 si pudo leer los datos o -1 si hubo un error.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);


/** \brief Funcion que lee los datos de tipo Employee desde  un archivo binario y los almacena en una lista Linkedlist.
 * \param pFile FILE* Puntero que contiene la direccion del archivo de donde extraera los datos.
 * \param pArrayListEmployee LinkedList* Puntero que contiene la direccion de la lista donde se guardaran los datos.
 * \return int Retorna 0 si pudo leer los datos o -1 si hubo un error.
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
