struct PersonaEst;

typedef struct PersonaEst * Persona;

Persona crearPersona(char nombre[], char apellido[], int dni, int edad);
int destruirPersona(Persona p);


//---------------EDAD---------------//

int getEdad(Persona p);
void setEdad(Persona p, int edad);

//---------------DNI---------------//

int getDni(Persona p);
void setDni(Persona p, int dni);

//---------------NOMBRE---------------//

char * getNombre(Persona p);
void setNombre(Persona p, char nombre[]);

//---------------APELLIDO---------------//

char * getApellido(Persona p);
void setApellido(Persona p, char apellido[]);