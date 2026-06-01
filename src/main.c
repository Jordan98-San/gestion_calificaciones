#include <stdio.h>

int main() {
  int estudiantes;

  printf("Ingrese el numero de estudiantes: ");
  scanf("%d", &estudiantes);

  float calificaciones[estudiantes][3];

  printf("\nSistema de gestion de calificaciones\n");

  for (int i = 0; i < estudiantes; i++) {
    printf("\nEstudiante %d\n", i + 1);

    for (int j = 0; j < 3; j++) {
      do {
        printf("Ingrese la calificacion de la asignatura %d: ", j + 1);
        scanf("%f", &calificaciones[i][j]);

        if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10) {
          printf("Error: la calificacion debe estar entre 0 y 10.\n");
        }

      } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
    }
  }

  printf("################## Resultado por estudiantes ######################");
  for (int i = 0; i < estudiantes; i++) {
    float suma = 0;
    float mayor = calificaciones[i][0];
    float menor = calificaciones[i][0];

    for (int j = 0; j < 3; i++) {
      suma += calificaciones[i][j];

      if (calificaciones[i][j] > mayor) {
        mayor = calificaciones[i][j];
      }

      if (calificaciones[i][j] < menor) {
        menor = calificaciones[i][j];
      }
    }
    float promedio = suma / 3;

    printf("\nEstudiante %d: ", i + 1);
    printf("\nPromeedio: %2.f", promedio);
    printf("\nCalificacion mas alta: %2.f", mayor);
    printf("\nCalificaion mas baja: %2.f", menor);
  }
  return 0;
}
