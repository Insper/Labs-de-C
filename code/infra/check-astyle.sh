#!/bin/bash
# Rafael Corsi @ Insper - 2020

red="\e[0;91m"
green="\e[0;92m"
yellow="\e[0;33m"
reset="\e[0m"

C_FILE=$1
CONFIG="--style=java --dry-run"
rtn=$(astyle $CONFIG $C_FILE)
unchanged=$(echo $rtn | grep Unchanged)
exitcode=0

echo "---------------------------------"
echo "- astyle                        -"
echo "---------------------------------"
if [ -z "$unchanged" ]; then
    echo -e ${yellow}
    echo $rtn
    echo -e "${red} você deve formatar o código antes de submeter!"
    echo " use 'make astyle'"
    exitcode=1
else
    echo -e " ${green}astyle formatado corretamente!"
fi


echo -e "${reset}"
exit $exitcode
