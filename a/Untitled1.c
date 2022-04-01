#include <stdio.h>
#define N 2

typedef struct
{
int d, m, y;
} fecha;

typedef struct
{
char nombre[50];
char apellido1[50];
char apellido2[50];
fecha fNac;
} contacto;

void printContacto(contacto persona);
int compFecha(fecha f1, fecha f2);

int main()
{
contacto contactos[N] ;
int i, iNac;

for (i = 0; i < N; i++)
{
printf("Contacto %d\n", i + 1);
printf("Nombre:\n");
scanf("%49[^\n]", contactos[i].nombre);
printf("Apellido 1:\n");
scanf("%49s", contactos[i].apellido1);
printf("Apellido 2:\n");
scanf("%49s", contactos[i].apellido2);
printf("Fecha (d m y):\n");
scanf("%d %d %d",
&contactos[i].fNac.d,
&contactos[i].fNac.m,
&contactos[i].fNac.y);
}
   iNac = compFecha(contactos[0].fNac, contactos[1].fNac);

   switch(iNac)
   {
       case 1:
           printContacto(contactos[0]);
           break;
        case -1:
            printContacto(contactos[1]);
            break;
        case 0:
            for (i = 0; i < N; i++)
            printContacto(contactos[i]);
            break;
       }
    return 0;

}

void printContacto(contacto persona)
{
printf("%s %s %s",
persona.nombre,
persona.apellido1,
persona.apellido2);
}

int compFecha(fecha f1, fecha f2)
{
if (f1.y > f2.y)
return 1;
     else if (f1.y < f2.y)
     return -1;
else
{
if (f1.m > f2.m)
return 1;
else if (f1.m < f2.m)
return -1;
else
{
if (f1.d > f2.d)
return 1;
else if (f1.d < f2.d)
return -1;
else return 0;
}
}
}
