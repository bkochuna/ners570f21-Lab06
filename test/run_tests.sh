# Build file with main to run all tests
f="run_tests.cpp"
rm -f "$f"
touch "$f"
echo "#include \"unit_test_framework.h\"" >> "$f"

# Automatically include tests from any cpp file that starts with "test"
for fTest in test*.cpp; do
    printf "#include \"%s\"\n" "$fTest" >> "$f"
done

printf "\nTEST_MAIN()\n" >> "$f"


echo "=============================================================="
echo "                    Single precision tests                    "
echo "=============================================================="
g++ -Wall -Werror -pedantic -g -Ofast -std=c++11 -DFP_TYPE=float "$f" -o test_single.exe
./test_single.exe
printf "\n"
echo "=============================================================="
echo "                    Double precision tests                    "
echo "=============================================================="
g++ -Wall -Werror -pedantic -g -Ofast -std=c++11 -DFP_TYPE=double "$f" -o test_double.exe
./test_double.exe
