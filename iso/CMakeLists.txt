PROJECT(NextDivel-iso)

MESSAGE(STATUS "Generating ISO script")
FILE(WRITE iso.sh "#!/bin/bash\n grub-mkrescue -o nextdivel.iso next")
INSTALL(FILES iso.sh DESTINATION ..)
#ADD_CUSTOM_COMMAND(OUTPUT "nextdivel.iso" COMMAND "grub-mkrescue -o nextdivel.iso ${CMAKE_BINARY_DIR}/nextroot")
#EXECUTE_PROCESS(COMMAND "grub-mkrescue -o ${CMAKE_BINARY_DIR}/nextdivel.iso ${CMAKE_BINARY_DIR}/nextroot" RESULT_VARIABLE rv)
#MESSAGE(${rv})
