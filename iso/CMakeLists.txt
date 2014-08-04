PROJECT(NextDivel-iso)

MESSAGE(STATUS "Generating ISO script")
FILE(WRITE iso.sh "#!/bin/bash\n grub-mkrescue --compress=xz --product-name=NextDivel --product-version=0.1.0 -o nextdivel.iso next")
INSTALL(PROGRAMS iso.sh DESTINATION ..)
