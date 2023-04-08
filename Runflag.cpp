code -r ~/.bashrc
source ~/.bashrc

run(){
    g++ $1.cpp -std=c++17 =02 -wall -0 $1.out && ./$1.out< in.txt > out.txt && rm $1.out 
}