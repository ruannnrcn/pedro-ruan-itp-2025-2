#include <stdio.h>

// Função para ajustar os minutos e horas quando ultrapassam os limites
void ajustarHorario(int *hora, int *minuto) {
    // Ajusta minutos que ultrapassam 59
    if (*minuto >= 60) {
        *hora += *minuto / 60;
        *minuto = *minuto % 60;
    }
    
    // Ajusta horas que ultrapassam 23 (volta para 0)
    if (*hora >= 24) {
        *hora = *hora % 24;
    }
}

// Função para imprimir no formato 24h
void imprimirFormato24h(int hora, int minuto) {
    printf("%02d:%02d\n", hora, minuto);
}

// Função para imprimir no formato 12h (AM/PM)
void imprimirFormato12h(int hora, int minuto) {
    if (hora == 0) {
        printf("%02d:%02d AM\n", 12, minuto);
    } else if (hora < 12) {
        printf("%02d:%02d AM\n", hora, minuto);
    } else if (hora == 12) {
        printf("%02d:%02d PM\n", 12, minuto);
    } else {
        printf("%02d:%02d PM\n", hora - 12, minuto);
    }
}

// Função para imprimir o horário no formato escolhido
void imprimirHorario(int hora, int minuto, int formato) {
    if (formato == 0) {
        imprimirFormato24h(hora, minuto);
    } else {
        imprimirFormato12h(hora, minuto);
    }
}

// Função para calcular e imprimir um horário de ronda
void calcularRonda(int hora_inicial, int minuto_inicial, int acrescimo_hora, int acrescimo_minuto, int formato) {
    int hora = hora_inicial + acrescimo_hora;
    int minuto = minuto_inicial + acrescimo_minuto;
    
    ajustarHorario(&hora, &minuto);
    imprimirHorario(hora, minuto, formato);
}

int main() {
    int hora, minuto, formato;
    
    // Leitura dos dados
    printf("Digite a hora, minuto e formato (0 para 24h, 1 para 12h): ");
    scanf("%d %d %d", &hora, &minuto, &formato);
    
    // Imprime os horários das 5 rondas
    calcularRonda(hora, minuto, 1, 0, formato);      // +1h
    calcularRonda(hora, minuto, 2, 10, formato);     // +2h10m
    calcularRonda(hora, minuto, 4, 40, formato);     // +4h40m
    calcularRonda(hora, minuto, 12, 5, formato);     // +12h5m
    
    return 0;
}
