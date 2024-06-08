#ifndef MATERIAS_H_INCLUDED
#define MATERIAS_H_INCLUDED

struct Materia;

typedef struct Materia * MateriaPtr;

MateriaPtr crearMateria(float promedio, char n[20]);

char * getNombreMateria(MateriaPtr m);
void setNombreMateria(MateriaPtr m, char n[20]);

float getPromedioMateria(MateriaPtr m);
void setPromedioMateria(MateriaPtr m, float p);

float getPromedioMateriaDatoPtr(void * m);


#endif // MATERIAS_H_INCLUDED