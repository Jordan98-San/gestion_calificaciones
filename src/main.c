#include <stdio.h>

int main() {
  int estudiantes;

  printf("Ingrese el numero de estudiantes: ");
  scanf("%d", &estudiantes);

  float calificaciones[estudiantes][3];

  printf("\nSistema de gestion de calificaciones\n");
  for (int i = 0; i < estudiantes; i++) {
    printf("\nEstudiante %d: \n", i + 1);
    for (int j = 0; j < 3; i++) {
      printf("Ingrese las calificaciones de la asignatura %d:", j + 1);
      scanf("%f", &calificaciones[i][j]);
    }
  }

  return 0;
}
