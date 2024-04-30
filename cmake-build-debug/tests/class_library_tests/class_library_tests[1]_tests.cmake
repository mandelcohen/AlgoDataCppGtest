add_test([=[vector3.hello_this_is_a_test]=]  /Users/mandel/Documents/Projects/AlgoTestsCppGtest/cmake-build-debug/tests/class_library_tests/class_library_tests [==[--gtest_filter=vector3.hello_this_is_a_test]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[vector3.hello_this_is_a_test]=]  PROPERTIES WORKING_DIRECTORY /Users/mandel/Documents/Projects/AlgoTestsCppGtest/cmake-build-debug/tests/class_library_tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  class_library_tests_TESTS vector3.hello_this_is_a_test)
