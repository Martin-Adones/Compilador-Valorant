#!/bin/bash

# Colores para mensajes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${YELLOW}Configurando el Compilador Valorant para Linux${NC}"

# Verificar dependencias
echo -e "\n${YELLOW}Verificando dependencias...${NC}"

# Función para verificar si un comando está instalado
check_command() {
    if ! command -v $1 &> /dev/null; then
        echo -e "${RED}$1 no está instalado.${NC}"
        return 1
    else
        echo -e "${GREEN}$1 está instalado correctamente.${NC}"
        return 0
    fi
}

# Verificar cada dependencia
missing_deps=0
check_command gcc || missing_deps=1
check_command flex || missing_deps=1
check_command bison || missing_deps=1
check_command make || missing_deps=1

# Si faltan dependencias, sugerir instalación
if [ $missing_deps -eq 1 ]; then
    echo -e "\n${RED}Faltan algunas dependencias. Por favor, instálalas con:${NC}"
    echo -e "sudo apt-get update"
    echo -e "sudo apt-get install -y gcc make flex bison"
    exit 1
fi

# Crear directorios necesarios
echo -e "\n${YELLOW}Creando directorios...${NC}"
mkdir -p bin build

# Compilar el proyecto
echo -e "\n${YELLOW}Compilando el proyecto...${NC}"
make clean
make

# Verificar si la compilación fue exitosa
if [ $? -eq 0 ]; then
    echo -e "\n${GREEN}¡Compilación exitosa!${NC}"
    echo -e "\nPuedes ejecutar los ejemplos con:"
    echo -e "${YELLOW}./bin/valorant ejemplos/calculadora.val${NC}"
    echo -e "${YELLOW}./bin/valorant ejemplos/calculadora_pro.val${NC}"
else
    echo -e "\n${RED}Error durante la compilación${NC}"
    exit 1
fi 