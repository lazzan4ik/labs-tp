if(EXISTS "C:/Users/mndav/tp_labs/TP_Lab6/out/build/x64-debug/TP_Lab6[1]_tests.cmake")
  include("C:/Users/mndav/tp_labs/TP_Lab6/out/build/x64-debug/TP_Lab6[1]_tests.cmake")
else()
  add_test(TP_Lab6_NOT_BUILT TP_Lab6_NOT_BUILT)
endif()
