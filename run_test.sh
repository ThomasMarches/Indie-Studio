rm build/tests/CMakeFiles/unit_tests.dir/CODE_COVERAGE
rm build/tests/CMakeFiles/unit_tests.dir/*.gcno
rm build/tests/CMakeFiles/unit_tests.dir/*.o
rm build/tests/CMakeFiles/unit_tests.dir/*.gcda
rm build/Fox/CMakeFiles/fox_engine.dir/src/raylib-cpp/*.gcda
rm build/Fox/CMakeFiles/fox_engine.dir/src/raylib-cpp/*.gcno
rm build/Fox/CMakeFiles/fox_engine.dir/src/*.gcno
rm build/Fox/CMakeFiles/fox_engine.dir/src/*.gcda
cd build/ && cmake .. && cmake --build . && cd .. && ./tests/unit_tests