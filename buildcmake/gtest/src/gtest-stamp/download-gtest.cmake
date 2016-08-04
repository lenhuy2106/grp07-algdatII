message(STATUS "downloading...
     src='http://googletest.googlecode.com/files/gtest-1.7.0.zip'
     dst='/cygdrive/c/Users/towlie1337/Uni/Algorithmen und Datenstrukturen II/grp07-algdatII/buildcmake/gtest/src/gtest-1.7.0.zip'
     timeout='none'")




file(DOWNLOAD
  "http://googletest.googlecode.com/files/gtest-1.7.0.zip"
  "/cygdrive/c/Users/towlie1337/Uni/Algorithmen und Datenstrukturen II/grp07-algdatII/buildcmake/gtest/src/gtest-1.7.0.zip"
  SHOW_PROGRESS
  # no TIMEOUT
  STATUS status
  LOG log)

list(GET status 0 status_code)
list(GET status 1 status_string)

if(NOT status_code EQUAL 0)
  message(FATAL_ERROR "error: downloading 'http://googletest.googlecode.com/files/gtest-1.7.0.zip' failed
  status_code: ${status_code}
  status_string: ${status_string}
  log: ${log}
")
endif()

message(STATUS "downloading... done")
