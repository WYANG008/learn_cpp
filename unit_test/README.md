sudo apt-get install libboost-test-dev
g++ -o test test.cpp -lboost_unit_test_framework-mt
./test --log_level=test_suite