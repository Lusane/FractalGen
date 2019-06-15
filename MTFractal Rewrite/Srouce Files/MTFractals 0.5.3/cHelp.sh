if [[ -n $0 && -n $1 && -n $2 && -n $3 && -n $4 ]]; then
    xterm -e mate-terminal --working-directory=HOME/src/FractalGen/MultiThreadingTesting/compiled/ -e ${0} ${1} ${2} ${3} ${4}
elif [[ -n $0 && -n $1 && -n $2 && -n $3 && -z $4 ]]; then
    xterm -e mate-terminal --working-directory=HOME/src/FractalGen/MultiThreadingTesting/compiled/ -e ${0} ${1} ${2} ${3}
elif [[ -n $0 && -n $1 && -n $2 && -z $3 && -z $4 ]]; then
    xterm -e mate-terminal --working-directory=HOME/src/FractalGen/MultiThreadingTesting/compiled/ -e ${0} ${1} ${2}
elif [[ -n $0 && -n $1 && -z $2 && -z $3 && -z $4 ]]; then
    xterm -e mate-terminal --working-directory=HOME/src/FractalGen/MultiThreadingTesting/compiled/ -e ${0} ${1}
elif [[ -n $0 && -z $1 && -z $2 && -z $3 && -z $4 ]]; then
    xterm -e mate-terminal --working-directory=HOME/src/FractalGen/MultiThreadingTesting/compiled/ -e ${0}
else
    echo "Error No Arguments, this script needs at least 1 argument."
fi