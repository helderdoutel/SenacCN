#include <string.h>
int elevado(float x, int y){
    for(int z=0; z < y-1; z++){
        x = x*x;
    }
    if(y == 0){
        return 1;
    }
    return x;
}

int char_para_int(char c){
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

char int_para_char(int num){
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

int para_base10(int baseatual, char *arg){
    // printf("numero: %s\n", arg);
    int len_numero = strlen(arg);
    int y = len_numero;
    int valor = 0;
    for(int x=0; x<len_numero; x++){
        y = y - 1;
        // printf("%c*%d^%d %d\n", arg[x], baseatual, y, elevado(baseatual, y));
        valor += (char_para_int(arg[x]) * elevado(baseatual, y));
    }
    return valor;
}

char* de_base10(char resp[], int base_nova, int dec){
    int x;
    for(x = 0; dec > 0; x++){
        resp[x] = int_para_char(dec % base_nova);
        dec = dec/base_nova;
    }
    resp[x] = '\0';
    int len = 0;
    len = strlen(resp);
    char temp;
    for(x = 0; x < len/2; x++){
        temp = resp[x];
        resp[x] = resp[len - x - 1];
        resp[len - x - 1] = temp;
    }
    return resp;
}
