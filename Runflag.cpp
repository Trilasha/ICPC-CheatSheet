code -r ~/.bashrc
source ~/.bashrc

run(){
    g++ $1.cpp -std=c++17 -O2 -Wall -o $1.out && ./$1.out< in.txt > out.txt && rm $1.out 
}