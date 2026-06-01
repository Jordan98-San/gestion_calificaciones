#include <stdio.h>
#include <stdlib.h>

int main() {
  int estudiantes;

  printf("Ingrese el numero de estudiantes: ");
  scanf("%d", &estudiantes);

  float (*calificaciones)[3];
  calificaciones = malloc(estudiantes * sizeof(*calificaciones));

  if (calificaciones == NULL) {
    printf("Error al reservar memoria\n");
    return 1;
  }

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

  printf("\n========== RESULTADOS POR ESTUDIANTE ==========\n");

  for (int i = 0; i < estudiantes; i++) {
    float suma = 0;
    float mayor = calificaciones[i][0];
    float menor = calificaciones[i][0];

    for (int j = 0; j < 3; j++) {
      suma += calificaciones[i][j];

      if (calificaciones[i][j] > mayor) {
        mayor = calificaciones[i][j];
      }

      if (calificaciones[i][j] < menor) {
        menor = calificaciones[i][j];
      }
    }

    float promedio = suma / 3;

    printf("\nEstudiante %d", i + 1);
    printf("\nPromedio: %.2f", promedio);
    printf("\nCalificacion mas alta: %.2f", mayor);
    printf("\nCalificacion mas baja: %.2f\n", menor);
  }

  printf("\n========== RESULTADOS POR ASIGNATURA ==========\n");

  for (int j = 0; j < 3; j++) {
    float suma = 0;
    float mayor = calificaciones[0][j];
    float menor = calificaciones[0][j];

    int reprobados = 0;
    int aprobados = 0;

    for (int i = 0; i < estudiantes; i++) {
      suma += calificaciones[i][j];

      if (calificaciones[i][j] > mayor) {
        mayor = calificaciones[i][j];
      }

      if (calificaciones[i][j] < menor) {
        menor = calificaciones[i][j];
      }
      if (calificaciones[i][j] >= 6) {
        aprobados++;
      } else {
        reprobados++;
      }
    }

    float promedio = suma / estudiantes;

    printf("\nAsignatura %d", j + 1);
    printf("\nPromedio: %.2f", promedio);
    printf("\nCalificacion mas alta: %.2f", mayor);
    printf("\nCalificacion mas baja: %.2f\n", menor);
    printf("\nAprobados: %d", aprobados);
    printf("\nReprobados: %d \n", reprobados);
  }

  free(calificaciones);
  return 0;
}
