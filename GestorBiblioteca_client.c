/*
 * Muy Importante **
 * *****************
 * Para la entrada de un carácter por teclado utilizar la función __fpurge(stdin) antes de la función scanf.
 * La función __fpurge da un warning en el proceso de compilación pero se puede ignorar sin problemas.
 */

#include "GestorBiblioteca.h"

void gestorbiblioteca_1(char *host)
{
	CLIENT *clnt;
	int *result_1;
	char conexion_1_arg;
	bool_t *result_2;
	int desconexion_1_arg;
	int *result_3;
	TFichero cargardatos_1_arg;
	bool_t *result_4;
	int guardardatos_1_arg;
	int *result_5;
	TNuevo nuevolibro_1_arg;
	int *result_6;
	TComRet comprar_1_arg;
	int *result_7;
	TComRet retirar_1_arg;
	bool_t *result_8;
	TOrdenacion ordenar_1_arg;
	int *result_9;
	int nlibros_1_arg;
	int *result_10;
	TConsulta buscar_1_arg;
	TLibro *result_11;
	TPosicion descargar_1_arg;
	int *result_12;
	TPosicion prestar_1_arg;
	int *result_13;
	TPosicion devolver_1_arg;

#ifndef DEBUG
	clnt = clnt_create(host, GESTORBIBLIOTECA, GESTORBIBLIOTECA_VER, "udp");
	if (clnt == NULL)
	{
		clnt_pcreateerror(host);
		exit(1);
	}
#endif /* DEBUG */

	result_1 = conexion_1(&conexion_1_arg, clnt);
	if (result_1 == (int *)NULL)
	{
		clnt_perror(clnt, "call failed");
	}
	result_2 = desconexion_1(&desconexion_1_arg, clnt);
	if (result_2 == (bool_t *)NULL)
	{
		clnt_perror(clnt, "call failed");
	}
	result_3 = cargardatos_1(&cargardatos_1_arg, clnt);
	if (result_3 == (int *)NULL)
	{
		clnt_perror(clnt, "call failed");
	}
	result_4 = guardardatos_1(&guardardatos_1_arg, clnt);
	if (result_4 == (bool_t *)NULL)
	{
		clnt_perror(clnt, "call failed");
	}
	result_5 = nuevolibro_1(&nuevolibro_1_arg, clnt);
	if (result_5 == (int *)NULL)
	{
		clnt_perror(clnt, "call failed");
	}
	result_6 = comprar_1(&comprar_1_arg, clnt);
	if (result_6 == (int *)NULL)
	{
		clnt_perror(clnt, "call failed");
	}
	result_7 = retirar_1(&retirar_1_arg, clnt);
	if (result_7 == (int *)NULL)
	{
		clnt_perror(clnt, "call failed");
	}
	result_8 = ordenar_1(&ordenar_1_arg, clnt);
	if (result_8 == (bool_t *)NULL)
	{
		clnt_perror(clnt, "call failed");
	}
	result_9 = nlibros_1(&nlibros_1_arg, clnt);
	if (result_9 == (int *)NULL)
	{
		clnt_perror(clnt, "call failed");
	}
	result_10 = buscar_1(&buscar_1_arg, clnt);
	if (result_10 == (int *)NULL)
	{
		clnt_perror(clnt, "call failed");
	}
	result_11 = descargar_1(&descargar_1_arg, clnt);
	if (result_11 == (TLibro *)NULL)
	{
		clnt_perror(clnt, "call failed");
	}
	result_12 = prestar_1(&prestar_1_arg, clnt);
	if (result_12 == (int *)NULL)
	{
		clnt_perror(clnt, "call failed");
	}
	result_13 = devolver_1(&devolver_1_arg, clnt);
	if (result_13 == (int *)NULL)
	{
		clnt_perror(clnt, "call failed");
	}
#ifndef DEBUG
	clnt_destroy(clnt);
#endif /* DEBUG */
}

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define Cls system("clear")
#define Pause system("read -p \"Pulsa la tecla return para continuar..... \" a")

#define MostrarAviso(Texto) \
	{                       \
		printf(Texto);      \
		Pause;              \
	}

int MenuPrincipal()
{
	int Salida;
	do
	{
		Cls;
		printf(" GESTOR BIBLIOTECARIO 1.0 (M. PRINCIPAL)\n");
		printf("*****************************************\n");
		printf("\t1.- M. Administración\n");
		printf("\t2.- Consulta de libros\n");
		printf("\t3.- Préstamo de libros\n");
		printf("\t4.- Devolución de libros\n");
		printf("\t0.- Salir\n\n");
		printf(" Elige opción: ");
		__fpurge(stdin);
		scanf("%d", &Salida);
		if (Salida < 0 || Salida > 4)
			MostrarAviso("\n\n *** Error en la entrada de Datos.***\n\n");
	} while (Salida < 0 || Salida > 4);
	return Salida;
}

int MenuAdministracion()
{
	int Salida;
	do
	{
		Cls;
		printf(" GESTOR BIBLIOTECARIO 1.0 (M. ADMINISTRACION)\n");
		printf("**********************************************\n");
		printf("\t1.- Cargar datos Biblioteca\n");
		printf("\t2.- Guardar datos Biblioteca\n");
		printf("\t3.- Nuevo libro\n");
		printf("\t4.- Comprar libros\n");
		printf("\t5.- Retirar libros\n");
		printf("\t6.- Ordenar libros\n");
		printf("\t7.- Buscar libros\n");
		printf("\t8.- Listar libros\n");
		printf("\t0.- Salir\n\n");
		__fpurge(stdin);
		printf(" Elige opción: ");
		scanf("%d", &Salida);
		if (Salida < 0 || Salida > 8)
			MostrarAviso("\n\n *** Error en la entrada de Datos.***\n\n");
	} while (Salida < 0 || Salida > 8);
	return Salida;
}

void Formatea(char *Salida, const char *p, int ancho, char Caracter)
{
	Cadena vacia;
	int len = ancho - strlen(p);
	int l = 0, c = 0;

	while (p[l] != '\0')
	{
		if ((unsigned char)p[l] > 128)
			c++;
		l++;
	}
	len += c / 2;

	if (len < 0)
		len = 0;
	for (int i = 0; i < len; i++)
		vacia[i] = Caracter;
	vacia[len] = '\0';

	sprintf(Salida, "%s%s", p, vacia);
}

void MostrarLibro(TLibro *L, int Pos, bool_t Cabecera)
{
	Cadena T, A, B, PI;
	if (Cabecera == TRUE)
	{
		printf("%-*s%-*s%-*s%*s%*s%*s\n", 5, "POS", 58, "TITULO", 18, "ISBN", 4, "DIS", 4, "PRE", 4, "RES");
		printf("     %-*s%-*s%-*s\n", 30, "AUTOR", 28, "PAIS (IDIOMA)", 12, "AÑO");
		Formatea(B, "*", 93, '*');
		printf("%s\n", B);
	}
	Formatea(T, L->Titulo, 58, ' ');
	Formatea(A, L->Autor, 30, ' ');
	strcpy(B, L->Pais);
	strcat(B, " (");
	strcat(B, L->Idioma);
	strcat(B, ")");
	Formatea(PI, B, 28, ' ');
	printf("%-5d%s%-*s%*d%*d%*d\n", Pos + 1, T, 18, L->Isbn, 4, L->NoLibros, 4, L->NoPrestados, 4, L->NoListaEspera);
	printf("     %s%s%-*d\n", A, PI, 12, L->Anio);
}

/*Función que devuelve TRUE si el Campo correspondiente de Libro L contiene el Texto.
  Se utiliza para Buscar libros. */
bool_t Comprobar(TLibro *L, Cadena Texto, char Campo)
{
	bool_t Encontrado = FALSE;
	switch (tolower(Campo))
	{
	case 'i':
		Encontrado = strstr(L->Isbn, Texto) != NULL ? TRUE : FALSE;
		break;
	case 't':
		Encontrado = strstr(L->Titulo, Texto) != NULL ? TRUE : FALSE;
		break;
	case 'a':
		Encontrado = strstr(L->Autor, Texto) != NULL ? TRUE : FALSE;
		break;
	case 'p':
		Encontrado = strstr(L->Pais, Texto) != NULL ? TRUE : FALSE;
		break;
	case 'd':
		Encontrado = strstr(L->Idioma, Texto) != NULL ? TRUE : FALSE;
		break;
	case '*':
		Encontrado = (strstr(L->Isbn, Texto) != NULL || strstr(L->Titulo, Texto) != NULL || strstr(L->Autor, Texto) != NULL ||
					  strstr(L->Pais, Texto) != NULL || strstr(L->Idioma, Texto) != NULL)
						 ? TRUE
						 : FALSE;
	}
	return Encontrado;
}
int main(int argc, char *argv[])
{
	char *host;
	CLIENT *clnt;

	int SalidaPrincipal = -1, SalidaAdmin = -1;
	Cadena password, texto, isbn_buscar;
	char campo, sn;
	int idAdmin = -1;
	int i, n_libros, cabecera;

	int *res_int;
	bool_t *res_bool;
	TLibro *res_libro;

	TFichero arg_fichero;
	TNuevo arg_nuevo;
	TComRet arg_comret;
	TOrdenacion arg_ord;
	TPosicion arg_pos;
	TConsulta arg_cons;

	if (argc < 2)
	{
		printf("usage: %s server_host\n", argv[0]);
		exit(1);
	}
	host = argv[1];

	clnt = clnt_create(host, GESTORBIBLIOTECA, GESTORBIBLIOTECA_VER, "udp");
	if (clnt == NULL)
	{
		clnt_pcreateerror(host);
		exit(1);
	}

	while (SalidaPrincipal != 0)
	{
		SalidaPrincipal = MenuPrincipal();
		switch (SalidaPrincipal)
		{
		case 1:
		{
			printf("Por favor inserte la contraseña de Administración: ");
			
			__fpurge(stdin);
			 scanf("%s", password);
			res_int = conexion_1(password, clnt);
			if (res_int == NULL)
			{
				clnt_perror(clnt, "call failed");
			}
			else if (*res_int > 0)
			{
				idAdmin = *res_int;
				MostrarAviso("\n*** Contraseña correcta, puede acceder al menú de Administración. ***\n");
				SalidaAdmin = -1;
				while (SalidaAdmin != 0)
				{
					SalidaAdmin = MenuAdministracion();
					switch (SalidaAdmin)
					{
					case 1:
					{
						arg_fichero.Ida = idAdmin;
						printf("Introduce el nombre del fichero de datos: ");
						__fpurge(stdin);
						scanf("%s", arg_fichero.NomFile);
						res_int = cargardatos_1(&arg_fichero, clnt);
						if (res_int && *res_int == 1)
							MostrarAviso("\n*** La biblioteca ha sido cargada. ***\n");
						if (res_int && *res_int == -2)
							MostrarAviso("\n*** No se ha podido abrir el fichero indicado. ***\n");
						break;
					}
					case 2:
					{
						res_bool = guardardatos_1(&idAdmin, clnt);
						if (res_bool && *res_bool)
							MostrarAviso("\n*** Se ha guardado el estado actual de la biblioteca. ***\n");
						break;
					}
					case 3:
					{
						arg_nuevo.Ida = idAdmin;
						printf("Introduce el Isbn: ");
						__fpurge(stdin);
						scanf("%s", arg_nuevo.Libro.Isbn);
						printf("Introduce el Autor: ");
						__fpurge(stdin);
						scanf("%s", arg_nuevo.Libro.Autor);
						printf("Introduce el Titulo: ");
						__fpurge(stdin);
						scanf("%s", arg_nuevo.Libro.Titulo);
						printf("Introduce el Año: ");
						scanf("%d", &arg_nuevo.Libro.Anio);
						printf("Introduce el País: ");
						__fpurge(stdin);
						scanf("%s", arg_nuevo.Libro.Pais);
						printf("Introduce el Idioma: ");
						__fpurge(stdin);
						scanf("%s", arg_nuevo.Libro.Idioma);
						printf("Introduce Número de Libros inicial: ");
						scanf("%d", &arg_nuevo.Libro.NoLibros);
						arg_nuevo.Libro.NoPrestados = 0;
						arg_nuevo.Libro.NoListaEspera = 0;
						res_int = nuevolibro_1(&arg_nuevo, clnt);
						if (res_int != NULL)
						{
							if (res_int && *res_int == 1)
							{
								MostrarAviso("\n*** El libro ha sido añadido correctamente. ***\n");
							}
							else if (res_int && *res_int == 0)
							{
								MostrarAviso("\n*** ERROR: Ya hay un libro registrado con ese ISBN. ***\n");
							}
							else if (res_int && *res_int == -1)
							{
								MostrarAviso("\n*** ERROR: No tienes permisos de Administrador válidos. ***\n");
							}
							if (res_int && *res_int == 1)
								MostrarAviso("\n*** El libro ha sido añadido correctamente. ***\n");
						}
						break;
					}
					case 4:
                    {
                        arg_comret.Ida = idAdmin;
                        printf("Introduce Isbn a Buscar: ");
                        __fpurge(stdin);
                        scanf("%s", arg_comret.Isbn);
                        arg_cons.Ida = idAdmin;
                        strcpy(arg_cons.Isbn, arg_comret.Isbn);
                        res_int = buscar_1(&arg_cons, clnt);
                        if (res_int && *res_int >= 0)
                        {
                            arg_pos.Ida = idAdmin;
                            arg_pos.Pos = *res_int;
                            res_libro = descargar_1(&arg_pos, clnt);
                            MostrarLibro(res_libro, arg_pos.Pos, TRUE);
                            printf("¿Es este el libro que deseas comprar más unidades (s/n) ? ");
                            __fpurge(stdin);
                            scanf("%c", &sn);
                            if (tolower(sn) == 's')
                            {
                                printf("Introduce Número de Libros comprados: ");
                                scanf("%d", &arg_comret.NoLibros);
                                res_int = comprar_1(&arg_comret, clnt);
                                if (res_int != NULL && *res_int == 1) {
                                    MostrarAviso("\n*** Se han añadido los nuevos libros. ***\n");
								arg_ord.Ida = idAdmin;
								printf("Código de Ordenación\n0. Por Isbn\n1. Por Título\n2. Por Autor\n3. Por Año\n4. Por Pais\n5. Por Idioma\n6. Por nº de libros Disponibles\n7. Por nº de libros Prestados.\n8. Por nº de libros en espera\nIntroduce Código: ");
								scanf("%d", &arg_ord.Campo);
								res_bool = ordenar_1(&arg_ord, clnt);
									if (res_bool && *res_bool)
										MostrarAviso("\n*** La biblioteca ha sido ordenada correctamente. ***\n");	
							} else {
									MostrarAviso("\n*** Error al comprar los libros. ***\n");
                                }
                            }
                        } else {
                            MostrarAviso("\n*** Libro no encontrado. ***\n");
                        }
                        break;
                    }

                    case 5:
                    {
                        arg_comret.Ida = idAdmin;
                        printf("Introduce Isbn a Buscar: ");
                        __fpurge(stdin);
                        scanf("%s", arg_comret.Isbn);
                        arg_cons.Ida = idAdmin;
                        strcpy(arg_cons.Isbn, arg_comret.Isbn);
                        res_int = buscar_1(&arg_cons, clnt);
                        if (res_int && *res_int >= 0)
                        {
                            arg_pos.Ida = idAdmin;
                            arg_pos.Pos = *res_int;
                            res_libro = descargar_1(&arg_pos, clnt);
                            MostrarLibro(res_libro, arg_pos.Pos, TRUE);
                            printf("¿Es este el libro que deseas retirar unidades (s/n) ? ");
                            __fpurge(stdin);
                            scanf("%c", &sn);
                            if (tolower(sn) == 's')
                            {
                                printf("Introduce Número de unidades a retirar: ");
                                scanf("%d", &arg_comret.NoLibros);
                                res_int = retirar_1(&arg_comret, clnt);
                                if (res_int != NULL && *res_int == 1) {
                                    MostrarAviso("\n*** Se han retirado el número de libros indicados. ***\n");
                                } else {
                                     MostrarAviso("\n*** Error al retirar los libros (no hay suficientes o error de ID). ***\n");
                                }
                            }
                        } else {
                             MostrarAviso("\n*** Libro no encontrado. ***\n");
                        }
                        break;
                    }
					case 6:
					{
						arg_ord.Ida = idAdmin;
						printf("Código de Ordenación\n0. Por Isbn\n1. Por Título\n2. Por Autor\n3. Por Año\n4. Por Pais\n5. Por Idioma\n6. Por nº de libros Disponibles\n7. Por nº de libros Prestados.\n8. Por nº de libros en espera\nIntroduce Código: ");
						scanf("%d", &arg_ord.Campo);
						res_bool = ordenar_1(&arg_ord, clnt);
						if (res_bool && *res_bool)
							MostrarAviso("\n*** La biblioteca ha sido ordenada correctamente. ***\n");
						break;
					}
					case 7:
					case 8:
					{
						if (SalidaAdmin == 7)
						{
							printf("Introduce el texto a Buscar: ");
							__fpurge(stdin);
							scanf("%s", texto);
							printf("Código de Búsqueda\nI. Por Isbn\nT. Por Título\nA. Por Autor\nP. Por País\nD. Por Idioma\n*. Por todos los campos.\nIntroduce Código: ");
							__fpurge(stdin);
							scanf("%c", &campo);
						}
						res_int = nlibros_1(&idAdmin, clnt);
						if (res_int)
						{
							n_libros = *res_int;
							cabecera = TRUE;
							for (i = 0; i < n_libros; i++)
							{
								arg_pos.Ida = idAdmin;
								arg_pos.Pos = i;
								res_libro = descargar_1(&arg_pos, clnt);
								if (SalidaAdmin == 8 || Comprobar(res_libro, texto, campo))
								{
									MostrarLibro(res_libro, i, cabecera);
									cabecera = FALSE;
								}
							}
							Pause;
						}
						break;
					}
					case 0:
					{
						desconexion_1(&idAdmin, clnt);
						break;
					}
					}
				}
			}
			else
			{
				MostrarAviso("\n*** Error de conexión o contraseña incorrecta. ***\n");
			}
			break;
		}
		case 3:
		{
			printf("Introduce el texto a Buscar: ");
			__fpurge(stdin);
			scanf("%s", texto);
			printf("Código de Consulta\nI. Por Isbn\nT. Por Título\nA. Por Autor\nP. Por país\nD. Por Idioma\n*.- Por todos los campos.\nIntroduce Código: ");
			__fpurge(stdin);
			scanf("%c", &campo);

			res_int = nlibros_1(&idAdmin, clnt);
			if (res_int)
			{
				n_libros = *res_int;
				cabecera = TRUE;
				for (i = 0; i < n_libros; i++)
				{
					arg_pos.Ida = idAdmin;
					arg_pos.Pos = i;
					res_libro = descargar_1(&arg_pos, clnt);
					if (Comprobar(res_libro, texto, campo))
					{
						MostrarLibro(res_libro, i, cabecera);
						cabecera = FALSE;
					}
				}

				printf("¿Quieres sacar algún libro de la biblioteca (s/n) ? ");
				__fpurge(stdin);
				scanf("%c", &sn);
				if (tolower(sn) == 's')
				{
					printf("Introduce la Posición del libro a solicitar su préstamo: ");
					scanf("%d", &arg_pos.Pos);
					arg_pos.Pos--;
					arg_pos.Ida = idAdmin;
					res_int = prestar_1(&arg_pos, clnt);
					if(*res_int==1){
					MostrarAviso("\n*** El préstamo se ha concedido, recoge el libro en el mostrador. ***\n");}
					else if(*res_int == 0){
					MostrarAviso("\n*** *Se le ha puesto en la lista de espera**\n");}
					else{
					MostrarAviso("\n*** Hay un error con la posicion elegida ***\n");}
				}
				else
				{
					Pause;
				}
			}
			break;
		}
		case 4:
        {
            printf("Introduce el Isbn a Buscar: ");
            __fpurge(stdin);
            scanf("%127s", isbn_buscar); 

            res_int = nlibros_1(&idAdmin, clnt);
            
            if (res_int != NULL && *res_int >= 0)
            {
                n_libros = *res_int;
                cabecera = TRUE;
                int encontrados = 0; 

                for (i = 0; i < n_libros; i++)
                {
                    arg_pos.Ida = idAdmin;
                    arg_pos.Pos = i;
                    res_libro = descargar_1(&arg_pos, clnt);
                    
                    if (res_libro != NULL) 
                    {
                        if (strstr(res_libro->Isbn, isbn_buscar) != NULL)
                        {
                            MostrarLibro(res_libro, i, cabecera);
                            cabecera = FALSE;
                            encontrados++;
                        }
                    }
                }

                if (encontrados > 0)
                {
                    printf("¿Quieres devolver algún libro de la biblioteca (s/n) ? ");
                    __fpurge(stdin);
                    scanf("%c", &sn);
                    if (tolower(sn) == 's')
                    {
                        printf("Introduce la Posición del libro a devolver: ");
                        scanf("%d", &arg_pos.Pos);
                        arg_pos.Pos--; 
                        arg_pos.Ida = idAdmin;
                        
                        res_int = devolver_1(&arg_pos, clnt);
                        
                        if (res_int != NULL && *res_int == 1) 
                        {
                            MostrarAviso("\n*** Se ha devuelto el libro y se pondrá en la estantería. ***\n");
                        }
                        else
                        {
                            MostrarAviso("\n*** Error: No se pudo devolver el libro (Permisos o libro no prestado). ***\n");
                        }
                    }
                }
                else
                {
                    MostrarAviso("\n*** No se ha encontrado ningún libro con ese ISBN. ***\n");
                }
            }
            else
            {
                MostrarAviso("\n*** Error al consultar el servidor (No autorizado o error de red). ***\n");
            }
            break;
        }
		case 0:
		{
			break;
		}

		case 2:
		{

			printf("Introduce el texto a Buscar: ");
			__fpurge(stdin);
			scanf("%s", texto);
			printf("Código de Búsqueda\nI. Por Isbn\nT. Por Título\nA. Por Autor\nP. Por País\nD. Por Idioma\n*. Por todos los campos.\nIntroduce Código: ");
			__fpurge(stdin);
			scanf("%c", &campo);

			res_int = nlibros_1(&idAdmin, clnt);
			if (res_int)
			{
				n_libros = *res_int;
				cabecera = TRUE;
				for (i = 0; i < n_libros; i++)
				{
					arg_pos.Ida = idAdmin;
					arg_pos.Pos = i;
					res_libro = descargar_1(&arg_pos, clnt);
					if (Comprobar(res_libro, texto, campo))
					{
						MostrarLibro(res_libro, i, cabecera);
						cabecera = FALSE;
					}
				}
				Pause;
			}
			break;
		}
		}
	}
	clnt_destroy(clnt);
	exit(0);
}