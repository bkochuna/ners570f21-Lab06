for f in *.cpp; do
    g++ -Wall -Werror -pedantic -O1 -std=c++11 -DFP_TYPE=float "$f" -o test_single.exe
    ./test_single.exe
    g++ -Wall -Werror -pedantic -O1 -std=c++11 -DFP_TYPE=double "$f" -o test_double.exe
    ./test_double.exe
done