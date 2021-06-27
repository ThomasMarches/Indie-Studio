gcov build/tests/CMakeFiles/unit_tests.dir/*.cpp.gcno
lcov --capture --directory build/tests/CMakeFiles/unit_tests.dir/ --output-file build/tests/CMakeFiles/unit_tests.dir/gtest_coverage.info
genhtml build/tests/CMakeFiles/unit_tests.dir/gtest_coverage.info --output-directory build/tests/CMakeFiles/unit_tests.dir/CODE_COVERAGE
open build/tests/CMakeFiles/unit_tests.dir/CODE_COVERAGE/index.html
rm *.gcov