PROJECT(NextDivel-iso)

MESSAGE(STATUS "Generating ISO")
ADD_CUSTOM_COMMAND(OUTPUT ${ISO} COMMAND grub-mkrescue -o nextdivel.iso ../nextroot)
