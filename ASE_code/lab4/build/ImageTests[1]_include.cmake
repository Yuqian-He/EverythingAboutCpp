if(EXISTS "/home/s5529663/Desktop/2022/cpp_notes/ASE/lab4/build/ImageTests[1]_tests.cmake")
  include("/home/s5529663/Desktop/2022/cpp_notes/ASE/lab4/build/ImageTests[1]_tests.cmake")
else()
  add_test(ImageTests_NOT_BUILT ImageTests_NOT_BUILT)
endif()
