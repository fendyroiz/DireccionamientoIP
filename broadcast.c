#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*En este codigo se ingresa un ip,lo valida y lo muestra en binario
 * Fendy Adalahi Roiz Cosio*/

bool validacionOcteto(const char* octeto) {
    int valor = atoi(octeto);
    return (valor >= 0 && valor <= 255);
}

bool validacionIP(const char* ip) {
    char* token = strtok((char*)ip, ".");
    int cuenta = 0;

    while (token != NULL) {
        if (!validacionIP(token)) {
            return false;
        }
        token = strtok(NULL, ".");
        cuenta++;
    }

    return (cuenta == 4);
}



void binario(const char* ip) {
    int octetos[4];
    int i;

    // Divide la dirección IP en octetos usando el delimitador "."
    char* token = strtok((char*)ip, ".");
    for (i = 0; i < 4; i++) {
        if (token != NULL) {
            octetos[i] = atoi(token);
            token = strtok(NULL, ".");
        } else {
printf("Dirección IP inválida.\n");
            return;
        }
    }

    // Imprime la representación binaria de la dirección IP
    for (i = 0; i < 4; i++) {
        int j;
        for (j = 7; j >= 0; j--) {
            int bit = (octetos[i] >> j) & 1;
            printf("%d", bit);
        }
        if (i != 3) {
            printf(".");
        }
    }
    printf("\n");
}

int main() {
    char ip[16];

    printf("Ingrese la dirección IP: ");
    scanf("%15s", ip);

    binario(ip);

    return 0;
}
