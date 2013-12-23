 /* Check if the compiler thinks if we are targeting the wrong operating system. */
#ifndef NEXT_DIVEL
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
/* Headers for description tables */
//#include "NextKernel_GDT.h"
/* Headers for all system functions */
//#include "NextDivel.h"
/* Headers for MultiBoot */
#include <ND_Multiboot.hpp>
/* Headers for NextFS */
//#include "NextFS.h"
//#include "ND_Initrd.h"
//extern uint32_t placement_address;
//extern fs_node_t* fs_root;
#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif
int NextKernel_Main(struct multiboot *mboot_ptr)
{
	/*NextKernel_GDT_Init();
	ND_Versions_Startup();*/
	/*asm volatile ("int $0x3");
	asm volatile ("int $0x4");
	
	asm volatile ("sti");*/
	//ND_Timer_Init(50); //50 mhz
	/*uint32_t initrd_location = *((uint32_t*)mboot_ptr->mods_addr);
	uint32_t initrd_end = *(uint32_t*)(mboot_ptr->mods_addr+4);*/
	// Don't trample our module with placement accesses, please!
	/*placement_address = initrd_end;

	fs_root = initialise_initrd(initrd_location);*/
	
	//Testing filesystem
	/*int i = 0;
	struct dirent *node = 0;
	while ( (node = readdir_fs(fs_root, i)) != 0)
	{
	  ND_Screen_WriteString("Found file ");
	  ND_Screen_WriteString(node->name);
	  fs_node_t *fsnode = finddir_fs(fs_root, node->name);

	  if ((fsnode->flags&0x7) == FS_DIRECTORY)
	   ND_Screen_WriteString("\n\t(directory)\n");
	  else
	  {
	    ND_Screen_WriteString("\n\t contents: \"");
	    char buf[256];
	    uint32_t sz = read_fs(fsnode, 0, 256, buf);
	    int j;
	    ND_Screen_WriteString(buf);

	    ND_Screen_WriteString("\"\n");
	  }
	  i++;
	} */

	return 0;
}
