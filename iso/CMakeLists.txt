PROJECT(NextDivel-iso)

MESSAGE(STATUS "Generating ISO script")
FILE(WRITE iso.sh "#!/bin/bash\n grub2-mkrescue -o nextdivel.iso next")
INSTALL(FILES iso.sh DESTINATION ..)
