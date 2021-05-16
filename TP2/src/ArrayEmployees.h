/*
 * employee.h
 *
 *  Created on: 15 may. 2021
 *      Author: julio
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define SIZE_NAME 51
typedef struct
{
    int idEmployee;
    char name[SIZE_NAME];
    char lastName[SIZE_NAME];
    float salary;
    int sector;
    int isEmpty;
}Employee;

int emp_init(Employee *list, int len);
int emp_add(Employee *list, int len, int *id);
int emp_remove(Employee *list, int len);
int emp_modify(Employee* array,int limite);
int emp_findById(Employee *list, int len, int *indexObtained);
int emp_print(Employee *list);
int emp_printArray(Employee *list, int len);
int emp_searchEmptyIndex(Employee* list,int* emptyIndex,int len);
int emp_isEmptyIndex(Employee *pEmployee);
int emp_searchID(Employee *list, int len, int IdEntered, int *indexObtained);
int emp_validateList(Employee *list, int len);
int emp_inform(Employee* list, int len);
int emp_informSector(Employee* list, int len);
int emp_sortByLastName(Employee* list, int len);
int emp_sortBySector(Employee* list, int len);
int emp_SalaryInfo(Employee* pEmployee, int length);
int emp_ForceAdd(Employee *list, int len, char *name, char *lastName,
                 float salary,int sector, int index, int *id);
#endif /* ARRAYEMPLOYEES_H_ */
