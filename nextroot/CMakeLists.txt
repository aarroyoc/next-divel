PROJECT(NextDivel-nextroot)

MESSAGE(STATUS "Creating NextRoot directory")
FILE(COPY ../grub DESTINATION boot)
FILE(COPY ../src/START.ELF DESTINATION next)
FILE(COPY ../include DESTINATION .)
