chmod +x compiled/shellScripts/opiln.sh
chmod +x compiled/shellScripts/opln.sh
chmod +x compiled/shellScripts/opimg.sh
chmod +x compiled/shellScripts/oprm.sh
g++ MultiThreadingTesting/main.cpp -pthread -o /home/h4x0r/src/FractalGen/MultiThreadingTesting/compiled/MTFractals -I /home/h4x0r/src/FractalGen/MultiThreadingTesting/MultiThreadingTesting/
xterm -e mate-terminal --working-directory=/home/h4x0r/src/FractalGen/MultiThreadingTesting/compiled/ -e ./MTFractals