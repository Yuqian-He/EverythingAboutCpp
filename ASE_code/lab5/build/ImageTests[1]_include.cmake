if(EXISTS "/home/s5529663/Desktop/2022/cpp_notes/ASE_code/lab5/build/ImageTests[1]_tests.cmake")
  include("/home/s5529663/Desktop/2022/cpp_notes/ASE_code/lab5/build/ImageTests[1]_tests.cmake")
else()
  add_test(ImageTests_NOT_BUILT ImageTests_NOT_BUILT)
endif()