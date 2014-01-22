PROJECT(NextDivel)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
SET(CMAKE_INSTALL_PREFIX "")

ADD_SUBDIRECTORY(src) #Build components and install its into /next
ADD_SUBDIRECTORY(nextroot) #Copy files from grub and include to /
ADD_SUBDIRECTORY(iso) #Create a script for create ISO
MESSAGE("make DESTDIR=next install")
MESSAGE("./iso.sh")

FIND_PACKAGE(Doxygen)
IF(DOXYGEN_FOUND)
	ADD_CUSTOM_TARGET(doc
	${DOXYGEN_EXECUTABLE} ${PROJECT_SOURCE_DIR}/Doxyfile
	WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
	COMMENT "Generating API documentation with Doxygen" VERBATIM
	)

ENDIF(DOXYGEN_FOUND)
