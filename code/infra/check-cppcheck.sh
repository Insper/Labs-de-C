#!/bin/bash
# Rafael Corsi @ Insper - 2020

RUN_DIR=$1

red="\e[0;91m"
green="\e[0;92m"
yellow="\e[0;33m"
reset="\e[0m"

cppcheck --enable=warning,style,performance,portability,unusedFunction  --template="{file}:{line}: {severity}: {message}" $RUN_DIR 2> cppcheck.log

CNT=$(cat cppcheck.log | grep -E "(error|style)" | wc -l)

echo "---------------------------------"
echo "- cppcheck                      -"
echo "---------------------------------"
if [ $CNT -gt 0 ]; then
    echo -e ${yellow}
    cat cppcheck.log
    echo -e "${red} cppcheck encontrou" $CNT "erros!"
    echo -e " você deve corrigir antes de submeter "

else
    echo -e " ${green}cppcheck não encontrou erros!"
fi

echo -e "${reset}"
rm cppcheck.log

exit $CNT
